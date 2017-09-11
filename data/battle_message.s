	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata


.string "{STRING 36}$"
.string "{STRING 0} gained{PLAYER}\n{STRING 52} EXP. Points!\p$"
.string "$"
.string " a boosted$"
.string "{STRING 0} grew to\nLV. {PLAYER}!{UNKNOWN_A}\p$"
.string "{STRING 0} learned\n{PLAYER}!{UNKNOWN_A}\p$"
.string "{STRING 0} is trying to\nlearn {PLAYER}.\p$"
.string "But, {STRING 0} can’t learn\nmore than four moves.\p$"
.string "Delete a move to make\nroom for {PLAYER}?$"
.string "{STRING 0} forgot\n{PLAYER}.\p$"
.string "{PAUSE 32}Stop learning\n{PLAYER}?$"
.string "{STRING 0} did not learn\n{PLAYER}.\p$"
.string "Use next POKéMON?$"
.string "{STRING 15}’s\nattack missed!$"
.string "{STRING 16}\nprotected itself!$"
.string "{STRING 16} avoided\ndamage with {STRING 25}!$"
.string "{STRING 16} makes GROUND\nmoves miss with {STRING 25}!$"
.string "{STRING 16} avoided\nthe attack!$"
.string "It doesn’t affect\n{STRING 16}‥$"
.string "{STRING 15}\nfainted!\p$"
.string "{STRING 16}\nfainted!\p$"
.string "{STRING 35} got ¥{STRING 0}\nfor winning!\p$"
.string "{STRING 35} is out of\nusable POKéMON!\p$"
.string "{STRING 35} whited out!{PAUSE_UNTIL_PRESS}$"
.string "{STRING 19} prevents\nescape with {STRING 26}!\p$"
.string "Can’t escape!\p$"
.string "{STRING 15} can’t escape!$"
.string "Hit {STRING 0} time(s)!$"
.string "{STRING 17}\nfell asleep!$"
.string "{STRING 19}’s {STRING 26}\nmade {STRING 17} sleep!$"
.string "{STRING 16} is\nalready asleep!$"
.string "{STRING 15} is\nalready asleep!$"
.string "{STRING 16}\nwasn’t affected!$"
.string "{STRING 17}\nwas poisoned!$"
.string "{STRING 19}’s {STRING 26}\npoisoned {STRING 17}!$"
.string "{STRING 15} is hurt\nby poison!$"
.string "{STRING 16} is already\npoisoned.$"
.string "{STRING 17} is badly\npoisoned!$"
.string "{STRING 16} had its\nenergy drained!$"
.string "{STRING 17} was burned!$"
.string "{STRING 19}’s {STRING 26}\nburned {STRING 17}!$"
.string "{STRING 15} is hurt\nby its burn!$"
.string "{STRING 16} already\nhas a burn.$"
.string "{STRING 17} was\nfrozen solid!$"
.string "{STRING 19}’s {STRING 26}\nfroze {STRING 17} solid!$"
.string "{STRING 15} is\nfrozen solid!$"
.string "{STRING 16} was\ndefrosted!$"
.string "{STRING 15} was\ndefrosted!$"
.string "{STRING 15} was\ndefrosted by {STRING 20}!$"
.string "{STRING 17} is paralyzed!\nIt may be unable to move!$"
.string "{STRING 19}’s {STRING 26}\nparalyzed {STRING 17}!\lIt may be unable to move!$"
.string "{STRING 15} is paralyzed!\nIt can’t move!$"
.string "{STRING 16} is\nalready paralyzed!$"
.string "{STRING 16} was\nhealed of paralysis!$"
.string "{STRING 16}’s\ndream was eaten!$"
.string "{STRING 15}’s {STRING 0}\nwon’t go higher!$"
.string "{STRING 16}’s {STRING 0}\nwon’t go lower!$"
.string "Your team’s {STRING 0}\nstopped working!$"
.string "The foe’s {STRING 0}\nstopped working!$"
.string "{STRING 15} is\nconfused!$"
.string "{STRING 15} snapped\nout of confusion!$"
.string "{STRING 17} became\nconfused!$"
.string "{STRING 16} is\nalready confused!$"
.string "{STRING 16}\nfell in love!$"
.string "{STRING 15} is in love\nwith {STRING 19}!$"
.string "{STRING 15} is\nimmobilized by love!$"
.string "{STRING 16} was\nblown away!$"
.string "{STRING 15} transformed\ninto the {STRING 0} type!$"
.string "{STRING 15} flinched!$"
.string "{STRING 16} regained\nhealth!$"
.string "{STRING 16}’s\nHP is full!$"
.string "{STRING 42}’s {STRING 20}\nraised SP. DEF!$"
.string "{STRING 42}’s {STRING 20}\nraised SP. DEF a little!$"
.string "{STRING 42}’s {STRING 20}\nraised DEFENSE!$"
.string "{STRING 42}’s {STRING 20}\nraised DEFENSE a little!$"
.string "{STRING 42}’s party is covered\nby a veil!$"
.string "{STRING 16}’s party is protected\nby SAFEGUARD!$"
.string "{STRING 44}’s party is no longer\nprotected by SAFEGUARD!$"
.string "{STRING 15} went\nto sleep!$"
.string "{STRING 15} slept and\nbecame healthy!$"
.string "{STRING 15} whipped\nup a whirlwind!$"
.string "{STRING 15} took\nin sunlight!$"
.string "{STRING 15} lowered\nits head!$"
.string "{STRING 15} is glowing!$"
.string "{STRING 15} flew\nup high!$"
.string "{STRING 15} dug a hole!$"
.string "{STRING 15} hid\nunderwater!$"
.string "{STRING 15} sprang up!$"
.string "{STRING 16} was squeezed by\n{STRING 15}’s BIND!$"
.string "{STRING 16} was trapped\nin the vortex!$"
.string "{STRING 16} was trapped\nby SAND TOMB!$"
.string "{STRING 16} was WRAPPED by\n{STRING 15}!$"
.string "{STRING 15} CLAMPED\n{STRING 16}!$"
.string "{STRING 15} is hurt\nby {STRING 0}!$"
.string "{STRING 15} was freed\nfrom {STRING 0}!$"
.string "{STRING 15} kept going\nand crashed!$"

gUnknown_085CA424:: @ 85CA424

.string "{STRING 42} became\nshrouded in MIST!$"
.string "{STRING 19} is protected\nby MIST!$"

gUnknown_085CA459:: @ 85CA459

.string "{STRING 15} is getting\npumped!$"
.string "{STRING 15} is hit\nwith recoil!$"
.string "{STRING 15} protected\nitself!$"
.string "{STRING 15} is buffeted\nby the sandstorm!$"
.string "{STRING 15} is pelted\nby HAIL!$"
.string "{STRING 40}’s {STRING 0}\nwore off!$"
.string "{STRING 16} was seeded!$"
.string "{STRING 16} evaded\nthe attack!$"
.string "{STRING 15}’s health is\nsapped by LEECH SEED!$"
.string "{STRING 15} is fast\nasleep.$"
.string "{STRING 15} woke up!$"
.string "But {STRING 19}’s UPROAR\nkept it awake!$"
.string "{STRING 15} woke up\nin the UPROAR!$"
.string "{STRING 15} caused\nan UPROAR!$"
.string "{STRING 15} is making\nan UPROAR!$"
.string "{STRING 15} calmed down.$"
.string "But {STRING 16} can’t\nsleep in an UPROAR!$"
.string "{STRING 15} STOCKPILED\n{STRING 0}!$"
.string "{STRING 15} can’t\nSTOCKPILE any more!$"
.string "But {STRING 16} can’t\nsleep in an UPROAR!$"
.string "But the UPROAR kept\n{STRING 16} awake!$"
.string "{STRING 16} stayed awake\nusing its {STRING 25}!$"
.string "{STRING 15} is storing\nenergy!$"
.string "{STRING 15} unleashed\nenergy!$"
.string "{STRING 15} became\nconfused due to fatigue!$"
.string "{STRING 35} picked up\n¥{STRING 0}!\p$"
.string "{STRING 16} is\nunaffected!$"
.string "{STRING 15} transformed\ninto {STRING 0}!$"
.string "{STRING 15} made\na SUBSTITUTE!$"
.string "{STRING 15} already\nhas a SUBSTITUTE!$"
.string "The SUBSTITUTE took damage\nfor {STRING 16}!\p$"
.string "{STRING 16}’s\nSUBSTITUTE faded!\p$"
.string "{STRING 15} must\nrecharge!$"
.string "{STRING 16}’s RAGE\nis building!$"
.string "{STRING 16}’s {STRING 0}\nwas disabled!$"
.string "{STRING 15} is disabled\nno more!$"
.string "{STRING 16} got\nan ENCORE!$"
.string "{STRING 15}’s ENCORE\nended!$"
.string "{STRING 15} took aim\nat {STRING 16}!$"
.string "{STRING 15} SKETCHED\n{STRING 0}!$"
.string "{STRING 15} is trying\nto take its foe with it!$"
.string "{STRING 16} took\n{STRING 15} with it!$"
.string "Reduced {STRING 16}’s\n{STRING 0} by {PLAYER}!$"
.string "{STRING 15} stole\n{STRING 16}’s {STRING 22}!$"
.string "{STRING 16} can’t\nescape now!$"
.string "{STRING 16} fell into\na NIGHTMARE!$"
.string "{STRING 15} is locked\nin a NIGHTMARE!$"
.string "{STRING 15} cut its own HP and\nlaid a CURSE on {STRING 16}!$"
.string "{STRING 15} is afflicted\nby the CURSE!$"
.string "SPIKES were scattered all around\nthe opponent’s side!$"
.string "{STRING 19} is hurt\nby SPIKES!$"
.string "{STRING 15} identified\n{STRING 16}!$"
.string "{STRING 15}’s PERISH count\nfell to {STRING 0}!$"
.string "{STRING 15} braced\nitself!$"
.string "{STRING 16} ENDURED\nthe hit!$"
.string "MAGNITUDE {STRING 0}!$"
.string "{STRING 15} cut its own HP\nand maximized ATTACK!$"
.string "{STRING 15} copied\n{STRING 16}’s stat changes!$"
.string "{STRING 15} got free of\n{STRING 16}’s {STRING 0}!$"
.string "{STRING 15} shed\nLEECH SEED!$"
.string "{STRING 15} blew away\nSPIKES!$"
.string "{STRING 15} fled from\nbattle!$"
.string "{STRING 15} foresaw\nan attack!$"
.string "{STRING 16} took the\n{STRING 0} attack!$"
.string "{STRING 15} chose\n{STRING 20} as its destiny!$"
.string "{STRING 0}’s attack!$"
.string "{STRING 15} became the\ncenter of attention!$"
.string "{STRING 15} began\ncharging power!$"
.string "NATURE POWER turned into\n{STRING 20}!$"
.string "{STRING 15}’s status\nreturned to normal!$"
.string "{STRING 16} was subjected\nto TORMENT!$"
.string "{STRING 15} is tightening\nits focus!$"
.string "{STRING 16} fell for\nthe TAUNT!$"
.string "{STRING 15} is ready to\nhelp {STRING 16}!$"
.string "{STRING 15} switched\nitems with its opponent!$"
.string "{STRING 15} obtained\n{STRING 0}.$"
.string "{STRING 16} obtained\n{PLAYER}.$"
.string "{STRING 15} obtained\n{STRING 0}.\p{STRING 16} obtained\n{PLAYER}.$"
.string "{STRING 15} copied\n{STRING 16}’s {STRING 25}!$"
.string "{STRING 15} made a WISH!$"
.string "{STRING 0}’s WISH\ncame true!$"
.string "{STRING 15} planted its roots!$"
.string "{STRING 15} absorbed\nnutrients with its roots!$"
.string "{STRING 16} anchored\nitself with its roots!$"
.string "{STRING 15} made\n{STRING 16} drowsy!$"
.string "{STRING 15} knocked off\n{STRING 16}’s {STRING 22}!$"
.string "{STRING 15} swapped abilities\nwith its opponent!$"
.string "{STRING 15} sealed the\nopponent’s move(s)!$"
.string "{STRING 15} wants the\nopponent to bear a GRUDGE!$"
.string "{STRING 15}’s {STRING 0} lost\nall its PP due to the GRUDGE!$"
.string "{STRING 15} shrouded\nitself in {STRING 20}!$"
.string "{STRING 15}’s {STRING 20}\nwas bounced back by MAGIC COAT!$"
.string "{STRING 15} waits for a target\nto make a move!$"
.string "{STRING 16} SNATCHED\n{STRING 19}’s move!$"
.string "Electricity’s power was\nweakened!$"
.string "Fire’s power was\nweakened!$"
.string "{STRING 15} found\none {STRING 22}!$"
.string "A soothing aroma wafted\nthrough the area!$"
.string "Items can’t be used now.{PAUSE 64}$"
.string "For {STRING 19},\n{STRING 22} {STRING 0}$"
.string "{STRING 19} used\n{STRING 22} to get pumped!$"
.string "{STRING 15} lost its\nfocus and couldn’t move!$"
.string "{STRING 16} was\ndragged out!\p$"
.string "The wall shattered!$"
.string "But it had no effect!$"
.string "{STRING 18} has no\nmoves left!\p$"
.string "{STRING 18}’s {STRING 20}\nis disabled!\p$"
.string "{STRING 18} can’t use the same\nmove in a row due to the TORMENT!\p$"
.string "{STRING 18} can’t use\n{STRING 20} after the TAUNT!\p$"
.string "{STRING 18} can’t use the\nsealed {STRING 20}!\p$"
.string "{STRING 19}’s {STRING 26}\nmade it rain!$"
.string "{STRING 19}’s {STRING 26}\nraised its SPEED!$"
.string "{STRING 16} was protected\nby {STRING 25}!$"
.string "{STRING 16}’s {STRING 25}\nprevents {STRING 15}\lfrom using {STRING 20}!$"
.string "{STRING 16} restored HP\nusing its {STRING 25}!$"
.string "{STRING 16}’s {STRING 25}\nmade {STRING 20} useless!$"
.string "{STRING 16}’s {STRING 25}\nmade it the {STRING 0} type!$"
.string "{STRING 17}’s {STRING 25}\nprevents paralysis!$"
.string "{STRING 16}’s {STRING 25}\nprevents romance!$"
.string "{STRING 17}’s {STRING 25}\nprevents poisoning!$"
.string "{STRING 16}’s {STRING 25}\nprevents confusion!$"
.string "{STRING 16}’s {STRING 25}\nraised its FIRE power!$"
.string "{STRING 16} anchors\nitself with {STRING 25}!$"
.string "{STRING 19}’s {STRING 26}\ncuts {STRING 16}’s ATTACK!$"
.string "{STRING 19}’s {STRING 26}\nprevents stat loss!$"
.string "{STRING 16}’s {STRING 25}\nhurt {STRING 15}!$"
.string "{STRING 19} TRACED\n{STRING 0}’s {PLAYER}!$"
.string "{STRING 17}’s {STRING 27}\nprevents burns!$"
.string "{STRING 16}’s {STRING 25}\nblocks {STRING 20}!$"
.string "{STRING 19}’s {STRING 26}\nblocks {STRING 20}!$"
.string "{STRING 15}’s {STRING 24}\nrestored its HP a little!$"
.string "{STRING 19}’s {STRING 26}\nwhipped up a sandstorm!$"
.string "{STRING 19}’s {STRING 26}\nintensified the sun’s rays!$"
.string "{STRING 19}’s {STRING 26}\nprevents {STRING 0} loss!$"
.string "{STRING 16}’s {STRING 25}\ninfatuated {STRING 15}!$"
.string "{STRING 16}’s {STRING 25}\nmade {STRING 20} ineffective!$"
.string "{STRING 19}’s {STRING 26}\ncured its {STRING 0} problem!$"
.string "It sucked up the\nLIQUID OOZE!$"
.string "{STRING 19} transformed!$"
.string "{STRING 16}’s {STRING 25}\ntook the attack!$"

gUnknown_085CB2A1:: @ 85CB2A1

.string "{STRING 0}’s {STRING 23}\nprevents switching!\p$"
.string "{STRING 16}’s {STRING 25}\nprevented {STRING 19}’s\l{STRING 0} from working!$"
.string "{STRING 19}’s {STRING 26}\nmade it ineffective!$"
.string "{STRING 17}’s {STRING 27}\nprevents flinching!$"
.string "{STRING 15}’s {STRING 24}\nprevents {STRING 16}’s\l{STRING 25} from working!$"
.string "{STRING 19}’s {STRING 26}\ncured its {STRING 0} problem!$"
.string "{STRING 19}’s {STRING 26}\nhad no effect on {STRING 17}!$"
.string "sharply $"

gUnknown_085CB38A:: @ 85CB38A

.string "rose!$"
.string "harshly $"
.string "fell!$"
.string "{STRING 15}’s {STRING 0}\n{PLAYER}$"

gUnknown_085CB3AA:: @ 85CB3AA

.string "{STRING 16}’s {STRING 0}\n{PLAYER}$"
.string "Using {STRING 22}, the {STRING 0}\nof {STRING 19} {PLAYER}$"
.string "{STRING 15}’s {STRING 0}\n{PLAYER}$"
.string "{STRING 16}’s {STRING 0}\n{PLAYER}$"
.string "{STRING 15}’s stats won’t\ngo any higher!$"
.string "{STRING 16}’s stats won’t\ngo any lower!$"
.string "A critical hit!$"
.string "It’s a one-hit KO!$"
.string "{PAUSE 32}1, {PAUSE 15}2, and{PAUSE 15}‥ {PAUSE 15}‥ {PAUSE 15}‥ {PAUSE 15}{PLAY_SE 0x0038}Poof!\p$"
.string "And‥\p$"
.string "HM moves can’t be\nforgotten now.\p$"
.string "It’s not very effective‥$"
.string "It’s super effective!$"

gUnknown_085CB4CA:: @ 85CB4CA

.string "{PLAY_SE 0x0011}Got away safely!\p$"
.string "{PLAY_SE 0x0011}{STRING 15} fled\nusing its {STRING 22}!\p$"
.string "{PLAY_SE 0x0011}{STRING 15} fled\nusing {STRING 24}!\p$"
.string "{PLAY_SE 0x0011}Wild {STRING 0} fled!$"

gUnknown_085CB524:: @ 85CB524

.string "Player defeated\n{STRING 32}!$"

gUnknown_085CB538:: @ 85CB538

.string "Player beat {STRING 32}\nand {STRING 33}!$"

gUnknown_085CB54F:: @ 85CB54F

.string "Player lost against\n{STRING 32}!$"

gUnknown_085CB567:: @ 85CB567

.string "Player lost to {STRING 32}\nand {STRING 33}!$"

gUnknown_085CB581:: @ 85CB581

.string "Player battled to a draw against\n{STRING 32}!$"

gUnknown_085CB5A6:: @ 85CB5A6

.string "Player battled to a draw against\n{STRING 32} and {STRING 33}!$"

gUnknown_085CB5D2:: @ 85CB5D2

.string "{PLAY_SE 0x0011}{STRING 32} fled!$"

gUnknown_085CB5DF:: @ 85CB5DF

.string "{PLAY_SE 0x0011}{STRING 32} and\n{STRING 33} fled!$"
.string "No! There’s no running\nfrom a TRAINER battle!\p$"
.string "Can’t escape!\p$"
.string "PROF. BIRCH: Don’t leave me like this!\p$"
.string "But nothing happened!$"
.string "But it failed!$"
.string "It hurt itself in its\nconfusion!$"
.string "The MIRROR MOVE failed!$"
.string "It started to rain!$"
.string "A downpour started!$"
.string "Rain continues to fall.$"
.string "The downpour continues.$"
.string "The rain stopped.$"
.string "A sandstorm brewed!$"
.string "The sandstorm rages.$"
.string "The sandstorm subsided.$"
.string "The sunlight got bright!$"
.string "The sunlight is strong.$"
.string "The sunlight faded.$"
.string "It started to hail!$"
.string "Hail continues to fall.$"
.string "The hail stopped.$"
.string "But it failed to SPIT UP\na thing!$"
.string "But it failed to SWALLOW\na thing!$"
.string "The wind turned into a\nHEAT WAVE!$"
.string "All stat changes were\neliminated!$"
.string "Coins scattered everywhere!$"
.string "It was too weak to make\na SUBSTITUTE!$"
.string "The battlers shared\ntheir pain!$"
.string "A bell chimed!$"
.string "All affected POKéMON will\nfaint in three turns!$"
.string "There’s no PP left for\nthis move!\p$"
.string "But there was no PP left\nfor the move!$"
.string "{STRING 15} ignored\norders while asleep!$"
.string "{STRING 15} ignored\norders!$"
.string "{STRING 15} began to nap!$"
.string "{STRING 15} is\nloafing around!$"
.string "{STRING 15} won’t\nobey!$"
.string "{STRING 15} turned away!$"
.string "{STRING 15} pretended\nnot to notice!$"
.string "{STRING 28} {STRING 29} is\nabout to use {PLAYER}.\pWill {STRING 35} change\nPOKéMON?$"
.string "{STRING 15} learned\n{STRING 0}!$"

gUnknown_085CBA2E:: @ 85CBA2E

.string "Player defeated\n{STRING 28} {STRING 29}!\p$"
.string "{STRING 35} crept closer to\n{RIVAL}!$"
.string "{STRING 35} can’t get any closer!$"
.string "{RIVAL} is watching\ncarefully!$"
.string "{RIVAL} is curious about\nthe {STRING 0}!$"
.string "{RIVAL} is enthralled by\nthe {STRING 0}!$"
.string "{RIVAL} completely ignored\nthe {STRING 0}!$"
.string "{STRING 35} threw a {POKEBLOCK}\nat the {RIVAL}!$"
.string "{PLAY_SE 0x0049}ANNOUNCER: You’re out of\nSAFARI BALLS! Game over!\p$"
.string "{RIVAL} appeared!\p$"

gUnknown_085CBB47:: @ 85CBB47

.string "Wild {RIVAL} appeared!\p$"

gUnknown_085CBB5A:: @ 85CBB5A

.string "Wild {RIVAL} appeared!\p$"

gUnknown_085CBB6D:: @ 85CBB6D

.string "Wild {RIVAL} appeared!{PAUSE 127}$"

gUnknown_085CBB82:: @ 85CBB82

.string "Wild {RIVAL} and\n{AQUA} appeared!\p$"

gUnknown_085CBB9C:: @ 85CBB9C

.string "{STRING 28} {STRING 29}\nwould like to battle!\p$"

gUnknown_085CBBB9:: @ 85CBBB9

.string "{STRING 32}\nwants to battle!$"

gUnknown_085CBBCD:: @ 85CBBCD

.string "{STRING 32} and {STRING 33}\nwant to battle!$"

gUnknown_085CBBE7:: @ 85CBBE7

.string "{STRING 28} {STRING 29} sent\nout {RIVAL}!$"

gUnknown_085CBBFA:: @ 85CBBFA

.string "{STRING 28} {STRING 29} sent\nout {RIVAL} and {AQUA}!$"

gUnknown_085CBC14:: @ 85CBC14

.string "{STRING 28} {STRING 29} sent\nout {STRING 0}!$"

gUnknown_085CBC27:: @ 85CBC27

.string "{STRING 32} sent out\n{RIVAL}!$"

gUnknown_085CBC37:: @ 85CBC37

.string "{STRING 32} sent out\n{RIVAL} and {AQUA}!$"

gUnknown_085CBC4E:: @ 85CBC4E

.string "{STRING 32} sent out {STRING 10}!\n{STRING 33} sent out {STRING 12}!$"

gUnknown_085CBC6E:: @ 85CBC6E

.string "{STRING 32} sent out\n{STRING 0}!$"

gUnknown_085CBC7E:: @ 85CBC7E

.string "{STRING 34} sent out\n{STRING 0}!$"

gUnknown_085CBC8E:: @ 85CBC8E

.string "Go! {STRING 5}!$"

gUnknown_085CBC96:: @ 85CBC96

.string "Go! {STRING 5} and\n{VERSION}!$"

gUnknown_085CBCA5:: @ 85CBCA5

.string "Go! {STRING 0}!$"

gUnknown_085CBCAD:: @ 85CBCAD

.string "Do it! {STRING 0}!$"

gUnknown_085CBCB8:: @ 85CBCB8

.string "Go for it, {STRING 0}!$"

gUnknown_085CBCC7:: @ 85CBCC7

.string "Your foe’s weak!\nGet ’em, {STRING 0}!$"

gUnknown_085CBCE5:: @ 85CBCE5

.string "{STRING 31} sent out {STRING 11}!\nGo! {STRING 9}!$"

gUnknown_085CBCFD:: @ 85CBCFD

.string "{STRING 0}, that’s enough!\nCome back!$"

gUnknown_085CBD1B:: @ 85CBD1B

.string "{STRING 0}, come back!$"

gUnknown_085CBD2A:: @ 85CBD2A

.string "{STRING 0}, OK!\nCome back!$"

gUnknown_085CBD3D:: @ 85CBD3D

.string "{STRING 0}, good!\nCome back!$"

gUnknown_085CBD52:: @ 85CBD52

.string "{STRING 28} {STRING 29}\nwithdrew {STRING 0}!$"

gUnknown_085CBD65:: @ 85CBD65

.string "{STRING 32} withdrew\n{STRING 0}!$"

gUnknown_085CBD75:: @ 85CBD75

.string "{STRING 34} withdrew\n{STRING 0}!$"

gUnknown_085CBD85:: @ 85CBD85

.string "Wild $"

gUnknown_085CBD8B:: @ 85CBD8B

.string "Foe $"
.string "$"

gUnknown_085CBD91:: @ 85CBD91

.string "Foe$"

gUnknown_085CBD95:: @ 85CBD95

.string "Ally$"

gUnknown_085CBD9A:: @ 85CBD9A

.string "Foe$"

gUnknown_085CBD9E:: @ 85CBD9E

.string "Ally$"

gUnknown_085CBDA3:: @ 85CBDA3

.string "Foe$"

gUnknown_085CBDA7:: @ 85CBDA7

.string "Ally$"

gUnknown_085CBDAC:: @ 85CBDAC

.string "{STRING 15} used\n{PLAYER}$"

gUnknown_085CBDB7:: @ 85CBDB7

.string "!$"

gUnknown_085CBDB9:: @ 85CBDB9

.string "!$"

gUnknown_085CBDBB:: @ 85CBDBB

.string "!$"

gUnknown_085CBDBD:: @ 85CBDBD

.string "!$"

gUnknown_085CBDBF:: @ 85CBDBF
	.incbin "baserom.gba", 0x5cbdbf, 0x41

gStatNamesTable:: @ 85CBE00
	.incbin "baserom.gba", 0x5cbe00, 0x6c

gUnknown_085CBE6C:: @ 85CBE6C
	.incbin "baserom.gba", 0x5cbe6c, 0x1a9
    
gUnknown_085CC015:: @ 85CC015

.string "someone’s$"

gUnknown_085CC01F:: @ 85CC01F

.string "LANETTE’s$"
.string "{RIVAL}’s data was\nadded to the POKéDEX.\p$"
.string "It is raining.$"
.string "A sandstorm is raging.$"
.string "The BOX is full!\nYou can’t catch any more!\p$"

gUnknown_085CC0A0:: @ 85CC0A0

.string "ENIGMA BERRY$"

gUnknown_085CC0AD:: @ 85CC0AD

.string " BERRY$"
.string "{STRING 19}’s {STRING 22}\ncured paralysis!$"
.string "{STRING 19}’s {STRING 22}\ncured poison!$"
.string "{STRING 19}’s {STRING 22}\nhealed its burn!$"
.string "{STRING 19}’s {STRING 22}\ndefrosted it!$"
.string "{STRING 19}’s {STRING 22}\nwoke it from its sleep!$"
.string "{STRING 19}’s {STRING 22}\nsnapped it out of confusion!$"
.string "{STRING 19}’s {STRING 22}\ncured its {STRING 0} problem!$"
.string "{STRING 19}’s {STRING 22}\nnormalized its status!$"
.string "{STRING 19}’s {STRING 22}\nrestored health!$"
.string "{STRING 19}’s {STRING 22}\nrestored {STRING 0}’s PP!$"
.string "{STRING 19}’s {STRING 22}\nrestored its status!$"
.string "{STRING 19}’s {STRING 22}\nrestored its HP a little!$"
.string "{STRING 22} allows the\nuse of only {STRING 20}!\p$"
.string "{STRING 16} hung on\nusing its {STRING 22}!$"

gUnknown_085CC23E:: @ 85CC23E

.string "$"
.string "You throw a BALL now, right?\nI‥ I’ll do my best!$"

gUnknown_085CC270:: @ 85CC270
	.incbin "baserom.gba", 0x5cc270, 0x5c4

gUnknown_085CC834:: @ 85CC834
	.incbin "baserom.gba", 0x5cc834, 0x14e

gUnknown_085CC982:: @ 85CC982
	.incbin "baserom.gba", 0x5cc982, 0xe

gUnknown_085CC990:: @ 85CC990

.string "What?\n{STR_VAR_1} is evolving!$"

gUnknown_085CC9A6:: @ 85CC9A6

.string "Congratulations! Your {STR_VAR_1}\nevolved into {STR_VAR_2}!{UNKNOWN_A}\p$"

gUnknown_085CC9D3:: @ 85CC9D3

.string "Huh? {STR_VAR_1}\nstopped evolving!\p$"

gUnknown_085CC9EE:: @ 85CC9EE

.string "‥‥?\p$"

gUnknown_085CC9F3:: @ 85CC9F3

.string "What will\n{STRING 18} do?$"

gUnknown_085CCA04:: @ 85CCA04

.string "What will\n{STRING 35} do?$"

gUnknown_085CCA15:: @ 85CCA15

.string "What will\nWALLY do?$"

gUnknown_085CCA29:: @ 85CCA29

.string "{PAUSE 16}Link standby‥$"

gUnknown_085CCA3A:: @ 85CCA3A
	.incbin "baserom.gba", 0x5cca3a, 0x1a

gUnknown_085CCA54:: @ 85CCA54
	.incbin "baserom.gba", 0x5cca54, 0x1b

gUnknown_085CCA6F:: @ 85CCA6F
	.incbin "baserom.gba", 0x5cca6f, 0x4

gUnknown_085CCA73:: @ 85CCA73
	.incbin "baserom.gba", 0x5cca73, 0x48

gUnknown_085CCABB:: @ 85CCABB
	.incbin "baserom.gba", 0x5ccabb, 0xf

gUnknown_085CCACA:: @ 85CCACA
	.incbin "baserom.gba", 0x5ccaca, 0x62

gUnknown_085CCB2C:: @ 85CCB2C
	.incbin "baserom.gba", 0x5ccb2c, 0x10

gUnknown_085CCB3C:: @ 85CCB3C
	.incbin "baserom.gba", 0x5ccb3c, 0x3d

gUnknown_085CCB79:: @ 85CCB79
	.incbin "baserom.gba", 0x5ccb79, 0x6

gUnknown_085CCB7F:: @ 85CCB7F
	.incbin "baserom.gba", 0x5ccb7f, 0x3

gUnknown_085CCB82:: @ 85CCB82
	.incbin "baserom.gba", 0x5ccb82, 0x2

gUnknown_085CCB84:: @ 85CCB84
	.incbin "baserom.gba", 0x5ccb84, 0x2

gUnknown_085CCB86:: @ 85CCB86
	.incbin "baserom.gba", 0x5ccb86, 0x2

gUnknown_085CCB88:: @ 85CCB88
	.incbin "baserom.gba", 0x5ccb88, 0x4

gUnknown_085CCB8C:: @ 85CCB8C
	.incbin "baserom.gba", 0x5ccb8c, 0x4

gUnknown_085CCB90:: @ 85CCB90
	.incbin "baserom.gba", 0x5ccb90, 0x8

gUnknown_085CCB98:: @ 85CCB98
	.incbin "baserom.gba", 0x5ccb98, 0x6

gUnknown_085CCB9E:: @ 85CCB9E
	.incbin "baserom.gba", 0x5ccb9e, 0x7

gUnknown_085CCBA5:: @ 85CCBA5
	.incbin "baserom.gba", 0x5ccba5, 0x8

gUnknown_085CCBAD:: @ 85CCBAD
	.incbin "baserom.gba", 0x5ccbad, 0x8

gUnknown_085CCBB5:: @ 85CCBB5
	.incbin "baserom.gba", 0x5ccbb5, 0x4

gUnknown_085CCBB9:: @ 85CCBB9
	.incbin "baserom.gba", 0x5ccbb9, 0x3

gUnknown_085CCBBC:: @ 85CCBBC
	.incbin "baserom.gba", 0x5ccbbc, 0x132

gUnknown_085CCCEE:: @ 85CCCEE
	.incbin "baserom.gba", 0x5cccee, 0x32

gUnknown_085CCD20:: @ 85CCD20
	.incbin "baserom.gba", 0x5ccd20, 0x92

gUnknown_085CCDB2:: @ 85CCDB2
	.incbin "baserom.gba", 0x5ccdb2, 0x3

gUnknown_085CCDB5:: @ 85CCDB5
	.incbin "baserom.gba", 0x5ccdb5, 0x3

gUnknown_085CCDB8:: @ 85CCDB8
	.incbin "baserom.gba", 0x5ccdb8, 0x3

gUnknown_085CCDBB:: @ 85CCDBB
	.incbin "baserom.gba", 0x5ccdbb, 0x5

gUnknown_085CCDC0:: @ 85CCDC0
	.incbin "baserom.gba", 0x5ccdc0, 0x6

gUnknown_085CCDC6:: @ 85CCDC6
	.incbin "baserom.gba", 0x5ccdc6, 0x5

gUnknown_085CCDCB:: @ 85CCDCB
	.incbin "baserom.gba", 0x5ccdcb, 0x13

gUnknown_085CCDDE:: @ 85CCDDE
	.incbin "baserom.gba", 0x5ccdde, 0x26

gUnknown_085CCE04:: @ 85CCE04
	.incbin "baserom.gba", 0x5cce04, 0x13

gUnknown_085CCE17:: @ 85CCE17
	.incbin "baserom.gba", 0x5cce17, 0x21

gUnknown_085CCE38:: @ 85CCE38
	.incbin "baserom.gba", 0x5cce38, 0x1b

gUnknown_085CCE53:: @ 85CCE53
	.incbin "baserom.gba", 0x5cce53, 0x375

gUnknown_085CD1C8:: @ 85CD1C8
	.incbin "baserom.gba", 0x5cd1c8, 0x84

gUnknown_085CD24C:: @ 85CD24C
	.incbin "baserom.gba", 0x5cd24c, 0x1b

gUnknown_085CD267:: @ 85CD267
	.incbin "baserom.gba", 0x5cd267, 0x28

gUnknown_085CD28F:: @ 85CD28F
	.incbin "baserom.gba", 0x5cd28f, 0x3c

gUnknown_085CD2CB:: @ 85CD2CB
	.incbin "baserom.gba", 0x5cd2cb, 0x36

gUnknown_085CD301:: @ 85CD301
	.incbin "baserom.gba", 0x5cd301, 0x17

gUnknown_085CD318:: @ 85CD318
	.incbin "baserom.gba", 0x5cd318, 0x1e

gUnknown_085CD336:: @ 85CD336
	.incbin "baserom.gba", 0x5cd336, 0xec

gUnknown_085CD422:: @ 85CD422
	.incbin "baserom.gba", 0x5cd422, 0x23e

gUnknown_085CD660:: @ 85CD660
	.incbin "baserom.gba", 0x5cd660, 0x8

gUnknown_085CD668:: @ 85CD668
	.incbin "baserom.gba", 0x5cd668, 0x4

