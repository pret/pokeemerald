#include "global.h"
#include "malloc.h"
#include "bg.h"
#include "decompress.h"
#include "dma3.h"
#include "dynamic_placeholder_text_util.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "link.h"
#include "link_rfu.h"
#include "load_save.h"
#include "main.h"
#include "menu.h"
#include "overworld.h"
#include "palette.h"
#include "save.h"
#include "scanline_effect.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text.h"
#include "text_window.h"
#include "union_room_chat.h"
#include "window.h"
#include "constants/rgb.h"
#include "constants/songs.h"

enum
{
    UNION_ROOM_KB_PAGE_UPPER,
    UNION_ROOM_KB_PAGE_LOWER,
    UNION_ROOM_KB_PAGE_EMOJI,
    UNION_ROOM_KB_PAGE_REGISTER,
    UNION_ROOM_KB_PAGE_COUNT,
};

#define MAX_MESSAGE_LENGTH 15

enum {
    CHAT_MESSAGE_NONE,
    CHAT_MESSAGE_CHAT,
    CHAT_MESSAGE_JOIN,
    CHAT_MESSAGE_LEAVE,
    CHAT_MESSAGE_DROP,
    CHAT_MESSAGE_DISBAND,
};

enum {
    STDMESSAGE_QUIT_CHATTING,
    STDMESSAGE_REGISTER_WHERE,
    STDMESSAGE_REGISTER_HERE,
    STDMESSAGE_INPUT_TEXT,
    STDMESSAGE_EXITING_CHAT,
    STDMESSAGE_LEADER_LEFT,
    STDMESSAGE_ASK_SAVE,
    STDMESSAGE_ASK_OVERWRITE,
    STDMESSAGE_SAVING_NO_OFF,
    STDMESSAGE_SAVED_THE_GAME,
    STDMESSAGE_WARN_LEADER_LEAVE,
};

enum {
    CHAT_FUNC_JOIN,
    CHAT_FUNC_HANDLE_INPUT,
    CHAT_FUNC_SWITCH,
    CHAT_FUNC_ASK_QUIT,
    CHAT_FUNC_SEND,
    CHAT_FUNC_REGISTER,
    CHAT_FUNC_EXIT,
    CHAT_FUNC_DROP,
    CHAT_FUNC_DISBANDED,
    CHAT_FUNC_SAVE_AND_EXIT,
};

enum {
    CHATDISPLAY_FUNC_LOAD_GFX,
    CHATDISPLAY_FUNC_MOVE_KB_CURSOR,
    CHATDISPLAY_FUNC_CURSOR_BLINK,
    CHATDISPLAY_FUNC_SHOW_KB_SWAP_MENU,
    CHATDISPLAY_FUNC_HIDE_KB_SWAP_MENU,
    CHATDISPLAY_FUNC_SWITCH_PAGES,
    CHATDISPLAY_FUNC_ASK_QUIT_CHATTING,
    CHATDISPLAY_FUNC_DESTROY_YESNO,
    CHATDISPLAY_FUNC_UPDATE_MSG,
    CHATDISPLAY_FUNC_ASK_REGISTER_TEXT,
    CHATDISPLAY_FUNC_CANCEL_REGISTER,
    CHATDISPLAY_FUNC_RETURN_TO_KB,
    CHATDISPLAY_FUNC_SCROLL_CHAT,
    CHATDISPLAY_FUNC_PRINT_INPUT_TEXT,
    CHATDISPLAY_FUNC_ASK_SAVE,
    CHATDISPLAY_FUNC_ASK_OVERWRITE_SAVE,
    CHATDISPLAY_FUNC_PRINT_SAVING,
    CHATDISPLAY_FUNC_PRINT_SAVED_GAME,
    CHATDISPLAY_FUNC_PRINT_EXITING_CHAT,
    CHATDISPLAY_FUNC_PRINT_LEADER_LEFT,
    CHATDISPLAY_FUNC_ASK_CONFIRM_LEADER_LEAVE,
};

enum {
    CHAT_EXIT_NONE,
    CHAT_EXIT_ONLY_LEADER,
    CHAT_EXIT_DROPPED,
    CHAT_EXIT_DISBANDED,
};

struct UnionRoomChat
{
    u32 filler1;
    u16 funcId;
    u16 funcState;
    u16 filler2;
    u16 exitDelayTimer;
    u8 filler3;
    u8 linkPlayerCount;
    u8 handleInputTask;
    u8 receiveMessagesTask;
    u8 currentPage;
    u8 currentCol;
    u8 currentRow;
    u8 multiplayerId;
    u8 lastBufferCursorPos;
    u8 bufferCursorPos;
    u8 receivedPlayerIndex;
    u8 exitType;
    bool8 changedRegisteredTexts;
    u8 afterSaveTimer;
    u8 messageEntryBuffer[2 * MAX_MESSAGE_LENGTH + 1];
    u8 receivedMessage[64];
    u8 hostName[64];
    u8 registeredTexts[UNION_ROOM_KB_ROW_COUNT][21];
    u8 filler4[5];
    u8 sendMessageBuffer[40];
    u16 tryQuitAgainTimer;
};

struct UnionRoomChatDisplay_Subtask
{
    bool32 (* callback)(u8 *);
    bool8 active;
    u8 state;
};

struct UnionRoomChatDisplay
{
    struct UnionRoomChatDisplay_Subtask subtasks[3];
    u16 yesNoMenuWindowId;
    u16 currLine;
    u16 scrollCount;
    u16 messageWindowId;
    s16 bg1hofs;
    u8 expandedPlaceholdersBuffer[0x106];
    u8 bg0Buffer[BG_SCREEN_SIZE];
    u8 bg1Buffer[BG_SCREEN_SIZE];
    u8 bg3Buffer[BG_SCREEN_SIZE];
    u8 bg2Buffer[BG_SCREEN_SIZE];
    u8 unk2128[0x20];
    u8 unk2148[0x20];
};

struct UnionRoomChatSprites
{
    struct Sprite *keyboardCursor;
    struct Sprite *textEntryArrow;
    struct Sprite *textEntryCursor;
    struct Sprite *rButtonIcon;
    struct Sprite *rButtonLabel;
    u16 cursorBlinkTimer;
};

struct SubtaskInfo
{
    u16 idx;
    bool32 (* callback)(u8 *);
};

struct MessageWindowInfo
{
    const u8 *text;
    u8 boxType;
    u8 x;
    u8 y;
    u8 letterSpacing;
    u8 lineSpacing;
    bool8 hasPlaceholders;
    bool8 useWiderBox;
};

static void InitUnionRoomChat(struct UnionRoomChat *);
static void CB2_LoadInterface(void);
static void VBlankCB_UnionRoomChatMain(void);
static void CB2_UnionRoomChatMain(void);
static void Task_HandlePlayerInput(u8 taskId);
static void Chat_Join(void);
static void Chat_HandleInput(void);
static void Chat_Switch(void);
static void Chat_AskQuitChatting(void);
static void Chat_Exit(void);
static void Chat_Drop(void);
static void Chat_Disbanded(void);
static void Chat_SendMessage(void);
static void Chat_Register(void);
static void Chat_SaveAndExit(void);
static void SetChatFunction(u16);
static bool32 HandleDPadInput(void);
static void AppendTextToMessage(void);
static void DeleteLastMessageCharacter(void);
static void SwitchCaseOfLastMessageCharacter(void);
static bool32 ChatMessageIsNotEmpty(void);
static void RegisterTextAtRow(void);
static void ResetMessageEntryBuffer(void);
static void SaveRegisteredTexts(void);
static u8 *GetEndOfMessagePtr(void);
static u8 *GetLastCharOfMessagePtr(void);
static void PrepareSendBuffer_Null(u8 *);
static void PrepareSendBuffer_Join(u8 *);
static void PrepareSendBuffer_Chat(u8 *);
static void PrepareSendBuffer_Leave(u8 *);
static void PrepareSendBuffer_Drop(u8 *);
static void PrepareSendBuffer_Disband(u8 *);
static u8 *GetLimitedMessageStartPtr(void);
static void Task_ReceiveChatMessage(u8 taskId);
static bool8 TryAllocDisplay(void);
static bool32 IsDisplaySubtask0Active(void);
static void FreeDisplay(void);
static void RunDisplaySubtasks(void);
static void StartDisplaySubtask(u16, u8);
static bool8 IsDisplaySubtaskActive(u8);
static s8 ProcessMenuInput(void);
static bool32 TryAllocSprites(void);
static void InitScanlineEffect(void);
static void InitDisplay(struct UnionRoomChatDisplay *);
static void ResetDisplaySubtasks(void);
static void FreeSprites(void);
static void ResetGpuBgState(void);
static void SetBgTilemapBuffers(void);
static void ClearBg0(void);
static void LoadChatWindowBorderGfx(void);
static void LoadChatWindowGfx(void);
static void sub_8020680(void);
static void LoadChatMessagesWindow(void);
static void LoadKeyboardWindow(void);
static void LoadKeyboardSwapWindow(void);
static void LoadTextEntryWindow(void);
static void CreateKeyboardCursorSprite(void);
static void CreateTextEntrySprites(void);
static void CreateRButtonSprites(void);
static void ShowKeyboardSwapMenu(void);
static void HideKeyboardSwapMenu(void);
static void SetKeyboardCursorInvisibility(bool32);
static bool32 sub_8020320(void);
static void PrintCurrentKeyboardPage(void);
static bool32 sub_8020368(void);
static void MoveKeyboardCursor(void);
static void UpdateRButtonLabel(void);
static void AddStdMessageWindow(int, u16);
static void AddYesNoMenuAt(u8, u8, u8);
static void HideStdMessageWindow(void);
static void HideYesNoMenuWindow(void);
static void DestroyStdMessageWindow(void);
static void DestroyYesNoMenuWindow(void);
static void FillTextEntryWindow(u16, u16, u8);
static void DrawTextEntryMessage(u16, u8 *, u8, u8, u8);
static void SetRegisteredTextPalette(bool32);
static void PrintChatMessage(u16, u8 *, u8);
static void StartKeyboardCursorAnim(void);
static bool32 TryKeyboardCursorReopen(void);
static void sub_80207C0(s16);
static void sub_8020818(s16);
static bool32 Display_Dummy(u8 *);
static bool32 Display_LoadGfx(u8 *state);
static bool32 Display_ShowKeyboardSwapMenu(u8 *state);
static bool32 Display_HideKeyboardSwapMenu(u8 *state);
static bool32 Display_SwitchPages(u8 *state);
static bool32 Display_MoveKeyboardCursor(u8 *state);
static bool32 Display_AskQuitChatting(u8 *state);
static bool32 Display_DestroyYesNoDialog(u8 *state);
static bool32 Display_UpdateMessageBuffer(u8 *state);
static bool32 Display_AskRegisterText(u8 *state);
static bool32 Display_CancelRegister(u8 *state);
static bool32 Display_ReturnToKeyboard(u8 *state);
static bool32 Display_ScrollChat(u8 *state);
static bool32 Display_AnimateKeyboardCursor(u8 *state);
static bool32 Display_PrintInputText(u8 *state);
static bool32 Display_PrintExitingChat(u8 *state);
static bool32 Display_PrintLeaderLeft(u8 *state);
static bool32 Display_AskSave(u8 *state);
static bool32 Display_AskOverwriteSave(u8 *state);
static bool32 Display_PrintSavingDontTurnOff(u8 *state);
static bool32 Display_PrintSavedTheGame(u8 *state);
static bool32 Display_AskConfirmLeaderLeave(u8 *state);
static void SpriteCB_TextEntryCursor(struct Sprite *sprite);
static void SpriteCB_TextEntryArrow(struct Sprite *sprite);

static EWRAM_DATA struct UnionRoomChat *sChat = NULL;
static EWRAM_DATA struct UnionRoomChatDisplay *sDisplay = NULL;
static EWRAM_DATA struct UnionRoomChatSprites *sSprites = NULL;

static void (*const sChatMainFunctions[])(void) = {
    [CHAT_FUNC_JOIN]          = Chat_Join,
    [CHAT_FUNC_HANDLE_INPUT]  = Chat_HandleInput,
    [CHAT_FUNC_SWITCH]        = Chat_Switch,
    [CHAT_FUNC_ASK_QUIT]      = Chat_AskQuitChatting,
    [CHAT_FUNC_SEND]          = Chat_SendMessage,
    [CHAT_FUNC_REGISTER]      = Chat_Register,
    [CHAT_FUNC_EXIT]          = Chat_Exit,
    [CHAT_FUNC_DROP]          = Chat_Drop,
    [CHAT_FUNC_DISBANDED]     = Chat_Disbanded,
    [CHAT_FUNC_SAVE_AND_EXIT] = Chat_SaveAndExit
};

static const u8 sKeyboardPageMaxRow[UNION_ROOM_KB_PAGE_COUNT] = 
{
    [UNION_ROOM_KB_PAGE_UPPER]    = 9, 
    [UNION_ROOM_KB_PAGE_LOWER]    = 9, 
    [UNION_ROOM_KB_PAGE_EMOJI]    = 9, 
    [UNION_ROOM_KB_PAGE_REGISTER] = 9
};

static const u8 sCaseToggleTable[256] = {
    [CHAR_A] = CHAR_a,
    [CHAR_B] = CHAR_b,
    [CHAR_C] = CHAR_c,
    [CHAR_D] = CHAR_d,
    [CHAR_E] = CHAR_e,
    [CHAR_F] = CHAR_f,
    [CHAR_G] = CHAR_g,
    [CHAR_H] = CHAR_h,
    [CHAR_I] = CHAR_i,
    [CHAR_J] = CHAR_j,
    [CHAR_K] = CHAR_k,
    [CHAR_L] = CHAR_l,
    [CHAR_M] = CHAR_m,
    [CHAR_N] = CHAR_n,
    [CHAR_O] = CHAR_o,
    [CHAR_P] = CHAR_p,
    [CHAR_Q] = CHAR_q,
    [CHAR_R] = CHAR_r,
    [CHAR_S] = CHAR_s,
    [CHAR_T] = CHAR_t,
    [CHAR_U] = CHAR_u,
    [CHAR_V] = CHAR_v,
    [CHAR_W] = CHAR_w,
    [CHAR_X] = CHAR_x,
    [CHAR_Y] = CHAR_y,
    [CHAR_Z] = CHAR_z,
    [CHAR_a] = CHAR_A,
    [CHAR_b] = CHAR_B,
    [CHAR_c] = CHAR_C,
    [CHAR_d] = CHAR_D,
    [CHAR_e] = CHAR_E,
    [CHAR_f] = CHAR_F,
    [CHAR_g] = CHAR_G,
    [CHAR_h] = CHAR_H,
    [CHAR_i] = CHAR_I,
    [CHAR_j] = CHAR_J,
    [CHAR_k] = CHAR_K,
    [CHAR_l] = CHAR_L,
    [CHAR_m] = CHAR_M,
    [CHAR_n] = CHAR_N,
    [CHAR_o] = CHAR_O,
    [CHAR_p] = CHAR_P,
    [CHAR_q] = CHAR_Q,
    [CHAR_r] = CHAR_R,
    [CHAR_s] = CHAR_S,
    [CHAR_t] = CHAR_T,
    [CHAR_u] = CHAR_U,
    [CHAR_v] = CHAR_V,
    [CHAR_w] = CHAR_W,
    [CHAR_x] = CHAR_X,
    [CHAR_y] = CHAR_Y,
    [CHAR_z] = CHAR_Z,
    [CHAR_A_GRAVE] = CHAR_a_GRAVE,
    [CHAR_A_ACUTE] = CHAR_a_ACUTE,
    [CHAR_A_CIRCUMFLEX] = CHAR_a_CIRCUMFLEX,
    [CHAR_A_DIAERESIS] = CHAR_a_DIAERESIS,
    [CHAR_C_CEDILLA] = CHAR_c_CEDILLA,
    [CHAR_E_GRAVE] = CHAR_e_GRAVE,
    [CHAR_E_ACUTE] = CHAR_e_ACUTE,
    [CHAR_E_CIRCUMFLEX] = CHAR_e_CIRCUMFLEX,
    [CHAR_E_DIAERESIS] = CHAR_e_DIAERESIS,
    [CHAR_I_GRAVE] = CHAR_i_GRAVE,
    [CHAR_I_ACUTE] = CHAR_i_ACUTE,
    [CHAR_I_CIRCUMFLEX] = CHAR_i_CIRCUMFLEX,
    [CHAR_I_DIAERESIS] = CHAR_i_DIAERESIS,
    [CHAR_O_GRAVE] = CHAR_o_GRAVE,
    [CHAR_O_ACUTE] = CHAR_o_ACUTE,
    [CHAR_O_CIRCUMFLEX] = CHAR_o_CIRCUMFLEX,
    [CHAR_O_DIAERESIS] = CHAR_o_DIAERESIS,
    [CHAR_OE] = CHAR_oe,
    [CHAR_U_GRAVE] = CHAR_u_GRAVE,
    [CHAR_U_ACUTE] = CHAR_u_ACUTE,
    [CHAR_U_CIRCUMFLEX] = CHAR_u_CIRCUMFLEX,
    [CHAR_U_DIAERESIS] = CHAR_u_DIAERESIS,
    [CHAR_N_TILDE] = CHAR_n_TILDE,
    [CHAR_ESZETT] = CHAR_ESZETT,
    [CHAR_a_GRAVE] = CHAR_A_GRAVE,
    [CHAR_a_ACUTE] = CHAR_A_ACUTE,
    [CHAR_a_CIRCUMFLEX] = CHAR_A_CIRCUMFLEX,
    [CHAR_a_DIAERESIS] = CHAR_A_DIAERESIS,
    [CHAR_c_CEDILLA] = CHAR_C_CEDILLA,
    [CHAR_e_GRAVE] = CHAR_E_GRAVE,
    [CHAR_e_ACUTE] = CHAR_E_ACUTE,
    [CHAR_e_CIRCUMFLEX] = CHAR_E_CIRCUMFLEX,
    [CHAR_e_DIAERESIS] = CHAR_E_DIAERESIS,
    [CHAR_i_GRAVE] = CHAR_I_GRAVE,
    [CHAR_i_ACUTE] = CHAR_I_ACUTE,
    [CHAR_i_CIRCUMFLEX] = CHAR_I_CIRCUMFLEX,
    [CHAR_i_DIAERESIS] = CHAR_I_DIAERESIS,
    [CHAR_o_GRAVE] = CHAR_O_GRAVE,
    [CHAR_o_ACUTE] = CHAR_O_ACUTE,
    [CHAR_o_CIRCUMFLEX] = CHAR_O_CIRCUMFLEX,
    [CHAR_o_DIAERESIS] = CHAR_O_DIAERESIS,
    [CHAR_oe] = CHAR_OE,
    [CHAR_u_GRAVE] = CHAR_U_GRAVE,
    [CHAR_u_ACUTE] = CHAR_U_ACUTE,
    [CHAR_u_CIRCUMFLEX] = CHAR_U_CIRCUMFLEX,
    [CHAR_u_DIAERESIS] = CHAR_U_DIAERESIS,
    [CHAR_n_TILDE] = CHAR_N_TILDE,
    [CHAR_0] = CHAR_0,
    [CHAR_1] = CHAR_1,
    [CHAR_2] = CHAR_2,
    [CHAR_3] = CHAR_3,
    [CHAR_4] = CHAR_4,
    [CHAR_5] = CHAR_5,
    [CHAR_6] = CHAR_6,
    [CHAR_7] = CHAR_7,
    [CHAR_8] = CHAR_8,
    [CHAR_9] = CHAR_9,
    [CHAR_PK] = CHAR_PK,
    [CHAR_MN] = CHAR_MN,
    [CHAR_PO] = CHAR_PO,
    [CHAR_KE] = CHAR_KE,
    [CHAR_SUPER_E]  = CHAR_SUPER_E,
    [CHAR_SUPER_ER] = CHAR_SUPER_ER,
    [CHAR_SUPER_RE] = CHAR_SUPER_RE,
    [CHAR_PERIOD] = CHAR_PERIOD,
    [CHAR_COMMA] = CHAR_COMMA,
    [CHAR_COLON] = CHAR_COLON,
    [CHAR_SEMICOLON] = CHAR_SEMICOLON,
    [CHAR_EXCL_MARK] = CHAR_EXCL_MARK,
    [CHAR_QUESTION_MARK] = CHAR_QUESTION_MARK,
    [CHAR_HYPHEN] = CHAR_HYPHEN,
    [CHAR_SLASH] = CHAR_SLASH,
    [CHAR_ELLIPSIS] = CHAR_ELLIPSIS,
    [CHAR_LEFT_PAREN] = CHAR_LEFT_PAREN,
    [CHAR_RIGHT_PAREN] = CHAR_RIGHT_PAREN,
    [CHAR_AMPERSAND] = CHAR_AMPERSAND,
    [CHAR_DBL_QUOT_LEFT] = CHAR_DBL_QUOT_LEFT,
    [CHAR_DBL_QUOT_RIGHT] = CHAR_DBL_QUOT_RIGHT,
    [CHAR_SGL_QUOT_LEFT] = CHAR_SGL_QUOT_LEFT,
    [CHAR_SGL_QUOT_RIGHT] = CHAR_SGL_QUOT_RIGHT,
    [CHAR_MASCULINE_ORDINAL] = CHAR_MASCULINE_ORDINAL,
    [CHAR_FEMININE_ORDINAL] = CHAR_FEMININE_ORDINAL,
    [CHAR_BULLET] = CHAR_BULLET,
    [CHAR_EQUALS] = CHAR_EQUALS,
    [CHAR_MULT_SIGN] = CHAR_MULT_SIGN,
    [CHAR_PERCENT] = CHAR_PERCENT,
    [CHAR_LESS_THAN] = CHAR_LESS_THAN,
    [CHAR_GREATER_THAN] = CHAR_GREATER_THAN,
    [CHAR_MALE] = CHAR_MALE,
    [CHAR_FEMALE] = CHAR_FEMALE,
    [CHAR_CURRENCY] = CHAR_CURRENCY,
    [CHAR_BLACK_TRIANGLE] = CHAR_BLACK_TRIANGLE,
};

// Excludes UNION_ROOM_KB_PAGE_REGISTER, the text for which is chosen by the player
static const u8 *const sUnionRoomKeyboardText[UNION_ROOM_KB_PAGE_COUNT - 1][UNION_ROOM_KB_ROW_COUNT] = 
{
    [UNION_ROOM_KB_PAGE_UPPER] = 
    {
        gText_UnionRoomChatKeyboard_ABCDE, 
        gText_UnionRoomChatKeyboard_FGHIJ, 
        gText_UnionRoomChatKeyboard_KLMNO, 
        gText_UnionRoomChatKeyboard_PQRST, 
        gText_UnionRoomChatKeyboard_UVWXY, 
        gText_UnionRoomChatKeyboard_Z, 
        gText_UnionRoomChatKeyboard_01234Upper, 
        gText_UnionRoomChatKeyboard_56789Upper, 
        gText_UnionRoomChatKeyboard_PunctuationUpper, 
        gText_UnionRoomChatKeyboard_SymbolsUpper
    },
    [UNION_ROOM_KB_PAGE_LOWER] = 
    {
        gText_UnionRoomChatKeyboard_abcde, 
        gText_UnionRoomChatKeyboard_fghij, 
        gText_UnionRoomChatKeyboard_klmno, 
        gText_UnionRoomChatKeyboard_pqrst, 
        gText_UnionRoomChatKeyboard_uvwxy, 
        gText_UnionRoomChatKeyboard_z, 
        gText_UnionRoomChatKeyboard_01234Lower, 
        gText_UnionRoomChatKeyboard_56789Lower, 
        gText_UnionRoomChatKeyboard_PunctuationLower, 
        gText_UnionRoomChatKeyboard_SymbolsLower
    },
    [UNION_ROOM_KB_PAGE_EMOJI] = 
    {
        gText_UnionRoomChatKeyboard_Emoji1, 
        gText_UnionRoomChatKeyboard_Emoji2, 
        gText_UnionRoomChatKeyboard_Emoji3, 
        gText_UnionRoomChatKeyboard_Emoji4, 
        gText_UnionRoomChatKeyboard_Emoji5, 
        gText_UnionRoomChatKeyboard_Emoji6, 
        gText_UnionRoomChatKeyboard_Emoji7, 
        gText_UnionRoomChatKeyboard_Emoji8, 
        gText_UnionRoomChatKeyboard_Emoji9, 
        gText_UnionRoomChatKeyboard_Emoji10
    }
};

static const u16 sUnk_Palette1[] = INCBIN_U16("graphics/union_room_chat/unk_palette1.gbapal");
static const u16 sUnk_Palette2[] = INCBIN_U16("graphics/union_room_chat/unk_palette2.gbapal");

static const struct BgTemplate sBgTemplates[] = {
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 7,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    }, {
        .bg = 1,
        .charBaseIndex = 3,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0
    }, {
        .bg = 2,
        .charBaseIndex = 2,
        .mapBaseIndex = 23,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0
    }, {
        .bg = 3,
        .charBaseIndex = 1,
        .mapBaseIndex = 15,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 3,
        .baseTile = 1
    }
};

static const struct WindowTemplate sWinTemplates[] = {
    {
        .bg = 0x03,
        .tilemapLeft = 0x08,
        .tilemapTop = 0x01,
        .width = 0x15,
        .height = 0x13,
        .paletteNum = 0x0f,
        .baseBlock = 0x0001,
    }, {
        .bg = 0x01,
        .tilemapLeft = 0x09,
        .tilemapTop = 0x12,
        .width = 0x0f,
        .height = 0x02,
        .paletteNum = 0x0c,
        .baseBlock = 0x007a,
    }, {
        .bg = 0x01,
        .tilemapLeft = 0x00,
        .tilemapTop = 0x02,
        .width = 0x06,
        .height = 0x0f,
        .paletteNum = 0x07,
        .baseBlock = 0x0020,
    }, {
        .bg = 0x00,
        .tilemapLeft = 0x01,
        .tilemapTop = 0x02,
        .width = 0x07,
        .height = 0x09,
        .paletteNum = 0x0e,
        .baseBlock = 0x0013,
    }, DUMMY_WIN_TEMPLATE
};

static const struct SubtaskInfo sDisplaySubtasks[] = {
    {CHATDISPLAY_FUNC_LOAD_GFX,                 Display_LoadGfx},
    {CHATDISPLAY_FUNC_SHOW_KB_SWAP_MENU,        Display_ShowKeyboardSwapMenu},
    {CHATDISPLAY_FUNC_HIDE_KB_SWAP_MENU,        Display_HideKeyboardSwapMenu},
    {CHATDISPLAY_FUNC_SWITCH_PAGES,             Display_SwitchPages},
    {CHATDISPLAY_FUNC_MOVE_KB_CURSOR,           Display_MoveKeyboardCursor},
    {CHATDISPLAY_FUNC_ASK_QUIT_CHATTING,        Display_AskQuitChatting},
    {CHATDISPLAY_FUNC_DESTROY_YESNO,            Display_DestroyYesNoDialog},
    {CHATDISPLAY_FUNC_UPDATE_MSG,               Display_UpdateMessageBuffer},
    {CHATDISPLAY_FUNC_ASK_REGISTER_TEXT,        Display_AskRegisterText},
    {CHATDISPLAY_FUNC_CANCEL_REGISTER,          Display_CancelRegister},
    {CHATDISPLAY_FUNC_RETURN_TO_KB,             Display_ReturnToKeyboard},
    {CHATDISPLAY_FUNC_SCROLL_CHAT,              Display_ScrollChat},
    {CHATDISPLAY_FUNC_CURSOR_BLINK,             Display_AnimateKeyboardCursor},
    {CHATDISPLAY_FUNC_PRINT_INPUT_TEXT,         Display_PrintInputText},
    {CHATDISPLAY_FUNC_PRINT_EXITING_CHAT,       Display_PrintExitingChat},
    {CHATDISPLAY_FUNC_PRINT_LEADER_LEFT,        Display_PrintLeaderLeft},
    {CHATDISPLAY_FUNC_ASK_SAVE,                 Display_AskSave},
    {CHATDISPLAY_FUNC_ASK_OVERWRITE_SAVE,       Display_AskOverwriteSave},
    {CHATDISPLAY_FUNC_PRINT_SAVING,             Display_PrintSavingDontTurnOff},
    {CHATDISPLAY_FUNC_PRINT_SAVED_GAME,         Display_PrintSavedTheGame},
    {CHATDISPLAY_FUNC_ASK_CONFIRM_LEADER_LEAVE, Display_AskConfirmLeaderLeave}
};

static const struct MessageWindowInfo sDisplayStdMessages[] = {
    [STDMESSAGE_QUIT_CHATTING] = {
        .text = gText_QuitChatting, 
        .boxType = 1, 
        .x = 0, 
        .y = 1, 
        .letterSpacing = 0, 
        .lineSpacing = 0, 
        .hasPlaceholders = FALSE, 
        .useWiderBox = FALSE
    },
    [STDMESSAGE_REGISTER_WHERE] = {
        .text = gText_RegisterTextWhere, 
        .boxType = 1, 
        .x = 0, 
        .y = 1, 
        .letterSpacing = 0, 
        .lineSpacing = 0, 
        .hasPlaceholders = FALSE, 
        .useWiderBox = FALSE
    },
    [STDMESSAGE_REGISTER_HERE] = {
        .text = gText_RegisterTextHere, 
        .boxType = 1, 
        .x = 0, 
        .y = 1, 
        .letterSpacing = 0, 
        .lineSpacing = 0, 
        .hasPlaceholders = FALSE, 
        .useWiderBox = FALSE
    },
    [STDMESSAGE_INPUT_TEXT] = {
        .text = gText_InputText, 
        .boxType = 1, 
        .x = 0, 
        .y = 1, 
        .letterSpacing = 0, 
        .lineSpacing = 0, 
        .hasPlaceholders = FALSE, 
        .useWiderBox = FALSE
    },
    [STDMESSAGE_EXITING_CHAT] = {
        .text = gText_ExitingChat, 
        .boxType = 2, 
        .x = 0, 
        .y = 1, 
        .letterSpacing = 0, 
        .lineSpacing = 0, 
        .hasPlaceholders = FALSE, 
        .useWiderBox = FALSE
    },
    [STDMESSAGE_LEADER_LEFT] = {
        .text = gText_LeaderLeftEndingChat, 
        .boxType = 2, 
        .x = 0, 
        .y = 1, 
        .letterSpacing = 0, 
        .lineSpacing = 0, 
        .hasPlaceholders = TRUE, 
        .useWiderBox = FALSE
    },
    [STDMESSAGE_ASK_SAVE] = {
        .text = gText_RegisteredTextChangedOKToSave, 
        .boxType = 2, 
        .x = 0, 
        .y = 1, 
        .letterSpacing = 0, 
        .lineSpacing = 0, 
        .hasPlaceholders = FALSE, 
        .useWiderBox = TRUE
    },
    [STDMESSAGE_ASK_OVERWRITE] = {
        .text = gText_AlreadySavedFile_Chat, 
        .boxType = 2, 
        .x = 0, 
        .y = 1, 
        .letterSpacing = 0, 
        .lineSpacing = 0, 
        .hasPlaceholders = FALSE, 
        .useWiderBox = TRUE
    },
    [STDMESSAGE_SAVING_NO_OFF] = {
        .text = gText_SavingDontTurnOff_Chat, 
        .boxType = 2, 
        .x = 0, 
        .y = 1, 
        .letterSpacing = 0, 
        .lineSpacing = 0, 
        .hasPlaceholders = FALSE, 
        .useWiderBox = TRUE
    },
    [STDMESSAGE_SAVED_THE_GAME] = {
        .text = gText_PlayerSavedGame_Chat, 
        .boxType = 2, 
        .x = 0, 
        .y = 1, 
        .letterSpacing = 0, 
        .lineSpacing = 0, 
        .hasPlaceholders = TRUE, 
        .useWiderBox = TRUE
    },
    [STDMESSAGE_WARN_LEADER_LEAVE] = {
        .text = gText_IfLeaderLeavesChatEnds, 
        .boxType = 2, 
        .x = 0, 
        .y = 1, 
        .letterSpacing = 0, 
        .lineSpacing = 0, 
        .hasPlaceholders = FALSE, 
        .useWiderBox = TRUE
    }
};

static const u8 sText_Ellipsis[] = _("…");

static const struct MenuAction sKeyboardPageTitleTexts[UNION_ROOM_KB_PAGE_COUNT + 1] = {
    [UNION_ROOM_KB_PAGE_UPPER]    = {gText_Upper, NULL},
    [UNION_ROOM_KB_PAGE_LOWER]    = {gText_Lower, NULL},
    [UNION_ROOM_KB_PAGE_EMOJI]    = {gText_Symbols, NULL},
    [UNION_ROOM_KB_PAGE_REGISTER] = {gText_Register2, NULL},
    [UNION_ROOM_KB_PAGE_COUNT]    = {gText_Exit2, NULL},
};

static const u16 sUnionRoomChatInterfacePal[] = INCBIN_U16("graphics/union_room_chat/interface.gbapal");
static const u32 sKeyboardCursorTiles[] = INCBIN_U32("graphics/union_room_chat/keyboard_cursor.4bpp.lz");
static const u32 sTextEntryCursorTiles[] = INCBIN_U32("graphics/union_room_chat/text_entry_cursor.4bpp.lz");
static const u32 sTextEntryArrowTiles[] = INCBIN_U32("graphics/union_room_chat/text_entry_arrow.4bpp.lz");
static const u32 sRButtonGfxTiles[] = INCBIN_U32("graphics/union_room_chat/r_button.4bpp.lz");

static const struct CompressedSpriteSheet sSpriteSheets[] = {
    {sKeyboardCursorTiles,         0x1000, 0},
    {sTextEntryArrowTiles,         0x0040, 1},
    {sTextEntryCursorTiles,        0x0040, 2},
    {sRButtonGfxTiles,             0x0080, 3},
    {gUnionRoomChat_RButtonLabels, 0x0400, 4}
};

static const struct SpritePalette sSpritePalette = {
    sUnionRoomChatInterfacePal, 0
};

static const struct OamData sOam_KeyboardCursor = {
    .shape = SPRITE_SHAPE(64x32),
    .size = SPRITE_SIZE(64x32),
    .priority = 1
};

static const union AnimCmd sAnim_KeyboardCursor_Open[] = {
    ANIMCMD_FRAME(0x00, 30),
    ANIMCMD_END
};

static const union AnimCmd sAnim_KeyboardCursor_Closed[] = {
    ANIMCMD_FRAME(0x20, 30),
    ANIMCMD_END
};

static const union AnimCmd sAnim_KeyboardCursorWide_Open[] = {
    ANIMCMD_FRAME(0x40, 30),
    ANIMCMD_END
};

static const union AnimCmd sAnim_KeyboardCursorWide_Closed[] = {
    ANIMCMD_FRAME(0x60, 30),
    ANIMCMD_END
};

static const union AnimCmd *const sAnims_KeyboardCursor[] = {
    sAnim_KeyboardCursor_Open,
    sAnim_KeyboardCursor_Closed,
    sAnim_KeyboardCursorWide_Open,
    sAnim_KeyboardCursorWide_Closed
};

static const struct SpriteTemplate sSpriteTemplate_KeyboardCursor = {
    .tileTag = 0x0000,
    .paletteTag = 0x0000,
    .oam = &sOam_KeyboardCursor,
    .anims = sAnims_KeyboardCursor,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct OamData sOam_TextEntrySprite = {
    .shape = SPRITE_SHAPE(8x16),
    .size = SPRITE_SIZE(8x16),
    .priority = 2
};

static const struct SpriteTemplate sSpriteTemplate_TextEntryCursor = {
    .tileTag = 0x0002,
    .paletteTag = 0x0000,
    .oam = &sOam_TextEntrySprite,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_TextEntryCursor
};

static const struct SpriteTemplate sSpriteTemplate_TextEntryArrow = {
    .tileTag = 0x0001,
    .paletteTag = 0x0000,
    .oam = &sOam_TextEntrySprite,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_TextEntryArrow
};

static const struct OamData sOam_RButtonIcon = {
    .shape = SPRITE_SHAPE(16x16),
    .size = SPRITE_SIZE(16x16),
    .priority = 2
};

static const struct OamData sOam_RButtonLabel = {
    .shape = SPRITE_SHAPE(32x16),
    .size = SPRITE_SIZE(32x16),
    .priority = 2
};

static const union AnimCmd sAnim_ToggleCaseIcon[] = {
    ANIMCMD_FRAME(0x00, 2),
    ANIMCMD_END
};

static const union AnimCmd sAnim_ToggleCaseIcon_Duplicate1[] = {
    ANIMCMD_FRAME(0x08, 2),
    ANIMCMD_END
};

static const union AnimCmd sAnim_ToggleCaseIcon_Duplicate2[] = {
    ANIMCMD_FRAME(0x10, 2),
    ANIMCMD_END
};

static const union AnimCmd sAnim_RegisterIcon[] = {
    ANIMCMD_FRAME(0x18, 2),
    ANIMCMD_END
};

static const union AnimCmd *const sAnims_RButtonLabels[] = {
    sAnim_ToggleCaseIcon,
    sAnim_ToggleCaseIcon_Duplicate1,
    sAnim_ToggleCaseIcon_Duplicate2,
    sAnim_RegisterIcon
};

static const struct SpriteTemplate sSpriteTemplate_RButtonIcon = {
    .tileTag = 0x0003,
    .paletteTag = 0x0000,
    .oam = &sOam_RButtonIcon,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static const struct SpriteTemplate sSpriteTemplate_RButtonLabels = {
    .tileTag = 0x0004,
    .paletteTag = 0x0000,
    .oam = &sOam_RButtonLabel,
    .anims = sAnims_RButtonLabels,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

void EnterUnionRoomChat(void)
{
    sChat = Alloc(sizeof(struct UnionRoomChat));
    InitUnionRoomChat(sChat);
    gKeyRepeatStartDelay = 20;
    SetVBlankCallback(NULL);
    SetMainCallback2(CB2_LoadInterface);
}

static void InitUnionRoomChat(struct UnionRoomChat *chat)
{
    int i;

    chat->funcId = 0;
    chat->funcState = 0;
    chat->currentPage = 0;
    chat->currentCol = 0;
    chat->currentRow = 0;
    chat->lastBufferCursorPos = 0;
    chat->bufferCursorPos = 0;
    chat->receivedPlayerIndex = 0;
    chat->messageEntryBuffer[0] = EOS;
    chat->linkPlayerCount = GetLinkPlayerCount();
    chat->multiplayerId = GetMultiplayerId();
    chat->exitType = 0;
    chat->changedRegisteredTexts = FALSE;
    PrepareSendBuffer_Null(chat->sendMessageBuffer);
    for (i = 0; i < UNION_ROOM_KB_ROW_COUNT; i++)
        StringCopy(chat->registeredTexts[i], gSaveBlock1Ptr->registeredTexts[i]);
}

static void FreeUnionRoomChat(void)
{
    DestroyTask(sChat->handleInputTask);
    DestroyTask(sChat->receiveMessagesTask);
    Free(sChat);
}

static void CB2_LoadInterface(void)
{
    switch (gMain.state)
    {
    case 0:
        ResetTasks();
        ResetSpriteData();
        FreeAllSpritePalettes();
        TryAllocDisplay();
        gMain.state++;
        break;
    case 1:
        RunDisplaySubtasks();
        if (!IsDisplaySubtask0Active())
        {
            BlendPalettes(PALETTES_ALL, 16, RGB_BLACK);
            BeginNormalPaletteFade(PALETTES_ALL, -1, 16, 0, RGB_BLACK);
            SetVBlankCallback(VBlankCB_UnionRoomChatMain);
            gMain.state++;
        }
        break;
    case 2:
        UpdatePaletteFade();
        if (!gPaletteFade.active)
        {
            SetMainCallback2(CB2_UnionRoomChatMain);
            sChat->handleInputTask = CreateTask(Task_HandlePlayerInput, 8);
            sChat->receiveMessagesTask = CreateTask(Task_ReceiveChatMessage, 7);
            LoadWirelessStatusIndicatorSpriteGfx();
            CreateWirelessStatusIndicatorSprite(232, 150);
        }
        break;
    }
}

static void VBlankCB_UnionRoomChatMain(void)
{
    TransferPlttBuffer();
    LoadOam();
    ProcessSpriteCopyRequests();
    ScanlineEffect_InitHBlankDmaTransfer();
}

static void CB2_UnionRoomChatMain(void)
{
    RunTasks();
    RunDisplaySubtasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void Task_HandlePlayerInput(u8 taskId)
{
    switch (sChat->exitType)
    {
    case CHAT_EXIT_ONLY_LEADER:
        SetChatFunction(CHAT_FUNC_EXIT);
        sChat->exitType = CHAT_EXIT_NONE;
        break;
    case CHAT_EXIT_DROPPED:
        SetChatFunction(CHAT_FUNC_DROP);
        sChat->exitType = CHAT_EXIT_NONE;
        break;
    case CHAT_EXIT_DISBANDED:
        SetChatFunction(CHAT_FUNC_DISBANDED);
        sChat->exitType = CHAT_EXIT_NONE;
        break;
    }

    sChatMainFunctions[sChat->funcId]();
}

static void Chat_Join(void)
{
    switch (sChat->funcState)
    {
    case 0:
        PrepareSendBuffer_Join(sChat->sendMessageBuffer);
        sChat->funcState++;
        // fall through
    case 1:
        if (IsLinkTaskFinished() && !sub_8011A9C())
        {
            if (SendBlock(0, sChat->sendMessageBuffer, sizeof(sChat->sendMessageBuffer)))
                sChat->funcState++;
        }
        break;
    case 2:
        if (IsLinkTaskFinished())
            SetChatFunction(CHAT_FUNC_HANDLE_INPUT);
        break;
    }
}

static void Chat_HandleInput(void)
{
    bool8 updateMsgActive, cursorBlinkActive;

    switch (sChat->funcState)
    {
    case 0:
        if (JOY_NEW(START_BUTTON))
        {
            if (sChat->bufferCursorPos)
                SetChatFunction(CHAT_FUNC_SEND);
        }
        else if (JOY_NEW(SELECT_BUTTON))
        {
            SetChatFunction(CHAT_FUNC_SWITCH);
        }
        else if (gMain.newAndRepeatedKeys & B_BUTTON)
        {
            if (sChat->bufferCursorPos)
            {
                DeleteLastMessageCharacter();
                StartDisplaySubtask(CHATDISPLAY_FUNC_UPDATE_MSG, 0);
                sChat->funcState = 1;
            }
            else
            {
                SetChatFunction(CHAT_FUNC_ASK_QUIT);
            }
        }
        else if (JOY_NEW(A_BUTTON))
        {
            AppendTextToMessage();
            StartDisplaySubtask(CHATDISPLAY_FUNC_UPDATE_MSG, 0);
            StartDisplaySubtask(CHATDISPLAY_FUNC_CURSOR_BLINK, 1);
            sChat->funcState = 1;
        }
        else if (JOY_NEW(R_BUTTON))
        {
            if (sChat->currentPage != UNION_ROOM_KB_PAGE_REGISTER)
            {
                SwitchCaseOfLastMessageCharacter();
                StartDisplaySubtask(CHATDISPLAY_FUNC_UPDATE_MSG, 0);
                sChat->funcState = 1;
            }
            else
            {
                SetChatFunction(5);
            }
        }
        else if (HandleDPadInput())
        {
            StartDisplaySubtask(CHATDISPLAY_FUNC_MOVE_KB_CURSOR, 0);
            sChat->funcState = 1;
        }
        break;
    case 1:
        updateMsgActive = IsDisplaySubtaskActive(0);
        cursorBlinkActive = IsDisplaySubtaskActive(1);
        if (!updateMsgActive && !cursorBlinkActive)
            sChat->funcState = 0;
        break;
    }
}

static void Chat_Switch(void)
{
    s16 input;
    bool32 shouldSwitchPages;

    switch (sChat->funcState)
    {
    case 0:
        StartDisplaySubtask(CHATDISPLAY_FUNC_SHOW_KB_SWAP_MENU, 0);
        sChat->funcState++;
        break;
    case 1:
        if (!IsDisplaySubtaskActive(0))
            sChat->funcState++;
        break;
    case 2:
        input = Menu_ProcessInput();
        switch (input)
        {
        default:
            StartDisplaySubtask(CHATDISPLAY_FUNC_HIDE_KB_SWAP_MENU, 0);
            shouldSwitchPages = TRUE;
            if (sChat->currentPage == input || input > UNION_ROOM_KB_PAGE_REGISTER)
                shouldSwitchPages = FALSE;
            break;
        case MENU_NOTHING_CHOSEN:
            if (JOY_NEW(SELECT_BUTTON))
            {
                PlaySE(SE_SELECT);
                Menu_MoveCursor(1);
            }
            return;
        case MENU_B_PRESSED:
            StartDisplaySubtask(CHATDISPLAY_FUNC_HIDE_KB_SWAP_MENU, 0);
            sChat->funcState = 3;
            return;
        }

        if (!shouldSwitchPages)
        {
            sChat->funcState = 3;
            return;
        }

        sChat->currentCol = 0;
        sChat->currentRow = 0;
        StartDisplaySubtask(CHATDISPLAY_FUNC_SWITCH_PAGES, 1);
        sChat->currentPage = input;
        sChat->funcState = 4;
        break;
    case 3:
        if (!IsDisplaySubtaskActive(0))
            SetChatFunction(CHAT_FUNC_HANDLE_INPUT);
        break;
    case 4:
        if (!IsDisplaySubtaskActive(0) && !IsDisplaySubtaskActive(1))
            SetChatFunction(CHAT_FUNC_HANDLE_INPUT);
        break;
    }
}

static void Chat_AskQuitChatting(void)
{
    s8 input;

    switch (sChat->funcState)
    {
    case 0:
        StartDisplaySubtask(CHATDISPLAY_FUNC_ASK_QUIT_CHATTING, 0);
        sChat->funcState = 1;
        break;
    case 1:
        if (!IsDisplaySubtaskActive(0))
            sChat->funcState = 2;
        break;
    case 2:
        input = ProcessMenuInput();
        switch (input)
        {
        case -1:
        case 1:
            StartDisplaySubtask(CHATDISPLAY_FUNC_DESTROY_YESNO, 0);
            sChat->funcState = 3;
            break;
        case 0:
            if (sChat->multiplayerId == 0)
            {
                PrepareSendBuffer_Disband(sChat->sendMessageBuffer);
                StartDisplaySubtask(CHATDISPLAY_FUNC_DESTROY_YESNO, 0);
                sChat->funcState = 9;
            }
            else
            {
                PrepareSendBuffer_Leave(sChat->sendMessageBuffer);
                sChat->funcState = 4;
            }
            break;
        }
        break;
    case 3:
        if (!IsDisplaySubtaskActive(0))
            SetChatFunction(CHAT_FUNC_HANDLE_INPUT);
        break;
    case 9:
        if (!IsDisplaySubtaskActive(0))
        {
            StartDisplaySubtask(CHATDISPLAY_FUNC_ASK_CONFIRM_LEADER_LEAVE, 0);
            sChat->funcState = 10;
        }
        break;
    case 10:
        if (!IsDisplaySubtaskActive(0))
            sChat->funcState = 8;
        break;
    case 8:
        input = ProcessMenuInput();
        switch (input)
        {
        case -1:
        case 1:
            StartDisplaySubtask(CHATDISPLAY_FUNC_DESTROY_YESNO, 0);
            sChat->funcState = 3;
            break;
        case 0:
            sub_80104B0();
            PrepareSendBuffer_Disband(sChat->sendMessageBuffer);
            sChat->funcState = 4;
            sChat->tryQuitAgainTimer = 0;
            break;
        }
        break;
    case 4:
        if (IsLinkTaskFinished() && !sub_8011A9C() && SendBlock(0, sChat->sendMessageBuffer, sizeof(sChat->sendMessageBuffer)))
        {
            if (!sChat->multiplayerId)
                sChat->funcState = 6;
            else
                sChat->funcState = 5;
        }

        if (!gReceivedRemoteLinkPlayers)
            SetChatFunction(CHAT_FUNC_SAVE_AND_EXIT);
        break;
    case 5:
        if (!gReceivedRemoteLinkPlayers)
        {
            SetChatFunction(CHAT_FUNC_SAVE_AND_EXIT);
        }
        else if (++sChat->tryQuitAgainTimer > 300)
        {
            sChat->tryQuitAgainTimer = 0;
            sChat->funcState = 4;
        }
        break;
    }
}

static void Chat_Exit(void)
{
    switch (sChat->funcState)
    {
    case 0:
        if (!FuncIsActiveTask(Task_ReceiveChatMessage))
        {
            StartDisplaySubtask(CHATDISPLAY_FUNC_DESTROY_YESNO, 0);
            sChat->funcState++;
        }
        break;
    case 1:
        if (!IsDisplaySubtaskActive(0))
        {
            StartDisplaySubtask(CHATDISPLAY_FUNC_PRINT_EXITING_CHAT, 0);
            sChat->funcState++;
        }
        break;
    case 2:
        if (!IsDisplaySubtaskActive(0))
        {
            PrepareSendBuffer_Drop(sChat->sendMessageBuffer);
            sChat->funcState++;
        }
        break;
    case 3:
        if (IsLinkTaskFinished() && !sub_8011A9C() && SendBlock(0, sChat->sendMessageBuffer, sizeof(sChat->sendMessageBuffer)))
            sChat->funcState++;
        break;
    case 4:
        if ((GetBlockReceivedStatus() & 1) && !sub_8011A9C())
            sChat->funcState++;
        break;
    case 5:
        if (IsLinkTaskFinished() && !sub_8011A9C())
        {
            SetCloseLinkCallback();
            sChat->exitDelayTimer = 0;
            sChat->funcState++;
        }
        break;
    case 6:
        if (sChat->exitDelayTimer < 150)
            sChat->exitDelayTimer++;

        if (!gReceivedRemoteLinkPlayers)
            sChat->funcState++;
        break;
    case 7:
        if (sChat->exitDelayTimer >= 150)
            SetChatFunction(CHAT_FUNC_SAVE_AND_EXIT);
        else
            sChat->exitDelayTimer++;
        break;
    }
}

static void Chat_Drop(void)
{
    switch (sChat->funcState)
    {
    case 0:
        if (!FuncIsActiveTask(Task_ReceiveChatMessage))
        {
            StartDisplaySubtask(CHATDISPLAY_FUNC_DESTROY_YESNO, 0);
            sChat->funcState++;
        }
        break;
    case 1:
        if (!IsDisplaySubtaskActive(0) && IsLinkTaskFinished() && !sub_8011A9C())
        {
            SetCloseLinkCallback();
            sChat->exitDelayTimer = 0;
            sChat->funcState++;
        }
        break;
    case 2:
        if (sChat->exitDelayTimer < 150)
            sChat->exitDelayTimer++;

        if (!gReceivedRemoteLinkPlayers)
            sChat->funcState++;
        break;
    case 3:
        if (sChat->exitDelayTimer >= 150)
            SetChatFunction(CHAT_FUNC_SAVE_AND_EXIT);
        else
            sChat->exitDelayTimer++;
        break;
    }
}

static void Chat_Disbanded(void)
{
    switch (sChat->funcState)
    {
    case 0:
        if (!FuncIsActiveTask(Task_ReceiveChatMessage))
        {
            if (sChat->multiplayerId)
                StartDisplaySubtask(CHATDISPLAY_FUNC_DESTROY_YESNO, 0);

            sChat->funcState++;
        }
        break;
    case 1:
        if (!IsDisplaySubtaskActive(0))
        {
            if (sChat->multiplayerId)
                StartDisplaySubtask(CHATDISPLAY_FUNC_PRINT_LEADER_LEFT, 0);

            sChat->funcState++;
        }
        break;
    case 2:
        if (IsDisplaySubtaskActive(0) != TRUE && IsLinkTaskFinished() && !sub_8011A9C())
        {
            SetCloseLinkCallback();
            sChat->exitDelayTimer = 0;
            sChat->funcState++;
        }
        break;
    case 3:
        if (sChat->exitDelayTimer < 150)
            sChat->exitDelayTimer++;

        if (!gReceivedRemoteLinkPlayers)
            sChat->funcState++;
        break;
    case 4:
        if (sChat->exitDelayTimer >= 150)
            SetChatFunction(CHAT_FUNC_SAVE_AND_EXIT);
        else
            sChat->exitDelayTimer++;
        break;
    }
}

static void Chat_SendMessage(void)
{
    switch (sChat->funcState)
    {
    case 0:
        if (!gReceivedRemoteLinkPlayers)
        {
            SetChatFunction(CHAT_FUNC_HANDLE_INPUT);
            break;
        }

        PrepareSendBuffer_Chat(sChat->sendMessageBuffer);
        sChat->funcState++;
        // fall through
    case 1:
        if (IsLinkTaskFinished() == TRUE && !sub_8011A9C() && SendBlock(0, sChat->sendMessageBuffer, sizeof(sChat->sendMessageBuffer)))
            sChat->funcState++;
        break;
    case 2:
        ResetMessageEntryBuffer();
        StartDisplaySubtask(CHATDISPLAY_FUNC_UPDATE_MSG, 0);
        sChat->funcState++;
        break;
    case 3:
        if (!IsDisplaySubtaskActive(0))
            sChat->funcState++;
        break;
    case 4:
        if (IsLinkTaskFinished())
            SetChatFunction(CHAT_FUNC_HANDLE_INPUT);
        break;
    }
}

static void Chat_Register(void)
{
    switch (sChat->funcState)
    {
    case 0:
        if (ChatMessageIsNotEmpty())
        {
            StartDisplaySubtask(CHATDISPLAY_FUNC_ASK_REGISTER_TEXT, 0);
            sChat->funcState = 2;
        }
        else
        {
            StartDisplaySubtask(CHATDISPLAY_FUNC_PRINT_INPUT_TEXT, 0);
            sChat->funcState = 5;
        }
        break;
    case 1:
        if (JOY_NEW(A_BUTTON))
        {
            RegisterTextAtRow();
            StartDisplaySubtask(CHATDISPLAY_FUNC_RETURN_TO_KB, 0);
            sChat->funcState = 3;
        }
        else if (JOY_NEW(B_BUTTON))
        {
            StartDisplaySubtask(CHATDISPLAY_FUNC_CANCEL_REGISTER, 0);
            sChat->funcState = 4;
        }
        else if (HandleDPadInput())
        {
            StartDisplaySubtask(CHATDISPLAY_FUNC_MOVE_KB_CURSOR, 0);
            sChat->funcState = 2;
        }
        break;
    case 2:
        if (!IsDisplaySubtaskActive(0))
            sChat->funcState = 1;
        break;
    case 3:
        if (!IsDisplaySubtaskActive(0))
        {
            StartDisplaySubtask(CHATDISPLAY_FUNC_CANCEL_REGISTER, 0);
            sChat->funcState = 4;
        }
        break;
    case 4:
        if (!IsDisplaySubtaskActive(0))
            SetChatFunction(CHAT_FUNC_HANDLE_INPUT);
        break;
    case 5:
        if (!IsDisplaySubtaskActive(0))
            sChat->funcState = 6;
        break;
    case 6:
        if (JOY_NEW(A_BUTTON | B_BUTTON))
        {
            StartDisplaySubtask(CHATDISPLAY_FUNC_DESTROY_YESNO, 0);
            sChat->funcState = 4;
        }
        break;
    }
}

static void Chat_SaveAndExit(void)
{
    s8 input;

    switch (sChat->funcState)
    {
    case 0:
        if (!sChat->changedRegisteredTexts)
        {
            sChat->funcState = 12;
        }
        else
        {
            StartDisplaySubtask(CHATDISPLAY_FUNC_DESTROY_YESNO, 0);
            sChat->funcState = 1;
        }
        break;
    case 1:
        if (!IsDisplaySubtaskActive(0))
        {
            StartDisplaySubtask(CHATDISPLAY_FUNC_ASK_SAVE, 0);
            sChat->funcState = 2;
        }
        break;
    case 2:
        input = ProcessMenuInput();
        switch (input)
        {
        case -1:
        case 1:
            sChat->funcState = 12;
            break;
        case 0:
            StartDisplaySubtask(CHATDISPLAY_FUNC_DESTROY_YESNO, 0);
            sChat->funcState = 3;
            break;
        }
        break;
    case 3:
        if (!IsDisplaySubtaskActive(0))
        {
            StartDisplaySubtask(CHATDISPLAY_FUNC_ASK_OVERWRITE_SAVE, 0);
            sChat->funcState = 4;
        }
        break;
    case 4:
        if (!IsDisplaySubtaskActive(0))
            sChat->funcState = 5;
        break;
    case 5:
        input = ProcessMenuInput();
        switch (input)
        {
        case -1:
        case 1:
            sChat->funcState = 12;
            break;
        case 0:
            StartDisplaySubtask(CHATDISPLAY_FUNC_DESTROY_YESNO, 0);
            sChat->funcState = 6;
            break;
        }
        break;
    case 6:
        if (!IsDisplaySubtaskActive(0))
        {
            StartDisplaySubtask(CHATDISPLAY_FUNC_PRINT_SAVING, 0);
            SaveRegisteredTexts();
            sChat->funcState = 7;
        }
        break;
    case 7:
        if (!IsDisplaySubtaskActive(0))
        {
            SetContinueGameWarpStatusToDynamicWarp();
            TrySavingData(SAVE_NORMAL);
            sChat->funcState = 8;
        }
        break;
    case 8:
        StartDisplaySubtask(CHATDISPLAY_FUNC_PRINT_SAVED_GAME, 0);
        sChat->funcState = 9;
        break;
    case 9:
        if (!IsDisplaySubtaskActive(0))
        {
            PlaySE(SE_SAVE);
            ClearContinueGameWarpStatus2();
            sChat->funcState = 10;
        }
        break;
    case 10:
        sChat->afterSaveTimer = 0;
        sChat->funcState = 11;
        break;
    case 11:
        sChat->afterSaveTimer++;
        if (sChat->afterSaveTimer > 120)
            sChat->funcState = 12;
        break;
    case 12:
        BeginNormalPaletteFade(PALETTES_ALL, -1, 0, 16, RGB_BLACK);
        sChat->funcState = 13;
        break;
    case 13:
        if (!gPaletteFade.active)
        {
            FreeDisplay();
            FreeUnionRoomChat();
            SetMainCallback2(CB2_ReturnToField);
        }
        break;
    }
}

static void SetChatFunction(u16 funcId)
{
    sChat->funcId = funcId;
    sChat->funcState = 0;
}

static bool32 HandleDPadInput(void)
{
    do
    {
        if (JOY_REPEAT(DPAD_UP))
        {
            if (sChat->currentRow > 0)
                sChat->currentRow--;
            else
                sChat->currentRow = sKeyboardPageMaxRow[sChat->currentPage];
            break;
        }
        if (JOY_REPEAT(DPAD_DOWN))
        {
            if (sChat->currentRow < sKeyboardPageMaxRow[sChat->currentPage])
                sChat->currentRow++;
            else
                sChat->currentRow = 0;
            break;
        }
        if (sChat->currentPage != UNION_ROOM_KB_PAGE_REGISTER)
        {
            if (JOY_REPEAT(DPAD_LEFT))
            {
                if (sChat->currentCol > 0)
                    sChat->currentCol--;
                else
                    sChat->currentCol = 4;
                break;
            }
            else if (JOY_REPEAT(DPAD_RIGHT))
            {
                if (sChat->currentCol < 4)
                    sChat->currentCol++;
                else
                    sChat->currentCol = 0;
                break;
            }
        }
        return FALSE;
    } while (0);

    return TRUE;  
}

static void AppendTextToMessage(void)
{
    int i;
    const u8 *charsStr;
    int strLength;
    u8 *str;
    u8 buffer[21];

    if (sChat->currentPage != UNION_ROOM_KB_PAGE_REGISTER)
    {
        // Going to append a single character        
        charsStr = sUnionRoomKeyboardText[sChat->currentPage][sChat->currentRow];
        for (i = 0; i < sChat->currentCol; i++)
        {
            if (*charsStr == CHAR_EXTRA_SYMBOL)
                charsStr++;
            charsStr++;
        }

        strLength = 1;
    }
    else
    {
        // Going to append registered text string
        u8 *tempStr = StringCopy(buffer, sChat->registeredTexts[sChat->currentRow]);
        tempStr[0] = CHAR_SPACE;
        tempStr[1] = EOS;
        charsStr = buffer;
        strLength = StringLength_Multibyte(buffer);
    }

    sChat->lastBufferCursorPos = sChat->bufferCursorPos;
    if (!charsStr)
        return;

    str = GetEndOfMessagePtr();
    while (--strLength != -1 && sChat->bufferCursorPos < MAX_MESSAGE_LENGTH)
    {
        if (*charsStr == CHAR_EXTRA_SYMBOL)
        {
            *str = *charsStr;
            charsStr++;
            str++;
        }

        *str = *charsStr;
        charsStr++;
        str++;

        sChat->bufferCursorPos++;
    }

    *str = EOS;
}

static void DeleteLastMessageCharacter(void)
{
    sChat->lastBufferCursorPos = sChat->bufferCursorPos;
    if (sChat->bufferCursorPos)
    {
        u8 *str = GetLastCharOfMessagePtr();
        *str = EOS;
        sChat->bufferCursorPos--;
    }
}

static void SwitchCaseOfLastMessageCharacter(void)
{
    u8 *str;
    u8 character;

    sChat->lastBufferCursorPos = sChat->bufferCursorPos - 1;
    str = GetLastCharOfMessagePtr();
    if (*str != CHAR_EXTRA_SYMBOL)
    {
        character = sCaseToggleTable[*str];
        if (character)
            *str = character;
    }
}

static bool32 ChatMessageIsNotEmpty(void)
{
    if (sChat->bufferCursorPos)
        return TRUE;
    else
        return FALSE;
}

static void RegisterTextAtRow(void)
{
    u8 *src = GetLimitedMessageStartPtr();
    StringCopy(sChat->registeredTexts[sChat->currentRow], src);
    sChat->changedRegisteredTexts = TRUE;
}

static void ResetMessageEntryBuffer(void)
{
    sChat->messageEntryBuffer[0] = EOS;
    sChat->lastBufferCursorPos = 15;
    sChat->bufferCursorPos = 0;
}

static void SaveRegisteredTexts(void)
{
    int i;
    for (i = 0; i < UNION_ROOM_KB_ROW_COUNT; i++)
        StringCopy(gSaveBlock1Ptr->registeredTexts[i], sChat->registeredTexts[i]);
}

static u8 *GetRegisteredTextByRow(int row)
{
    return sChat->registeredTexts[row];
}

static u8 *GetEndOfMessagePtr(void)
{
    u8 *str = sChat->messageEntryBuffer;
    while (*str != EOS)
        str++;

    return str;
}

static u8 *GetLastCharOfMessagePtr(void)
{
    u8 *currChar = sChat->messageEntryBuffer;
    u8 *lastChar = currChar;
    while (*currChar != EOS)
    {
        lastChar = currChar;
        if (*currChar == CHAR_EXTRA_SYMBOL)
            currChar++;
        currChar++;
    }

    return lastChar;
}

static u16 GetNumOverflowCharsInMessage(void)
{
    u8 *str;
    u32 i, numChars, strLength;

    strLength = StringLength_Multibyte(sChat->messageEntryBuffer);
    str = sChat->messageEntryBuffer;
    numChars = 0;
    if (strLength > 10)
    {
        strLength -= 10;
        for (i = 0; i < strLength; i++)
        {
            if (*str == CHAR_EXTRA_SYMBOL)
                str++;

            str++;
            numChars++;
        }
    }

    return numChars;
}

static void PrepareSendBuffer_Null(u8 *buffer)
{
    buffer[0] = CHAT_MESSAGE_NONE;
}

static void PrepareSendBuffer_Join(u8 *buffer)
{
    buffer[0] = CHAT_MESSAGE_JOIN;
    StringCopy(&buffer[1], gSaveBlock2Ptr->playerName);
    buffer[1 + (PLAYER_NAME_LENGTH + 1)] = sChat->multiplayerId;
}

static void PrepareSendBuffer_Chat(u8 *buffer)
{
    buffer[0] = CHAT_MESSAGE_CHAT;
    StringCopy(&buffer[1], gSaveBlock2Ptr->playerName);
    StringCopy(&buffer[1 + (PLAYER_NAME_LENGTH + 1)], sChat->messageEntryBuffer);
}

static void PrepareSendBuffer_Leave(u8 *buffer)
{
    buffer[0] = CHAT_MESSAGE_LEAVE;
    StringCopy(&buffer[1], gSaveBlock2Ptr->playerName);
    buffer[1 + (PLAYER_NAME_LENGTH + 1)] = sChat->multiplayerId;
    sub_8011A50();
}

static void PrepareSendBuffer_Drop(u8 *buffer)
{
    buffer[0] = CHAT_MESSAGE_DROP;
    StringCopy(&buffer[1], gSaveBlock2Ptr->playerName);
    buffer[1 + (PLAYER_NAME_LENGTH + 1)] = sChat->multiplayerId;
}

static void PrepareSendBuffer_Disband(u8 *buffer)
{
    buffer[0] = CHAT_MESSAGE_DISBAND;
    StringCopy(&buffer[1], gSaveBlock2Ptr->playerName);
    buffer[1 + (PLAYER_NAME_LENGTH + 1)] = sChat->multiplayerId;
}

static bool32 ProcessReceivedChatMessage(u8 *dest, u8 *recvMessage)
{
    u8 *tempStr;
    u8 cmd = *recvMessage;
    u8 *name = recvMessage + 1;
    recvMessage = name;
    recvMessage += PLAYER_NAME_LENGTH + 1;

    switch (cmd)
    {
    case CHAT_MESSAGE_JOIN:
        if (sChat->multiplayerId != name[PLAYER_NAME_LENGTH + 1])
        {
            DynamicPlaceholderTextUtil_Reset();
            DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, name);
            DynamicPlaceholderTextUtil_ExpandPlaceholders(dest, gText_F700JoinedChat);
            return TRUE;
        }
        break;
    case CHAT_MESSAGE_CHAT:
        tempStr = StringCopy(dest, name);
        *(tempStr++) = EXT_CTRL_CODE_BEGIN;
        *(tempStr++) = EXT_CTRL_CODE_CLEAR_TO;
        *(tempStr++) = 42;
        *(tempStr++) = CHAR_COLON;
        StringCopy(tempStr, recvMessage);
        return TRUE;
    case CHAT_MESSAGE_DISBAND:
        StringCopy(sChat->hostName, name);
        // fall through
    case CHAT_MESSAGE_LEAVE:
        if (sChat->multiplayerId != *recvMessage)
        {
            DynamicPlaceholderTextUtil_Reset();
            DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, name);
            DynamicPlaceholderTextUtil_ExpandPlaceholders(dest, gText_F700LeftChat);
            return TRUE;
        }
        break;
    }

    return FALSE;
}

static u8 GetCurrentKeyboardPage(void)
{
    return sChat->currentPage;
}

static void GetCurrentKeyboardColAndRow(u8 *col, u8 *row)
{
    *col = sChat->currentCol;
    *row = sChat->currentRow;
}

static u8 *GetMessageEntryBuffer(void)
{
    return sChat->messageEntryBuffer;
}

static int GetLengthOfMessageEntry(void)
{
    u8 *str = GetMessageEntryBuffer();
    return StringLength_Multibyte(str);
}

static void GetBufferSelectionRegion(u32 *x, u32 *width)
{
    int diff = sChat->bufferCursorPos - sChat->lastBufferCursorPos;
    if (diff < 0)
    {
        diff *= -1;
        *x = sChat->bufferCursorPos;
    }
    else
    {
        *x = sChat->lastBufferCursorPos;
    }

    *width = diff;
}

static u8 *GetLimitedMessageStartPtr(void)
{
    int i;
    u16 numChars = GetNumOverflowCharsInMessage();
    u8 *str = sChat->messageEntryBuffer;
    for (i = 0; i < numChars; i++)
    {
        if (*str == CHAR_EXTRA_SYMBOL)
            *str++;

        str++;
    }

    return str;
}

static u16 GetLimitedMessageStartPos(void)
{
    u16 count;
    u32 i;
    u16 numChars = GetNumOverflowCharsInMessage();
    u8 *str = sChat->messageEntryBuffer;
    for (count = 0, i = 0; i < numChars; count++, i++)
    {
        if (*str == CHAR_EXTRA_SYMBOL)
            str++;

        str++;
    }

    return count;
}

static u8 *GetLastReceivedMessage(void)
{
    return sChat->receivedMessage;
}

static u8 GetReceivedPlayerIndex(void)
{
    return sChat->receivedPlayerIndex;
}

static int GetTextEntryCursorPosition(void)
{
    return sChat->bufferCursorPos;
}

static int GetShouldShowCaseToggleIcon(void)
{
    u8 *str = GetLastCharOfMessagePtr();
    u32 character = *str;
    if (character > 0xFF || sCaseToggleTable[character] == character || sCaseToggleTable[character] == 0)
        return 3;
    else
        return 0;
}

static u8 *GetChatHostName(void)
{
    return sChat->hostName;
}

void InitUnionRoomChatRegisteredTexts(void)
{
    StringCopy(gSaveBlock1Ptr->registeredTexts[0], gText_Hello);
    StringCopy(gSaveBlock1Ptr->registeredTexts[1], gText_Pokemon2);
    StringCopy(gSaveBlock1Ptr->registeredTexts[2], gText_Trade);
    StringCopy(gSaveBlock1Ptr->registeredTexts[3], gText_Battle);
    StringCopy(gSaveBlock1Ptr->registeredTexts[4], gText_Lets);
    StringCopy(gSaveBlock1Ptr->registeredTexts[5], gText_Ok);
    StringCopy(gSaveBlock1Ptr->registeredTexts[6], gText_Sorry);
    StringCopy(gSaveBlock1Ptr->registeredTexts[7], gText_YaySmileEmoji);
    StringCopy(gSaveBlock1Ptr->registeredTexts[8], gText_ThankYou);
    StringCopy(gSaveBlock1Ptr->registeredTexts[9], gText_ByeBye);
}

#define tState               data[0]
#define tI                   data[1]
#define tCurrLinkPlayer      data[2]
#define tBlockReceivedStatus data[3]
#define tLinkPlayerCount     data[4]
#define tNextState           data[5]

static void Task_ReceiveChatMessage(u8 taskId)
{
    u8 *buffer;
    s16 *data = gTasks[taskId].data;

    switch (tState)
    {
    case 0:
        if (!gReceivedRemoteLinkPlayers)
        {
            DestroyTask(taskId);
            return;
        }

        tState = 1;
        // fall through
    case 1:
        tLinkPlayerCount = GetLinkPlayerCount();
        if (sChat->linkPlayerCount != tLinkPlayerCount)
        {
            tState = 2;
            sChat->linkPlayerCount = tLinkPlayerCount;
            return;
        }

        tBlockReceivedStatus = GetBlockReceivedStatus();
        if (!tBlockReceivedStatus && sub_8011A9C())
            return;

        tI = 0;
        tState = 3;
        // fall through
    case 3:
        for (; tI < 5 && ((tBlockReceivedStatus >> tI) & 1) == 0; tI++)
            ;

        if (tI == 5)
        {
            tState = 1;
            return;
        }

        tCurrLinkPlayer = tI;
        ResetBlockReceivedFlag(tCurrLinkPlayer);
        buffer = (u8 *)gBlockRecvBuffer[tI];
        switch (buffer[0])
        {
            default:
            case CHAT_MESSAGE_CHAT:     tNextState = 3; break;
            case CHAT_MESSAGE_JOIN:    tNextState = 3; break;
            case CHAT_MESSAGE_LEAVE:   tNextState = 4; break;
            case CHAT_MESSAGE_DROP:    tNextState = 5; break;
            case CHAT_MESSAGE_DISBAND: tNextState = 6; break;
        }

        if (ProcessReceivedChatMessage(sChat->receivedMessage, (u8 *)gBlockRecvBuffer[tI]))
        {
            sChat->receivedPlayerIndex = tI;
            StartDisplaySubtask(CHATDISPLAY_FUNC_SCROLL_CHAT, 2);
            tState = 7;
        }
        else
        {
            tState = tNextState;
        }

        tI++;
        break;
    case 7:
        if (!IsDisplaySubtaskActive(2))
            tState = tNextState;
        break;
    case 4:
        if (!sChat->multiplayerId && tCurrLinkPlayer)
        {
            if (GetLinkPlayerCount() == 2)
            {
                sub_80104B0();
                sChat->exitType = 1;
                DestroyTask(taskId);
                return;
            }

            sub_8011DE0(tCurrLinkPlayer);
        }

        tState = 3;
        break;
    case 5:
        if (sChat->multiplayerId)
            sChat->exitType = 2;

        DestroyTask(taskId);
        break;
    case 6:
        sChat->exitType = 3;
        DestroyTask(taskId);
        break;
    case 2:
        if (!sub_8011A9C())
        {
            if (!sChat->multiplayerId)
                sub_80110B8(sChat->linkPlayerCount);

            tState = 1;
        }
        break;
    }
}

#undef tNextState
#undef tLinkPlayerCount
#undef tBlockReceivedStatus
#undef tCurrLinkPlayer
#undef tI
#undef tState

static bool8 TryAllocDisplay(void)
{
    sDisplay = Alloc(sizeof(*sDisplay));
    if (sDisplay && TryAllocSprites())
    {
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, sBgTemplates, ARRAY_COUNT(sBgTemplates));
        InitWindows(sWinTemplates);
        ResetTempTileDataBuffers();
        InitScanlineEffect();
        InitDisplay(sDisplay);
        ResetDisplaySubtasks();
        StartDisplaySubtask(CHATDISPLAY_FUNC_LOAD_GFX, 0);
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

static bool32 IsDisplaySubtask0Active(void)
{
    return IsDisplaySubtaskActive(0);
}

static void FreeDisplay(void)
{
    FreeSprites();
    if (sDisplay)
        FREE_AND_SET_NULL(sDisplay);

    FreeAllWindowBuffers();
    gScanlineEffect.state = 3;
}

static void InitDisplay(struct UnionRoomChatDisplay *display)
{
    display->yesNoMenuWindowId = WINDOW_NONE;
    display->messageWindowId = WINDOW_NONE;
    display->currLine = 0;
}

static void ResetDisplaySubtasks(void)
{
    int i;

    if (!sDisplay)
        return;

    for (i = 0; i < (int)ARRAY_COUNT(sDisplay->subtasks); i++)
    {
        sDisplay->subtasks[i].callback = Display_Dummy;
        sDisplay->subtasks[i].active = FALSE;
        sDisplay->subtasks[i].state = 0;
    }
}

static void RunDisplaySubtasks(void)
{
    int i;

    if (!sDisplay)
        return;

    for (i = 0; i < (int)ARRAY_COUNT(sDisplay->subtasks); i++)
    {
        sDisplay->subtasks[i].active =
            sDisplay->subtasks[i].callback(&sDisplay->subtasks[i].state);
    }
}

static void StartDisplaySubtask(u16 subtaskId, u8 assignId)
{
    u32 i;

    sDisplay->subtasks[assignId].callback = Display_Dummy;
    for (i = 0; i < ARRAY_COUNT(sDisplaySubtasks); i++)
    {
        if (sDisplaySubtasks[i].idx == subtaskId)
        {
            sDisplay->subtasks[assignId].callback = sDisplaySubtasks[i].callback;
            sDisplay->subtasks[assignId].active = TRUE;
            sDisplay->subtasks[assignId].state = 0;
            break;
        }
    }
}

static bool8 IsDisplaySubtaskActive(u8 id)
{
    return sDisplay->subtasks[id].active;
}

static bool32 Display_LoadGfx(u8 *state)
{
    if (FreeTempTileDataBuffersIfPossible() == TRUE)
        return TRUE;

    switch (*state)
    {
    case 0:
        ResetGpuBgState();
        SetBgTilemapBuffers();
        break;
    case 1:
        ClearBg0();
        break;
    case 2:
        LoadChatWindowBorderGfx();
        break;
    case 3:
        LoadChatWindowGfx();
        break;
    case 4:
        sub_8020680();
        break;
    case 5:
        LoadChatMessagesWindow();
        LoadKeyboardWindow();
        LoadKeyboardSwapWindow();
        LoadTextEntryWindow();
        break;
    case 6:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            CreateKeyboardCursorSprite();
            CreateTextEntrySprites();
            CreateRButtonSprites();
        }
        break;
    default:
        return FALSE;
    }

    (*state)++;
    return TRUE;
}

static bool32 Display_ShowKeyboardSwapMenu(u8 *state)
{
    switch (*state)
    {
    case 0:
        ShowKeyboardSwapMenu();
        CopyWindowToVram(3, 3);
        break;
    case 1:
        return IsDma3ManagerBusyWithBgCopy();
    }

    (*state)++;
    return TRUE;
}

static bool32 Display_HideKeyboardSwapMenu(u8 *state)
{
    switch (*state)
    {
    case 0:
        HideKeyboardSwapMenu();
        CopyWindowToVram(3, 3);
        break;
    case 1:
        return IsDma3ManagerBusyWithBgCopy();
    }

    (*state)++;
    return TRUE;
}

static bool32 Display_SwitchPages(u8 *state)
{
    switch (*state)
    {
    case 0:
        SetKeyboardCursorInvisibility(TRUE);
        if (sub_8020320())
            return TRUE;

        PrintCurrentKeyboardPage();
        CopyWindowToVram(2, 2);
        break;
    case 1:
        if (IsDma3ManagerBusyWithBgCopy())
            return TRUE;
        break;
    case 2:
        if (sub_8020368())
            return TRUE;

        MoveKeyboardCursor();
        SetKeyboardCursorInvisibility(FALSE);
        UpdateRButtonLabel();
        return FALSE;
    }

    (*state)++;
    return TRUE;
}

static bool32 Display_MoveKeyboardCursor(u8 *state)
{
    MoveKeyboardCursor();
    return FALSE;
}

static bool32 Display_AskQuitChatting(u8 *state)
{
    switch (*state)
    {
    case 0:
        AddStdMessageWindow(STDMESSAGE_QUIT_CHATTING, 0);
        AddYesNoMenuAt(23, 11, 1);
        CopyWindowToVram(sDisplay->messageWindowId, 3);
        break;
    case 1:
        return IsDma3ManagerBusyWithBgCopy();
    }

    (*state)++;
    return TRUE;
}

static bool32 Display_DestroyYesNoDialog(u8 *state)
{
    switch (*state)
    {
    case 0:
        HideStdMessageWindow();
        HideYesNoMenuWindow();
        CopyBgTilemapBufferToVram(0);
        break;
    case 1:
        if (IsDma3ManagerBusyWithBgCopy())
            return TRUE;

        DestroyStdMessageWindow();
        DestroyYesNoMenuWindow();
        return FALSE;
    }

    (*state)++;
    return TRUE;
}

static bool32 Display_UpdateMessageBuffer(u8 *state)
{
    u32 x, width;
    u8 *str;

    switch (*state)
    {
    case 0:
        GetBufferSelectionRegion(&x, &width);
        FillTextEntryWindow(x, width, 0);
        str = GetMessageEntryBuffer();
        DrawTextEntryMessage(0, str, 3, 1, 2);
        CopyWindowToVram(1, 2);
        break;
    case 1:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            UpdateRButtonLabel();
            return FALSE;
        }
        return TRUE;
    }

    (*state)++;
    return TRUE;
}

static bool32 Display_AskRegisterText(u8 *state)
{
    u16 x;
    u8 *str;
    u16 length;

    switch (*state)
    {
    case 0:
        x = GetLimitedMessageStartPos();
        str = GetLimitedMessageStartPtr();
        length = StringLength_Multibyte(str);
        FillTextEntryWindow(x, length, PIXEL_FILL(6));
        DrawTextEntryMessage(x, str, 0, 4, 5);
        CopyWindowToVram(1, 2);
        break;
    case 1:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            AddStdMessageWindow(STDMESSAGE_REGISTER_WHERE, 16);
            CopyWindowToVram(sDisplay->messageWindowId, 3);
        }
        else
        {
            return TRUE;
        }
        break;
    case 2:
        if (!IsDma3ManagerBusyWithBgCopy())
            SetRegisteredTextPalette(TRUE);
        else
            return TRUE;
        break;
    case 3:
        return FALSE;
    }

    (*state)++;
    return TRUE;
}

static bool32 Display_CancelRegister(u8 *state)
{
    u16 x;
    u8 *str;
    u16 length;

    switch (*state)
    {
    case 0:
        x = GetLimitedMessageStartPos();
        str = GetLimitedMessageStartPtr();
        length = StringLength_Multibyte(str);
        FillTextEntryWindow(x, length, PIXEL_FILL(0));
        DrawTextEntryMessage(x, str, 3, 1, 2);
        CopyWindowToVram(1, 2);
        break;
    case 1:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            HideStdMessageWindow();
            CopyWindowToVram(sDisplay->messageWindowId, 3);
        }
        else
        {
            return TRUE;
        }
        break;
    case 2:
        if (!IsDma3ManagerBusyWithBgCopy())
        {
            SetRegisteredTextPalette(FALSE);
            DestroyStdMessageWindow();
        }
        else
        {
            return TRUE;
        }
        break;
    case 3:
        return FALSE;
    }

    (*state)++;
    return TRUE;
}

static bool32 Display_ReturnToKeyboard(u8 *state)
{
    switch (*state)
    {
    case 0:
        PrintCurrentKeyboardPage();
        CopyWindowToVram(2, 2);
        (*state)++;
        break;
    case 1:
        if (IsDma3ManagerBusyWithBgCopy())
            return TRUE;
        else
            return FALSE;
    }

    return TRUE;
}

static bool32 Display_ScrollChat(u8 *state)
{
    u16 row;
    u8 *str;
    u8 colorIdx;

    switch (*state)
    {
    case 0:
        row = sDisplay->currLine;
        str = GetLastReceivedMessage();
        colorIdx = GetReceivedPlayerIndex();
        PrintChatMessage(row, str, colorIdx);
        CopyWindowToVram(0, 2);
        break;
    case 1:
        if (IsDma3ManagerBusyWithBgCopy())
            return TRUE;

        if (sDisplay->currLine < 9)
        {
            sDisplay->currLine++;
            *state = 4;
            return FALSE;
        }
        else
        {
            sDisplay->scrollCount = 0;
            (*state)++;
        }
        // fall through
    case 2:
        ScrollWindow(0, 0, 5, PIXEL_FILL(1));
        CopyWindowToVram(0, 2);
        sDisplay->scrollCount++;
        (*state)++;
        // fall through
    case 3:
        if (IsDma3ManagerBusyWithBgCopy())
            return TRUE;

        if (sDisplay->scrollCount < 3)
        {
            (*state)--;
            return TRUE;
        }
        break;
    case 4:
        return FALSE;
    default:
        return TRUE;
    }

    (*state)++;
    return TRUE;
}

static bool32 Display_AnimateKeyboardCursor(u8 *state)
{
    switch (*state)
    {
    case 0:
        StartKeyboardCursorAnim();
        (*state)++;
        break;
    case 1:
        return TryKeyboardCursorReopen();
    }

    return TRUE;
}

static bool32 Display_PrintInputText(u8 *state)
{
    switch (*state)
    {
    case 0:
        AddStdMessageWindow(STDMESSAGE_INPUT_TEXT, 16);
        CopyWindowToVram(sDisplay->messageWindowId, 3);
        (*state)++;
        break;
    case 1:
        return IsDma3ManagerBusyWithBgCopy();
    }

    return TRUE;
}

static bool32 Display_PrintExitingChat(u8 *state)
{
    switch (*state)
    {
    case 0:
        AddStdMessageWindow(STDMESSAGE_EXITING_CHAT, 0);
        CopyWindowToVram(sDisplay->messageWindowId, 3);
        (*state)++;
        break;
    case 1:
        return IsDma3ManagerBusyWithBgCopy();
    }

    return TRUE;
}

static bool32 Display_PrintLeaderLeft(u8 *state)
{
    u8 *str;

    switch (*state)
    {
    case 0:
        DynamicPlaceholderTextUtil_Reset();
        str = GetChatHostName();
        DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, str);
        AddStdMessageWindow(STDMESSAGE_LEADER_LEFT, 0);
        CopyWindowToVram(sDisplay->messageWindowId, 3);
        (*state)++;
        break;
    case 1:
        return IsDma3ManagerBusyWithBgCopy();
    }

    return TRUE;
}

static bool32 Display_AskSave(u8 *state)
{
    switch (*state)
    {
    case 0:
        AddStdMessageWindow(STDMESSAGE_ASK_SAVE, 0);
        AddYesNoMenuAt(23, 10, 1);
        CopyWindowToVram(sDisplay->messageWindowId, 3);
        (*state)++;
        break;
    case 1:
        return IsDma3ManagerBusyWithBgCopy();
    }

    return TRUE;
}

static bool32 Display_AskOverwriteSave(u8 *state)
{
    switch (*state)
    {
    case 0:
        AddStdMessageWindow(STDMESSAGE_ASK_OVERWRITE, 0);
        AddYesNoMenuAt(23, 10, 1);
        CopyWindowToVram(sDisplay->messageWindowId, 3);
        (*state)++;
        break;
    case 1:
        return IsDma3ManagerBusyWithBgCopy();
    }

    return TRUE;
}

static bool32 Display_PrintSavingDontTurnOff(u8 *state)
{
    switch (*state)
    {
    case 0:
        AddStdMessageWindow(STDMESSAGE_SAVING_NO_OFF, 0);
        CopyWindowToVram(sDisplay->messageWindowId, 3);
        (*state)++;
        break;
    case 1:
        return IsDma3ManagerBusyWithBgCopy();
    }

    return TRUE;
}

static bool32 Display_PrintSavedTheGame(u8 *state)
{
    switch (*state)
    {
    case 0:
        DynamicPlaceholderTextUtil_Reset();
        DynamicPlaceholderTextUtil_SetPlaceholderPtr(0, gSaveBlock2Ptr->playerName);
        AddStdMessageWindow(STDMESSAGE_SAVED_THE_GAME, 0);
        CopyWindowToVram(sDisplay->messageWindowId, 3);
        (*state)++;
        break;
    case 1:
        return IsDma3ManagerBusyWithBgCopy();
    }

    return TRUE;
}

static bool32 Display_AskConfirmLeaderLeave(u8 *state)
{
    switch (*state)
    {
    case 0:
        AddStdMessageWindow(STDMESSAGE_WARN_LEADER_LEAVE, 0);
        AddYesNoMenuAt(23, 10, 1);
        CopyWindowToVram(sDisplay->messageWindowId, 3);
        (*state)++;
        break;
    case 1:
        return IsDma3ManagerBusyWithBgCopy();
    }

    return TRUE;
}

static bool32 Display_Dummy(u8 *state)
{
    return FALSE;
}

static void AddYesNoMenuAt(u8 left, u8 top, u8 initialCursorPos)
{
    struct WindowTemplate template;
    template.bg = 0;
    template.tilemapLeft = left;
    template.tilemapTop = top;
    template.width = 6;
    template.height = 4;
    template.paletteNum = 14;
    template.baseBlock = 0x52;
    sDisplay->yesNoMenuWindowId = AddWindow(&template);
    if (sDisplay->yesNoMenuWindowId != WINDOW_NONE)
    {
        FillWindowPixelBuffer(sDisplay->yesNoMenuWindowId, PIXEL_FILL(1));
        PutWindowTilemap(sDisplay->yesNoMenuWindowId);
        AddTextPrinterParameterized(sDisplay->yesNoMenuWindowId, 1, gText_Yes, 8, 1, TEXT_SPEED_FF, NULL);
        AddTextPrinterParameterized(sDisplay->yesNoMenuWindowId, 1, gText_No, 8, 17, TEXT_SPEED_FF, NULL);
        DrawTextBorderOuter(sDisplay->yesNoMenuWindowId, 1, 13);
        InitMenuInUpperLeftCornerPlaySoundWhenAPressed(sDisplay->yesNoMenuWindowId, 2, initialCursorPos);
    }
}

static void HideYesNoMenuWindow(void)
{
    if (sDisplay->yesNoMenuWindowId != WINDOW_NONE)
    {
        ClearStdWindowAndFrameToTransparent(sDisplay->yesNoMenuWindowId, FALSE);
        ClearWindowTilemap(sDisplay->yesNoMenuWindowId);
    }
}

static void DestroyYesNoMenuWindow(void)
{
    if (sDisplay->yesNoMenuWindowId != WINDOW_NONE)
    {
        RemoveWindow(sDisplay->yesNoMenuWindowId);
        sDisplay->yesNoMenuWindowId = WINDOW_NONE;
    }
}

static s8 ProcessMenuInput(void)
{
    return Menu_ProcessInput();
}

static void AddStdMessageWindow(int msgId, u16 bg0vofs)
{
    const u8 *str;
    int windowId;
    struct WindowTemplate template;
    template.bg = 0;
    template.tilemapLeft = 8;
    template.tilemapTop = 16;
    template.width = 21;
    template.height = 4;
    template.paletteNum = 14;
    template.baseBlock = 0x6A;
    if (sDisplayStdMessages[msgId].useWiderBox)
    {
        template.tilemapLeft -= 7;
        template.width += 7;
    }

    sDisplay->messageWindowId = AddWindow(&template);
    windowId = sDisplay->messageWindowId;
    if (sDisplay->messageWindowId == WINDOW_NONE)
        return;

    if (sDisplayStdMessages[msgId].hasPlaceholders)
    {
        DynamicPlaceholderTextUtil_ExpandPlaceholders(sDisplay->expandedPlaceholdersBuffer, sDisplayStdMessages[msgId].text);
        str = sDisplay->expandedPlaceholdersBuffer;
    }
    else
    {
        str = sDisplayStdMessages[msgId].text;
    }

    ChangeBgY(0, bg0vofs * 256, 0);
    FillWindowPixelBuffer(windowId, PIXEL_FILL(1));
    PutWindowTilemap(windowId);
    if (sDisplayStdMessages[msgId].boxType == 1)
    {
        DrawTextBorderInner(windowId, 0xA, 2);
        AddTextPrinterParameterized5(
            windowId,
            1,
            str,
            sDisplayStdMessages[msgId].x + 8,
            sDisplayStdMessages[msgId].y + 8,
            TEXT_SPEED_FF,
            NULL,
            sDisplayStdMessages[msgId].letterSpacing,
            sDisplayStdMessages[msgId].lineSpacing);
    }
    else
    {
        DrawTextBorderOuter(windowId, 0xA, 2);
        AddTextPrinterParameterized5(
            windowId,
            1,
            str,
            sDisplayStdMessages[msgId].x,
            sDisplayStdMessages[msgId].y,
            TEXT_SPEED_FF,
            NULL,
            sDisplayStdMessages[msgId].letterSpacing,
            sDisplayStdMessages[msgId].lineSpacing);
    }

    sDisplay->messageWindowId = windowId;
}

static void HideStdMessageWindow(void)
{
    if (sDisplay->messageWindowId != WINDOW_NONE)
    {
        ClearStdWindowAndFrameToTransparent(sDisplay->messageWindowId, FALSE);
        ClearWindowTilemap(sDisplay->messageWindowId);
    }

    ChangeBgY(0, 0, 0);
}

static void DestroyStdMessageWindow(void)
{
    if (sDisplay->messageWindowId != WINDOW_NONE)
    {
        RemoveWindow(sDisplay->messageWindowId);
        sDisplay->messageWindowId = WINDOW_NONE;
    }
}

static void FillTextEntryWindow(u16 x, u16 width, u8 fillValue)
{
    FillWindowPixelRect(1, fillValue, x * 8, 1, width * 8, 14);
}

static void DrawTextEntryMessage(u16 x, u8 *str, u8 bgColor, u8 fgColor, u8 shadowColor)
{
    u8 color[3];
    u8 strBuffer[35];
    if (bgColor != TEXT_COLOR_TRANSPARENT)
        FillTextEntryWindow(x, GetTextEntryCursorPosition() - x, bgColor);

    color[0] = bgColor;
    color[1] = fgColor;
    color[2] = shadowColor;
    strBuffer[0] = EXT_CTRL_CODE_BEGIN;
    strBuffer[1] = EXT_CTRL_CODE_MIN_LETTER_SPACING;
    strBuffer[2] = 8;
    StringCopy(&strBuffer[3], str);
    AddTextPrinterParameterized3(1, 2, x * 8, 1, color, TEXT_SPEED_FF, strBuffer);
}

static void PrintCurrentKeyboardPage(void)
{
    u8 page;
    int i;
    u16 left;
    u16 top;
    u8 color[3];
    u8 str[45];
    u8 *str2;

    FillWindowPixelBuffer(2, PIXEL_FILL(15));
    page = GetCurrentKeyboardPage();
    color[0] = TEXT_COLOR_TRANSPARENT;
    color[1] = TEXT_DYNAMIC_COLOR_5;
    color[2] = TEXT_DYNAMIC_COLOR_4;
    if (page != UNION_ROOM_KB_PAGE_REGISTER)
    {
        str[0] = EXT_CTRL_CODE_BEGIN;
        str[1] = EXT_CTRL_CODE_MIN_LETTER_SPACING;
        str[2] = 8;

        if (page == UNION_ROOM_KB_PAGE_EMOJI)
            left = 6;
        else
            left = 8;

        for (i = 0, top = 0; i < UNION_ROOM_KB_ROW_COUNT; i++, top += 12)
        {
            if (!sUnionRoomKeyboardText[page][i])
                return;

            StringCopy(&str[3], sUnionRoomKeyboardText[page][i]);
            AddTextPrinterParameterized3(2, 0, left, top, color, TEXT_SPEED_FF, str);
        }
    }
    else
    {
        left = 4;
        for (i = 0, top = 0; i < UNION_ROOM_KB_ROW_COUNT; i++, top += 12)
        {
            str2 = GetRegisteredTextByRow(i);
            if (GetStringWidth(0, str2, 0) <= 40)
            {
                AddTextPrinterParameterized3(2, 0, left, top, color, TEXT_SPEED_FF, str2);
            }
            else
            {
                int length = StringLength_Multibyte(str2);
                do
                {
                    length--;
                    StringCopyN_Multibyte(str, str2, length);
                } while (GetStringWidth(0, str, 0) > 35);

                AddTextPrinterParameterized3(2, 0, left, top, color, TEXT_SPEED_FF, str);
                AddTextPrinterParameterized3(2, 0, left + 35, top, color, TEXT_SPEED_FF, sText_Ellipsis);
            }
        }
    }
}

static bool32 sub_8020320(void)
{
    if (sDisplay->bg1hofs < 56)
    {
        sDisplay->bg1hofs += 12;
        if (sDisplay->bg1hofs >= 56)
            sDisplay->bg1hofs = 56;

        if (sDisplay->bg1hofs < 56)
        {
            sub_80207C0(sDisplay->bg1hofs);
            return TRUE;
        }
    }

    sub_8020818(sDisplay->bg1hofs);
    return FALSE;
}

static bool32 sub_8020368(void)
{
    if (sDisplay->bg1hofs > 0)
    {
        sDisplay->bg1hofs -= 12;
        if (sDisplay->bg1hofs <= 0)
            sDisplay->bg1hofs = 0;

        if (sDisplay->bg1hofs > 0)
        {
            sub_80207C0(sDisplay->bg1hofs);
            return TRUE;
        }
    }

    sub_8020818(sDisplay->bg1hofs);
    return FALSE;
}

static void ShowKeyboardSwapMenu(void)
{
    FillWindowPixelBuffer(3, PIXEL_FILL(1));
    DrawTextBorderOuter(3, 1, 13);
    PrintTextArray(3, 2, 8, 1, 14, 5, sKeyboardPageTitleTexts);
    sub_81983AC(3, 2, 0, 1, 14, 5, GetCurrentKeyboardPage());
    PutWindowTilemap(3);
}

static void HideKeyboardSwapMenu(void)
{
    ClearStdWindowAndFrameToTransparent(3, FALSE);
    ClearWindowTilemap(3);
}

static void PrintChatMessage(u16 row, u8 *str, u8 colorIdx)
{
    // colorIdx: 0 = gray, 1 = red, 2 = green, 3 = blue
    u8 color[3];
    color[0] = TEXT_COLOR_WHITE;
    color[1] = colorIdx * 2 + 2;
    color[2] = colorIdx * 2 + 3;
    FillWindowPixelRect(0, PIXEL_FILL(1), 0, row * 15, 168, 15);
    AddTextPrinterParameterized3(0, 2, 0, row * 15 + 1, color, TEXT_SPEED_FF, str);
}

static void ResetGpuBgState(void)
{
    ChangeBgX(0, 0, 0);
    ChangeBgY(0, 0, 0);
    ChangeBgX(1, 0, 0);
    ChangeBgY(1, 0, 0);
    ChangeBgX(2, 0, 0);
    ChangeBgY(2, 0, 0);
    ChangeBgX(3, 0, 0);
    ChangeBgY(3, 0, 0);
    ShowBg(0);
    ShowBg(1);
    ShowBg(2);
    ShowBg(3);
    SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    ClearGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON | DISPCNT_WIN1_ON | DISPCNT_OBJWIN_ON);
    SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON);
    SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(64, DISPLAY_WIDTH));
    SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(0, DISPLAY_HEIGHT - 16));
    SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG0 | WININ_WIN0_BG2 | WININ_WIN0_BG3
                              | WININ_WIN0_OBJ | WININ_WIN0_CLR);
    SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_BG_ALL | WINOUT_WIN01_OBJ | WINOUT_WIN01_CLR);
}

static void SetBgTilemapBuffers(void)
{
    SetBgTilemapBuffer(0, sDisplay->bg0Buffer);
    SetBgTilemapBuffer(1, sDisplay->bg1Buffer);
    SetBgTilemapBuffer(3, sDisplay->bg3Buffer);
    SetBgTilemapBuffer(2, sDisplay->bg2Buffer);
}

static void ClearBg0(void)
{
    RequestDma3Fill(0, (void *)BG_CHAR_ADDR(0), 0x20, 1);
    FillBgTilemapBufferRect_Palette0(0, 0, 0, 0, 32, 32);
    CopyBgTilemapBufferToVram(0);
}

static void LoadChatWindowBorderGfx(void)
{
    LoadPalette(gUnionRoomChat_Window_Pal2, 0x70, 0x20);
    LoadPalette(gUnionRoomChat_Window_Pal1, 0xC0, 0x20);
    DecompressAndCopyTileDataToVram(1, gUnionRoomChat_Border_Gfx, 0, 0, 0);
    CopyToBgTilemapBuffer(1, gUnionRoomChat_Border_Tilemap, 0, 0);
    CopyBgTilemapBufferToVram(1);
}

static void LoadChatWindowGfx(void)
{
    u8 *ptr;

    LoadPalette(gUnionRoomChat_Background_Pal, 0, 0x20);
    ptr = DecompressAndCopyTileDataToVram(2, gUnionRoomChat_Background_Gfx, 0, 0, 0);
    if (ptr)
    {
        CpuFastCopy(&ptr[0x220], sDisplay->unk2128, 0x20);
        CpuFastCopy(&ptr[0x420], sDisplay->unk2148, 0x20);
    }

    CopyToBgTilemapBuffer(2, gUnionRoomChat_Background_Tilemap, 0, 0);
    CopyBgTilemapBufferToVram(2);
}

static void sub_8020680(void)
{
    LoadPalette(sUnk_Palette1, 0x80, 0x20);
    RequestDma3Fill(0, (void *)BG_CHAR_ADDR(1) + 0x20, 0x20, 1);
}

static void LoadChatMessagesWindow(void)
{
    LoadPalette(sUnk_Palette2, 0xF0, 0x20);
    PutWindowTilemap(0);
    FillWindowPixelBuffer(0, PIXEL_FILL(1));
    CopyWindowToVram(0, 3);
}

static void LoadKeyboardWindow(void)
{
    PutWindowTilemap(2);
    PrintCurrentKeyboardPage();
    CopyWindowToVram(2, 3);
}

static void LoadTextEntryWindow(void)
{
    int i;
    u8 unused[2];
    unused[0] = 0;
    unused[1] = 0xFF;

    for (i = 0; i < MAX_MESSAGE_LENGTH; i++)
        BlitBitmapToWindow(1, sDisplay->unk2128, i * 8, 0, 8, 16);

    FillWindowPixelBuffer(1, PIXEL_FILL(0));
    PutWindowTilemap(1);
    CopyWindowToVram(1, 3);
}

static void LoadKeyboardSwapWindow(void)
{
    FillWindowPixelBuffer(3, PIXEL_FILL(1));
    LoadUserWindowBorderGfx(3, 1, 0xD0);
    LoadUserWindowBorderGfx_(3, 0xA, 0x20);
    LoadPalette(gUnknown_0860F074, 0xE0,  0x20);
}

static void InitScanlineEffect(void)
{
    struct ScanlineEffectParams params;
    params.dmaControl = SCANLINE_EFFECT_DMACNT_16BIT;
    params.dmaDest = &REG_BG1HOFS;
    params.initState = 1;
    params.unused9 = 0;
    sDisplay->bg1hofs = 0;
    CpuFastFill(0, gScanlineEffectRegBuffers, sizeof(gScanlineEffectRegBuffers));
    ScanlineEffect_SetParams(params);
}

static void sub_80207C0(s16 bg1hofs)
{
    CpuFill16(bg1hofs, gScanlineEffectRegBuffers[gScanlineEffect.srcBuffer], 0x120);
    CpuFill16(0,       gScanlineEffectRegBuffers[gScanlineEffect.srcBuffer] + 0x90, 0x20);
}

static void sub_8020818(s16 bg1hofs)
{
    CpuFill16(bg1hofs, gScanlineEffectRegBuffers[0],         0x120);
    CpuFill16(0,       gScanlineEffectRegBuffers[0] +  0x90, 0x20);
    CpuFill16(bg1hofs, gScanlineEffectRegBuffers[0] + 0x3C0, 0x120);
    CpuFill16(0,       gScanlineEffectRegBuffers[0] + 0x450, 0x20);
}

static bool32 TryAllocSprites(void)
{
    u32 i;
    for (i = 0; i < ARRAY_COUNT(sSpriteSheets); i++)
        LoadCompressedSpriteSheet(&sSpriteSheets[i]);

    LoadSpritePalette(&sSpritePalette);
    sSprites = Alloc(sizeof(struct UnionRoomChatSprites));
    if (!sSprites)
        return FALSE;

    return TRUE;
}

static void FreeSprites(void)
{
    if (sSprites)
        Free(sSprites);
}

static void CreateKeyboardCursorSprite(void)
{
    u8 spriteId = CreateSprite(&sSpriteTemplate_KeyboardCursor, 10, 24, 0);
    sSprites->keyboardCursor = &gSprites[spriteId];
}

static void SetKeyboardCursorInvisibility(bool32 invisible)
{
    sSprites->keyboardCursor->invisible = invisible;
}

static void MoveKeyboardCursor(void)
{
    u8 x, y;
    u8 page = GetCurrentKeyboardPage();
    GetCurrentKeyboardColAndRow(&x, &y);
    if (page != UNION_ROOM_KB_PAGE_REGISTER)
    {
        StartSpriteAnim(sSprites->keyboardCursor, 0);
        sSprites->keyboardCursor->x = x * 8 + 10;
        sSprites->keyboardCursor->y = y * 12 + 24;
    }
    else
    {
        StartSpriteAnim(sSprites->keyboardCursor, 2);
        sSprites->keyboardCursor->x = 24;
        sSprites->keyboardCursor->y = y * 12 + 24;
    }
}

static void SetRegisteredTextPalette(bool32 registering)
{
    const u16 *palette = &sUnionRoomChatInterfacePal[registering * 2 + 1];
    u8 index = IndexOfSpritePaletteTag(0);
    LoadPalette(palette, index * 16 + 0x101, 4);
}

static void StartKeyboardCursorAnim(void)
{
    if (GetCurrentKeyboardPage() != UNION_ROOM_KB_PAGE_REGISTER)
        StartSpriteAnim(sSprites->keyboardCursor, 1);
    else
        StartSpriteAnim(sSprites->keyboardCursor, 3);

    sSprites->cursorBlinkTimer = 0;
}

static bool32 TryKeyboardCursorReopen(void)
{
    if (sSprites->cursorBlinkTimer > 3)
        return FALSE;

    if (++sSprites->cursorBlinkTimer > 3)
    {
        if (GetCurrentKeyboardPage() != UNION_ROOM_KB_PAGE_REGISTER)
            StartSpriteAnim(sSprites->keyboardCursor, 0);
        else
            StartSpriteAnim(sSprites->keyboardCursor, 2);

        return FALSE;
    }

    return TRUE;
}

static void CreateTextEntrySprites(void)
{
    u8 spriteId = CreateSprite(&sSpriteTemplate_TextEntryCursor, 76, 152, 2);
    sSprites->textEntryCursor = &gSprites[spriteId];
    spriteId = CreateSprite(&sSpriteTemplate_TextEntryArrow, 64, 152, 1);
    sSprites->textEntryArrow = &gSprites[spriteId];
}

static void SpriteCB_TextEntryCursor(struct Sprite *sprite)
{
    int pos = GetTextEntryCursorPosition();
    if (pos == MAX_MESSAGE_LENGTH)
    {
        sprite->invisible = TRUE;
    }
    else
    {
        sprite->invisible = FALSE;
        sprite->x = pos * 8 + 76;
    }
}

static void SpriteCB_TextEntryArrow(struct Sprite *sprite)
{
    if (++sprite->data[0] > 4)
    {
        sprite->data[0] = 0;
        if (++sprite->x2 > 4)
            sprite->x2 = 0;
    }
}

static void CreateRButtonSprites(void)
{
    u8 spriteId = CreateSprite(&sSpriteTemplate_RButtonIcon, 8, 152, 3);
    sSprites->rButtonIcon = &gSprites[spriteId];
    spriteId = CreateSprite(&sSpriteTemplate_RButtonLabels, 32, 152, 4);
    sSprites->rButtonLabel = &gSprites[spriteId];
    sSprites->rButtonLabel->invisible = TRUE;
}

static void UpdateRButtonLabel(void)
{
    if (GetCurrentKeyboardPage() == UNION_ROOM_KB_PAGE_REGISTER)
    {
        if (GetLengthOfMessageEntry() != 0)
        {
            // REGISTER
            sSprites->rButtonLabel->invisible = FALSE;
            StartSpriteAnim(sSprites->rButtonLabel, 3);
        }
        else
        {
            sSprites->rButtonLabel->invisible = TRUE;
        }
    }
    else
    {
        int anim = GetShouldShowCaseToggleIcon();
        if (anim == 3)
        {
            sSprites->rButtonLabel->invisible = TRUE;
        }
        else
        {
            // A <--> a (toggle case)
            sSprites->rButtonLabel->invisible = FALSE;
            StartSpriteAnim(sSprites->rButtonLabel, anim);
        }
    }

}
