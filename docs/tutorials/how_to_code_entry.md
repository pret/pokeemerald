## How to use the code entry system

This system involves using the `EnterCode` special to prompt the player to enter a text string, and then the `GetCodeFeedback` special to perform some function based on the string entered. Using this system to make your own cheat codes or mystery gifts will involve both scripting and editing the `GetCodeFeedback` function itself to include your new functionality, and may involve further changes to the codebase if you want to implement something more far reaching (ie. a grindrunning mode).

This tutorial will use the example of entering the string "CaughtEmAll" to flag every Pokemon as caught

### 1. Choose where to initiaze your event scripting

This can be anywhere or anything, pre-existing or added by you in porymap. I usually like using signs for testing things but this can be anything. I'm going to give the main script a more generic name, and you can attach it to whatever object you like.

In that object's event script, add the following:
```diff
EventScript_CodeEntry::
    special EnterCode
    waitstate
    special GetCodeFeedback
    end
```

This will prompt text entry from the object and prepare it to handle reading the entered text after it's been entered, but it won't do anything yet. Next we need to add our functionality to `GetCodeFeedback`.

### 2. Add code string and code function to `GetCodeFeedback`

You can find `GetCodeFeedback` in `src/field_specials.c`. Let's start by taking a look at the function:
```
void GetCodeFeedback(void)
{
    static const u8 sText_SampleCode[] = _("SampleCode");
    if (!StringCompare(gStringVar2, sText_SampleCode))
        gSpecialVar_Result = 1;
    else
        gSpecialVar_Result = 0;
}
```

What this function does is compare the input string (`gStringVar2`) against a specified string (`sText_SampleCode`) and returns a value depending on whether the strings matched (`gSpecialVar_Result`). Note that due to the way `StringCompare` works, the comparison does need to be negated with `!`. By default, this sample setup returns 1 when the string "SampleCode" is entered by the player.

Let's leave that functionality alone in case we ever want to reference it again, and just add a brand new code instead. We want to use the string "CaughtEmAll" as our code, so we'll start by making a string for it, and a new conditional that checks if the entered string matches. We'll also want to make sure we return a new unique number for `gSpecialVar_Result` so our event script knows what happened.

```diff
void GetCodeFeedback(void)
{
    static const u8 sText_SampleCode[] = _("SampleCode");
+   static const u8 sText_CaughtEmAll_[] = _("CaughtEmAll"); // Mark entire Pokedex as caught
    if (!StringCompare(gStringVar2, sText_SampleCode))
        gSpecialVar_Result = 1;
+   else if (!StringCompare(gStringVar2, sText_CaughtEmAll))
+   {
+       // TODO
+       gSpecialVar_Result = 2;
+   }
    else
        gSpecialVar_Result = 0;
}
```

Great! Now we have a new case to handle our new code, but it still doesn't do anything. This is the part that will change dramatically depending on what you want to do, and you can do anything you want, from setting flags to calling other functions or anything else! Just make sure you do it from within the conditional that matches your code. In our case we want to iterate through the Pokedex to mark everything as caught, which I'll just do here for simplicity.

```diff
void GetCodeFeedback(void)
{
    static const u8 sText_SampleCode[] = _("SampleCode");
    static const u8 sText_CaughtEmAll_[] = _("CaughtEmAll"); // Mark entire Pokedex as caught
    if (!StringCompare(gStringVar2, sText_SampleCode))
        gSpecialVar_Result = 1;
    else if (!StringCompare(gStringVar2, sText_CaughtEmAll))
    {
+       u32 i;
+       for (i = 0; i < NATIONAL_DEX_COUNT; i++)
+       {
+           GetSetPokedexFlag(i + 1, FLAG_SET_CAUGHT);
+       }
        gSpecialVar_Result = 2;
    }
    else
        gSpecialVar_Result = 0;
}
```

Awesome! Now our `GetCodeFeedback` function performs the task we want it to, and returns a 2 to our event script so it can handle the situation appropriately. That's our next and final step!

### 3. Handle new `GetCodeFeedback` case in event script

To clarify, this step is *optional*. You don't need to do anything else after `GetCodeFeedback` has run if you don't want to, as all the functionality is there; once that function finishes, everything in the Pokedex will be marked as caught.

The reason we might want to do this step, and the reason we pass results back to the event script in the first place, is so we can handle providing the player with some dialogue based on what they're doing.

Let's go back to our event script.

```
EventScript_CodeEntry::
    special EnterCode
    waitstate
    special GetCodeFeedback
    end
```

Maybe we first want to prompt the player with a message that says something like "Enter a code?"

```diff
EventScript_CodeEntry::
+   lockall
+   msgbox EnterCode_EnterCodeText, MSGBOX_YESNO
+   compare VAR_RESULT, 0
+   goto_if_eq CodeExit
    special EnterCode
    waitstate
    special GetCodeFeedback
    end

+CodeExit::
+   releaseall
+   end
+
+EnterCode_EnterCodeText:
+   .string "Enter a code?$"
```

This is all straightforward scripting stuff, the sign will first give the player a YES / NO box and ask whether they'd like to enter a code. Let's now add some cases and messages that handle the different results of the code entry from `GetCodeFeedback`. Let's look at the sign first:

```diff
EventScript_CodeEntry::
	lockall
	msgbox EnterCode_EnterCodeText, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq CodeExit
    special EnterCode
    waitstate
    special GetCodeFeedback
+   goto_if_eq VAR_RESULT, 0, CodeFailed
+   goto_if_eq VAR_RESULT, 1, CodeSampleCode
+   goto_if_eq VAR_RESULT, 2, CodeCaughtEmAll
	end
```

Now we're handling cases for each of the possible return values from `GetCodeFeedback`! except we don't have any of those functions, so this will cause errors as the script has nothing to `goto_if_eq`. Let's write those too:

```diff
CodeFailed::
    msgbox EnterCode_FailedText, MSGBOX_DEFAULT
    releaseall
    end

CodeSampleString::
    msgbox EnterCode_SucceededText, MSGBOX_DEFAULT
    msgbox CodeSampleCode_Text, MSGBOX_DEFAULT
    releaseall
    end

CodeCaughtEmAll::
    msgbox EnterCode_SucceededText, MSGBOX_DEFAULT
    msgbox CodeCaughtEmAll_Text, MSGBOX_DEFAULT
    releaseall
    end
```

And lastly, we'll need to add all of the strings we now need to reference:

```
EnterCode_FailedText:
    .string "...nothing happened.$"

EnterCode_SucceededText:
    .string "The code worked!$"

CodeSampleCode_Text
    .string "You entered the sample code!$"

CodeCaughtEmAll_Text
    .string "Encyclopedic knowledge fills your head.\n"
    .string "It's like you've caught 'em all!$"
```

So to finish up, our event script file now looks like this, with all said and done:

```
EventScript_CodeEntry::
    lockall
    msgbox EnterCode_EnterCodeText, MSGBOX_YESNO
    compare VAR_RESULT, 0
    goto_if_eq CodeExit
    special EnterCode
    waitstate
    special GetCodeFeedback
    goto_if_eq VAR_RESULT, 0, CodeFailed
    goto_if_eq VAR_RESULT, 1, CodeSampleCode
    goto_if_eq VAR_RESULT, 2, CodeCaughtEmAll
	end

CodeExit::
    releaseall
    end

CodeFailed::
    msgbox EnterCode_FailedText, MSGBOX_DEFAULT
    releaseall
    end

CodeSampleString::
    msgbox EnterCode_SucceededText, MSGBOX_DEFAULT
    msgbox CodeSampleCode_Text, MSGBOX_DEFAULT
    releaseall
    end

CodeCaughtEmAll::
    msgbox EnterCode_SucceededText, MSGBOX_DEFAULT
    msgbox CodeCaughtEmAll_Text, MSGBOX_DEFAULT
    releaseall
    end

EnterCode_EnterCodeText:
    .string "Enter a code?$"

EnterCode_FailedText:
    .string "...nothing happened.$"

EnterCode_SucceededText:
    .string "The code worked!$"

CodeSampleCode_Text
    .string "You entered the sample code!$"

CodeCaughtEmAll_Text
    .string "Encyclopedic knowledge fills your head.\n"
    .string "It's like you've caught 'em all!$"

```

And that's it! Feel free to expand this in whatever way you wish, the pattern can just be repeated as much as you like, and you can made the code called from `GetCodeFeedback` do whatever you like.

## Can I change the icon on the name entry screen?

Absolutely! In `naming_screen.c`, look for the `NamingScreen_CreateCodeIcon` function. It's very short. There's one relevant line that needs to be changed:

```
spriteId = CreateObjectGraphicsSprite(OBJ_EVENT_GFX_MYSTERY_GIFT_MAN, SpriteCallbackDummy, 56, 37, 0);
```

Just swap out `OBJ_EVENT_GFX_MYSTERY_GIFT_MAN` for whatever event object sprite you'd like to use instead. You may need to adjust the position (the 56 and 37 in this example) depending on your sprite.

## What about a mystery gift setup?

I'd like to cover this separately because it's best handled via `givemon` script commands, which means we don't do much in `GetCodeFeedback` other than return a unique identifier. I'm gonna reference @PCG06's mystery gift implementation which is based on this code entry system for a clean and really thorough example.

### 3. Mystery Gift `GetCodeFeedback`

Let's say you have two mystery gift mons and no other cases you want to handle, one for Celebi and one for Jirachi. Your `GetCodeFeedback` function will look something like this:

```
{
    static const u8 sText_CodeCelebi[] = _("Celebi");
    static const u8 sText_CodeJirachi[] = _("Jirachi");
    if (!StringCompare(gStringVar2, sText_CodeCelebi))
        gSpecialVar_Result = 1;
    else if (!StringCompare(gStringVar2, sText_CodeJirachi))
        gSpecialVar_Result = 2;
    else
        gSpecialVar_Result = 0;
}
```
and that's it, super simple. All of the other handling will have to be done on the scripting end, as we'll be leaning on `givemon` and its associated handling.

### 2. Mystery Gift Scripting

Let's return back to our EventScript_CodeEntry pattern from before, but instead use our new codes.

```
EventScript_CodeEntry::
	lockall
	msgbox EnterCode_EnterCodeText, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq CodeExit
    special EnterCode
    waitstate
    special GetCodeFeedback
    goto_if_eq VAR_RESULT, 0, CodeFailed
    goto_if_eq VAR_RESULT, 1, MysteryGift_EventScript_Celebi
    goto_if_eq VAR_RESULT, 2, MysteryGift_EventScript_Jirachi
	end
```

Straightforward enough! The actual work is in writing `MysteryGift_EventScript_Celebi` and `MysteryGift_EventScript_Jirachi` to handle their givemons appropriately, prompt nicknaming, send them to the PC if the party is full, etc. We should also keep in mind that each Mystery Gift should only be entered once, so we'll want to track that with a flag; conveniently, expansion already has 15 flags we can use for the purpose. Let's do Celebi first.

```
MysteryGift_EventScript_Celebi::
	goto_if_set FLAG_MYSTERY_GIFT_1, MysteryGift_EventScript_Redeemed
	bufferspeciesname STR_VAR_1, SPECIES_CELEBI
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_CELEBI
	givemon SPECIES_CELEBI, 100, ITEM_LIFE_ORB, ITEM_CHERISH_BALL, NATURE_TIMID, 0, MON_GENDERLESS, 0, 0, 4, 252, 252, 0, 31, 31, 31, 30, 31, 31, MOVE_ENERGY_BALL, MOVE_PSYCHIC, MOVE_NASTY_PLOT, MOVE_CELEBRATE, TRUE, FALSE, TYPE_PSYCHIC
	setflag FLAG_MYSTERY_GIFT_1
	call MysteryGift_EventScript_ReceivedMon
	releaseall
	end
```

Walking through this, it's clear we'll need some more scripting. We first check if Celebi's corresponding Mystery Gift flag has been set, and if it has, we need to tell the player they've already redeemed it and can't again. If they haven't though, we get ourselves setup for the givemon, do the givemon, and set the mystery gift flag. Then we need soem more generic handling to prompt nicknaming and some fanfare.

Two things, then; an event script to handle the case where a mystery gift mon has already been redeemed, and an event script to handle when a mystery gift mon has successfully been received.

Just for the sake of simplicity, I'm going to handle entering a used mystery gift code the same way I'd handle an incorrect code. You're welcome to add more complex scripting if you prefer.

```
MysteryGift_EventScript_Redeemed::
    msgbox EnterCode_FailedText, MSGBOX_DEFAULT
	releaseall
	end
```

And then the scripto handle the player having successfully received a mon:

```
MysteryGift_EventScript_ReceivedMon::
	msgbox MysteryGift_Text_SucceededText, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message MysteryGift_Text_ReceivedGiftMon
	waitfanfare
    goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, MysteryGift_EventScript_NicknamePartyMon
    goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, MysteryGift_EventScript_NicknamePCMon
	goto Common_EventScript_NoMoreRoomForPokemon
	msgbox MysteryGift_Text_PleaseVisitAgain, MSGBOX_DEFAULT
	end
```

Almost done! Just need to handle the specific nicknaming scripts, and then add all of the text.

```
MysteryGift_EventScript_NicknamePartyMon::
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MysteryGift_EventScript_Exit
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto MysteryGift_EventScript_Exit
	end

MysteryGift_EventScript_NicknamePCMon::
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MysteryGift_EventScript_TransferredToPC
	call Common_EventScript_NameReceivedBoxMon
	call Common_EventScript_TransferredToPC
	releaseall
	end

MysteryGift_EventScript_TransferredToPC::
	call Common_EventScript_TransferredToPC
	releaseall
	end

MysteryGift_Text_WelcomeToMysteryGiftSystem:
	.string "Hello, {PLAYER}!\p"
	.string "Welcome to the Mystery Gift System!\p"
	.string "Would you like to enter a code?$"

MysteryGift_Text_CurrentlyUnavailable:
	.string "I'm sorry, but the Mystery Gift System\n"
	.string "is currently unavailable.\p"
	.string "Please try again later.\p"
	.string "Thank you!$"

MysteryGift_Text_PleaseVisitAgain:
	.string "Please visit again!$"

MysteryGift_Text_EnterCode:
	.string "Please enter the code.$"

MysteryGift_Text_SucceededText:
	.string "The code was valid!\p"
	.string "Enjoy your gift!$"

MysteryGift_Text_FailedText:
	.string "The code was invalid!\p"
	.string "Would you like to enter a new code?$"

MysteryGift_Text_RedeemedText:
	.string "This code was already redeemed!\p"
	.string "Would you like you enter a new code?$"

MysteryGift_Text_ReceivedGiftMon:
	.string "{PLAYER} received a {STR_VAR_1}!$"
```

Goodness, so much infrastructure scripting! The nice thing is that now that all the infrastructure is set up, much like before, adding new cases becomes really straightforward. With Celebi and all of the skeleton scripting finished, let's add Jirachi.

```
MysteryGift_EventScript_Jirachi::
	goto_if_set FLAG_MYSTERY_GIFT_2, MysteryGift_EventScript_Redeemed
	bufferspeciesname STR_VAR_1, SPECIES_JIRACHI
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_JIRACHI
	givemon SPECIES_JIRACHI, 100, ITEM_LIFE_ORB, ITEM_CHERISH_BALL, NATURE_ADAMANT, 0, MON_GENDERLESS, 0, 252, 4, 252, 0, 0, 31, 31, 31, 31, 31, 31, MOVE_IRON_HEAD, MOVE_ZEN_HEADBUTT, MOVE_PLAY_ROUGH, MOVE_CELEBRATE, TRUE, FALSE, TYPE_STEEL
	setflag FLAG_MYSTERY_GIFT_2
	call MysteryGift_EventScript_ReceivedMon
	releaseall
	end
```

And that's it! Super straightforward from here, just make sure to iterate `FLAG_MYSTERY_GIFT` each time you add a new mon, and of course add their code to both `GetCodeFeedback` and the main script controlling code entry.
