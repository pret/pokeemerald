Route134_MapScripts:: @ 81F7644
	map_script 5, Route134_MapScript1_1F764A
	.byte 0

Route134_MapScript1_1F764A: @ 81F764A
	setdivewarp UNDERWATER_ROUTE_134, 255, 8, 6
	end

Route134_EventScript_1F7653:: @ 81F7653
	trainerbattle 0, TRAINER_JACK, 0, Route134_Text_2A4571, Route134_Text_2A45BB
	msgbox Route134_Text_2A45C5, 6
	end

Route134_EventScript_1F766A:: @ 81F766A
	trainerbattle 0, TRAINER_LAUREL, 0, Route134_Text_2A4609, Route134_Text_2A4643
	msgbox Route134_Text_2A464B, 6
	end

Route134_EventScript_1F7681:: @ 81F7681
	trainerbattle 0, TRAINER_ALEX, 0, Route134_Text_2A4682, Route134_Text_2A46BE
	msgbox Route134_Text_2A46D2, 6
	end

Route134_EventScript_1F7698:: @ 81F7698
	trainerbattle 0, TRAINER_AARON, 0, Route134_Text_2A479E, Route134_Text_2A47E1
	msgbox Route134_Text_2A47FD, 6
	end

Route134_EventScript_1F76AF:: @ 81F76AF
	trainerbattle 0, TRAINER_HITOSHI, 0, Route134_Text_2A4709, Route134_Text_2A4745
	msgbox Route134_Text_2A475D, 6
	end

Route134_EventScript_1F76C6:: @ 81F76C6
	trainerbattle 0, TRAINER_HUDSON, 0, Route134_Text_2A4A8F, Route134_Text_2A4AC1
	msgbox Route134_Text_2A4AD8, 6
	end

Route134_EventScript_1F76DD:: @ 81F76DD
	trainerbattle 0, TRAINER_REYNA, 0, Route134_Text_2A49E9, Route134_Text_2A4A10
	msgbox Route134_Text_2A4A34, 6
	end

Route134_EventScript_1F76F4:: @ 81F76F4
	trainerbattle 0, TRAINER_MARLEY, 0, Route134_Text_2A4937, Route134_Text_2A496B
	msgbox Route134_Text_2A49B1, 6
	end

Route134_EventScript_1F770B:: @ 81F770B
	trainerbattle 0, TRAINER_KELVIN, 0, Route134_Text_2A4875, Route134_Text_2A489B
	msgbox Route134_Text_2A48BD, 6
	end

