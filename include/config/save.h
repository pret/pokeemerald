#ifndef GUARD_CONFIG_SAVE_H
#define GUARD_CONFIG_SAVE_H

// free saveblock 1 defines
#define FREE_EXTRA_SEEN_FLAGS               FALSE   // Free up unused Pokédex seen flags (52 bytes).
#define FREE_TRAINER_HILL                   FALSE   // Frees up Trainer Hill data (28 bytes). WARNING THIS HAS BEEN SHOWN TO BREAK MULTI BATTLES
#define FREE_MYSTERY_EVENT_BUFFERS          FALSE   //frees up mystery event and ramScript. roughly 1880 bytes       Needs FREE_BATTLE_TOWER_E_READER
#define FREE_MATCH_CALL                     FALSE   // Frees up match call and rematch data. (104 bytes).
#define FREE_UNION_ROOM_CHAT                FALSE   // Frees up union room chat (212 bytes).
#define FREE_ENIGMA_BERRY                   FALSE   // Frees up E-Reader Enigma Berry data (52 bytes).
#define FREE_LINK_BATTLE_RECORDS            FALSE   // Frees up link battle record data (88 bytes).
                                            // saveblock1 total: 1846 bytes
//free saveblock 2 defines
#define FREE_BATTLE_TOWER_E_READER          FALSE   // Frees up Battle Tower E-Reader data (188 bytes). WARNING THIS HAS BEEN SHOWN TO BREAK THE POKÉ MARTS' QUESTIONNAIRE
#define FREE_POKEMON_JUMP                   FALSE   // Frees up Pokémon Jump data (16 bytes).
#define FREE_RECORD_MIXING_HALL_RECORDS     FALSE   // Frees up hall records for record mixing (1032 bytes).
                                        // saveblock2 total: 1236 bytes

                                        //grand total: 3082

#if (FREE_MYSTERY_EVENT_BUFFERS == TRUE) && (FREE_BATTLE_TOWER_E_READER == FALSE)
#error "FREE_BATTLE_TOWER_E_READER must be enabled for FREE_MYSTERY_EVENT_BUFFERS to work"
#endif

#endif // GUARD_CONFIG_DECAP_H
