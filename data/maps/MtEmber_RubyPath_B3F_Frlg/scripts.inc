MtEmber_RubyPath_B3F_Frlg_MapScripts::
	.byte 0

@ Odd that this is here and not in MtEmber_RubyPath_B5F/scripts.inc
MtEmber_RubyPath_B5F_EventScript_Ruby::
	lock
	faceplayer
	setflag FLAG_GOT_RUBY
	removeobject LOCALID_RUBY
	giveitem_msg MtEmber_RubyPath_B3F_Text_FoundARuby, ITEM_RUBY, 1, MUS_RG_OBTAIN_KEY_ITEM
	release
	end

MtEmber_RubyPath_B3F_Text_FoundARuby::
	.string "{PLAYER} found a RUBY!$"

