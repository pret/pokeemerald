	.section script_data, "aw", %progbits

	.align 2
gMysteryEventScriptCmdTable:: @ 82DED2C
	.4byte MEScrCmd_nop
	.4byte MEScrCmd_checkcompat
	.4byte MEScrCmd_end
	.4byte MEScrCmd_setmsg
	.4byte MEScrCmd_setstatus
	.4byte MEScrCmd_runscript
	.4byte MEScrCmd_initramscript
	.4byte MEScrCmd_setenigmaberry
	.4byte MEScrCmd_giveribbon
	.4byte MEScrCmd_givenationaldex
	.4byte MEScrCmd_addrareword
	.4byte MEScrCmd_setrecordmixinggift
	.4byte MEScrCmd_givepokemon
	.4byte MEScrCmd_addtrainer
	.4byte MEScrCmd_enableresetrtc
	.4byte MEScrCmd_checksum
	.4byte MEScrCmd_crc
gMysteryEventScriptCmdTableEnd::
