Route104_PrettyPetalFlowerShop_MapScripts:: @ 822A34C
	map_script MAP_SCRIPT_ON_TRANSITION, Route104_PrettyPetalFlowerShop_OnTransition
	.byte 0

Route104_PrettyPetalFlowerShop_OnTransition: @ 822A352
	setflag FLAG_LANDMARK_FLOWER_SHOP
	goto_if_unset FLAG_MET_PRETTY_PETAL_SHOP_OWNER, Route104_PrettyPetalFlowerShop_EventScript_22A36B
	goto_if_unset FLAG_BADGE03_GET, Route104_PrettyPetalFlowerShop_EventScript_22A36B
	setflag FLAG_TEMP_1
	end

Route104_PrettyPetalFlowerShop_EventScript_22A36B:: @ 822A36B
	setobjectxyperm 1, 4, 6
	end

Route104_PrettyPetalFlowerShop_EventScript_22A373:: @ 822A373
	lock
	faceplayer
	goto_if_set FLAG_TEMP_1, Route104_PrettyPetalFlowerShop_EventScript_22A3E4
	msgbox Route104_PrettyPetalFlowerShop_Text_2A7686, MSGBOX_DEFAULT
	goto_if_set FLAG_MET_PRETTY_PETAL_SHOP_OWNER, Route104_PrettyPetalFlowerShop_EventScript_22A3B2
	setflag FLAG_MET_PRETTY_PETAL_SHOP_OWNER
	msgbox Route104_PrettyPetalFlowerShop_Text_2A7706, MSGBOX_YESNO
	compare VAR_RESULT, 1
	call_if_eq Route104_PrettyPetalFlowerShop_EventScript_22A3D2
	compare VAR_RESULT, 0
	call_if_eq Route104_PrettyPetalFlowerShop_EventScript_22A3DB
	release
	end

Route104_PrettyPetalFlowerShop_EventScript_22A3B2:: @ 822A3B2
	msgbox Route104_PrettyPetalFlowerShop_Text_2A76D9, MSGBOX_YESNO
	compare VAR_RESULT, 1
	call_if_eq Route104_PrettyPetalFlowerShop_EventScript_22A3D2
	compare VAR_RESULT, 0
	call_if_eq Route104_PrettyPetalFlowerShop_EventScript_22A3DB
	release
	end

Route104_PrettyPetalFlowerShop_EventScript_22A3D2:: @ 822A3D2
	msgbox Route104_PrettyPetalFlowerShop_Text_2A775B, MSGBOX_DEFAULT
	return

Route104_PrettyPetalFlowerShop_EventScript_22A3DB:: @ 822A3DB
	msgbox Route104_PrettyPetalFlowerShop_Text_2A78DF, MSGBOX_DEFAULT
	return

Route104_PrettyPetalFlowerShop_EventScript_22A3E4:: @ 822A3E4
	message gUnknown_08272A52
	waitmessage
	pokemartdecoration2 Route104_PrettyPetalFlowerShop_Pokemart_Plants
	msgbox gUnknown_08272A3F, MSGBOX_DEFAULT
	release
	end

	.align 2
Route104_PrettyPetalFlowerShop_Pokemart_Plants: @ 822A3FC
	.2byte DECOR_RED_PLANT
	.2byte DECOR_TROPICAL_PLANT
	.2byte DECOR_PRETTY_FLOWERS
	.2byte DECOR_COLORFUL_PLANT
	.2byte DECOR_BIG_PLANT
	.2byte DECOR_GORGEOUS_PLANT
	.2byte DECOR_NONE
	release
	end

Route104_PrettyPetalFlowerShop_EventScript_22A40C:: @ 822A40C
	lock
	faceplayer
	goto_if_unset FLAG_RECEIVED_WAILMER_PAIL, Route104_PrettyPetalFlowerShop_EventScript_22A421
	msgbox Route104_PrettyPetalFlowerShop_Text_2A79A6, MSGBOX_DEFAULT
	release
	end

Route104_PrettyPetalFlowerShop_EventScript_22A421:: @ 822A421
	msgbox Route104_PrettyPetalFlowerShop_Text_2A7916, MSGBOX_DEFAULT
	giveitem_std ITEM_WAILMER_PAIL
	msgbox Route104_PrettyPetalFlowerShop_Text_2A79A6, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_WAILMER_PAIL
	release
	end

Route104_PrettyPetalFlowerShop_EventScript_22A442:: @ 822A442
	lock
	faceplayer
	dotimebasedevents
	goto_if_set FLAG_DAILY_FLOWER_SHOP_RECEIVED_BERRY, Route104_PrettyPetalFlowerShop_EventScript_22A482
	msgbox Route104_PrettyPetalFlowerShop_Text_2A7A98, MSGBOX_DEFAULT
	random 8
	addvar VAR_RESULT, 133
	giveitem_std VAR_RESULT
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_FLOWER_SHOP_RECEIVED_BERRY
	msgbox Route104_PrettyPetalFlowerShop_Text_2A7AF3, MSGBOX_DEFAULT
	release
	end

Route104_PrettyPetalFlowerShop_EventScript_22A482:: @ 822A482
	msgbox Route104_PrettyPetalFlowerShop_Text_2A7AF3, MSGBOX_DEFAULT
	release
	end
