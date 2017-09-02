	.align 2
sRtcDummy:: @ 82FECC0
	.byte 0 @ year
	.byte 1 @ month
	.byte 1 @ day of month
	.byte 0 @ day of week
	.byte 0 @ hour
	.byte 0 @ minute
	.byte 0 @ second
	.byte 0 @ control register value
	.byte 0 @ unknown 1
	.byte 0 @ unknown 2
	.2byte 0 @ padding

	.align 2
sNumDaysInMonths:: @ 82FECCC
	.4byte 31 @ January
	.4byte 28 @ February
	.4byte 31 @ March
	.4byte 30 @ April
	.4byte 31 @ May
	.4byte 30 @ June
	.4byte 31 @ July
	.4byte 31 @ August
	.4byte 30 @ September
	.4byte 31 @ October
	.4byte 30 @ November
	.4byte 31 @ December
