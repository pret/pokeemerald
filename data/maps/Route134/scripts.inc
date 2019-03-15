Route134_MapScripts:: @ 81F7644
	map_script MAP_SCRIPT_ON_RESUME, Route134_MapScript1_1F764A
	.byte 0

Route134_MapScript1_1F764A: @ 81F764A
	setdivewarp MAP_UNDERWATER_ROUTE134, 255, 8, 6
	end

Route134_EventScript_1F7653:: @ 81F7653
	trainerbattle_single TRAINER_JACK, Route134_Text_2A4571, Route134_Text_2A45BB
	msgbox Route134_Text_2A45C5, MSGBOX_AUTOCLOSE
	end

Route134_EventScript_1F766A:: @ 81F766A
	trainerbattle_single TRAINER_LAUREL, Route134_Text_2A4609, Route134_Text_2A4643
	msgbox Route134_Text_2A464B, MSGBOX_AUTOCLOSE
	end

Route134_EventScript_1F7681:: @ 81F7681
	trainerbattle_single TRAINER_ALEX, Route134_Text_2A4682, Route134_Text_2A46BE
	msgbox Route134_Text_2A46D2, MSGBOX_AUTOCLOSE
	end

Route134_EventScript_1F7698:: @ 81F7698
	trainerbattle_single TRAINER_AARON, Route134_Text_2A479E, Route134_Text_2A47E1
	msgbox Route134_Text_2A47FD, MSGBOX_AUTOCLOSE
	end

Route134_EventScript_1F76AF:: @ 81F76AF
	trainerbattle_single TRAINER_HITOSHI, Route134_Text_2A4709, Route134_Text_2A4745
	msgbox Route134_Text_2A475D, MSGBOX_AUTOCLOSE
	end

Route134_EventScript_1F76C6:: @ 81F76C6
	trainerbattle_single TRAINER_HUDSON, Route134_Text_2A4A8F, Route134_Text_2A4AC1
	msgbox Route134_Text_2A4AD8, MSGBOX_AUTOCLOSE
	end

Route134_EventScript_1F76DD:: @ 81F76DD
	trainerbattle_single TRAINER_REYNA, Route134_Text_2A49E9, Route134_Text_2A4A10
	msgbox Route134_Text_2A4A34, MSGBOX_AUTOCLOSE
	end

Route134_EventScript_1F76F4:: @ 81F76F4
	trainerbattle_single TRAINER_MARLEY, Route134_Text_2A4937, Route134_Text_2A496B
	msgbox Route134_Text_2A49B1, MSGBOX_AUTOCLOSE
	end

Route134_EventScript_1F770B:: @ 81F770B
	trainerbattle_single TRAINER_KELVIN, Route134_Text_2A4875, Route134_Text_2A489B
	msgbox Route134_Text_2A48BD, MSGBOX_AUTOCLOSE
	end

