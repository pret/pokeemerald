extern const u8 EventScript_FollowerIsShivering[];
extern const u8 EventScript_FollowerNostalgia[];
extern const u8 EventScript_FollowerHopping[];
extern const u8 EventScript_FollowerJumpOnPlayer[];
extern const u8 EventScript_FollowerCuddling[];
extern const u8 EventScript_FollowerShiverCuddling[];
extern const u8 EventScript_FollowerGetCloser[];
extern const u8 EventScript_FollowerPokingPlayer[];
extern const u8 EventScript_FollowerLookAround[];
extern const u8 EventScript_FollowerLookAway[];
extern const u8 EventScript_FollowerLookAwayBark[];
extern const u8 EventScript_FollowerLookAwayPoke[];
extern const u8 EventScript_FollowerPokeGround[];
extern const u8 EventScript_FollowerStartled[];
extern const u8 EventScript_FollowerFastHopping[];
extern const u8 EventScript_FollowerDizzy[];
extern const u8 EventScript_FollowerLookAroundScared[];
extern const u8 EventScript_FollowerDance[];
extern const u8 EventScript_FollowerLookUp[];

// 'Generic', unconditional happy messages
static const u8 sHappyMsg00[] = _("{STR_VAR_1} began poking you in the\nstomach.");
static const u8 sHappyMsg01[] = _("{STR_VAR_1} is happy but shy.");
static const u8 sHappyMsg02[] = _("{STR_VAR_1} is coming along happily.");
static const u8 sHappyMsg03[] = _("{STR_VAR_1} is composed.");
static const u8 sHappyMsg04[] = _("{STR_VAR_1} seems to be feeling\ngreat about walking with you!");
static const u8 sHappyMsg05[] = _("{STR_VAR_1} is glowing with health.");
static const u8 sHappyMsg06[] = _("{STR_VAR_1} looks very happy.");
static const u8 sHappyMsg07[] = _("{STR_VAR_1} put in extra effort.");
static const u8 sHappyMsg08[] = _("{STR_VAR_1} is smelling the scents\nof the surrounding air.");
static const u8 sHappyMsg09[] = _("{STR_VAR_1} is jumping for joy!");
static const u8 sHappyMsg10[] = _("{STR_VAR_1} is still feeling great!");
static const u8 sHappyMsg11[] = _("Your POKéMON has caught the scent of\nsmoke.");
static const u8 sHappyMsg12[] = _("{STR_VAR_1} is poking at your belly.");
static const u8 sHappyMsg13[] = _("Your POKéMON stretched out its body\nand is relaxing.");
static const u8 sHappyMsg14[] = _("{STR_VAR_1} looks like it wants to\nlead!");
static const u8 sHappyMsg15[] = _("{STR_VAR_1} is doing it's best to\nkeep up with you.");
static const u8 sHappyMsg16[] = _("{STR_VAR_1} is happily cuddling up\nto you!");
static const u8 sHappyMsg17[] = _("{STR_VAR_1} is full of life!");
static const u8 sHappyMsg18[] = _("{STR_VAR_1} seems to be very happy!");
static const u8 sHappyMsg19[] = _("{STR_VAR_1} is so happy that it\ncan't stand still!");
static const u8 sHappyMsg20[] = _("{STR_VAR_1} nodded slowly.");
static const u8 sHappyMsg21[] = _("{STR_VAR_1} is very eager!");
static const u8 sHappyMsg22[] = _("{STR_VAR_1} is wandering around and\nlistening to the different sounds.");
static const u8 sHappyMsg23[] = _("{STR_VAR_1} looks very interested.");
static const u8 sHappyMsg24[] = _("{STR_VAR_1} is somehow forcing\nitself to keep going.");
static const u8 sHappyMsg25[] = _("{STR_VAR_1} gave you a sunny look!");
static const u8 sHappyMsg26[] = _("{STR_VAR_1} gives you a happy look\nand a smile.");
static const u8 sHappyMsg27[] = _("Your POKéMON is smelling the scent\nof flowers.");
static const u8 sHappyMsg28[] = _("{STR_VAR_1} seems very happy to see\nyou!");
static const u8 sHappyMsg29[] = _("{STR_VAR_1} faced this way and\ngrinned.");
static const u8 sHappyMsg30[] = _("{STR_VAR_1} happily cuddled up to\nyou!");
// Conditional messages begin here, index 31
static const u8 sHappyMsg31[] = _("Your POKéMON seems happy about the\ngreat weather.");
static const u8 sHappyMsg32[] = _("{STR_VAR_1} is very composed and\nsure of itself!");

const struct FollowerMsgInfo gFollowerHappyMessages[] = {
    {sHappyMsg00, EventScript_FollowerPokingPlayer},
    {sHappyMsg01}, {sHappyMsg02}, {sHappyMsg03}, {sHappyMsg04}, {sHappyMsg05}, {sHappyMsg06}, {sHappyMsg07},
    {sHappyMsg08, EventScript_FollowerLookAround},
    {sHappyMsg09, EventScript_FollowerHopping},
    {sHappyMsg10}, {sHappyMsg11},
    {sHappyMsg12, EventScript_FollowerPokingPlayer},
    {sHappyMsg13, EventScript_FollowerLookAround},
    {sHappyMsg14}, {sHappyMsg15},
    {sHappyMsg16, EventScript_FollowerCuddling},
    {sHappyMsg17}, {sHappyMsg18},
    {sHappyMsg19, EventScript_FollowerFastHopping},
    {sHappyMsg20}, {sHappyMsg21}, {sHappyMsg22}, {sHappyMsg23}, {sHappyMsg24}, {sHappyMsg25}, {sHappyMsg26}, {sHappyMsg27}, {sHappyMsg28}, {sHappyMsg29},
    {sHappyMsg30, EventScript_FollowerCuddling},
    {sHappyMsg31}, {sHappyMsg32},
};

// Unconditional neutral messages
static const u8 sNeutralMsg00[] = _("{STR_VAR_1} is steadily poking at\nthe ground.");
static const u8 sNeutralMsg01[] = _("{STR_VAR_1} is standing guard.");
static const u8 sNeutralMsg02[] = _("{STR_VAR_1} is staring patiently at\nnothing at all.");
static const u8 sNeutralMsg03[] = _("{STR_VAR_1} is wandering around.");
static const u8 sNeutralMsg04[] = _("Your POKéMON yawned loudly!");
static const u8 sNeutralMsg05[] = _("Your POKéMON is looking around\nrestlessly.");
static const u8 sNeutralMsg06[] = _("{STR_VAR_1} is looking this way and\nsmiling.");
static const u8 sNeutralMsg07[] = _("{STR_VAR_1} is gazing around\nrestlessly.");
static const u8 sNeutralMsg08[] = _("{STR_VAR_1} let out a battle cry.");
static const u8 sNeutralMsg09[] = _("{STR_VAR_1} danced a wonderful\ndance!");
static const u8 sNeutralMsg10[] = _("{STR_VAR_1} is very eager.");
static const u8 sNeutralMsg11[] = _("{STR_VAR_1} is staring intently into\nthe distance.");
static const u8 sNeutralMsg12[] = _("{STR_VAR_1} is on the lookout!");
static const u8 sNeutralMsg13[] = _("{STR_VAR_1} looked off into the\ndistance and barked!");

const struct FollowerMsgInfo gFollowerNeutralMessages[] = {
    {sNeutralMsg00, EventScript_FollowerPokeGround},
    {sNeutralMsg01},
    {sNeutralMsg02, EventScript_FollowerLookAway},
    {sNeutralMsg03, EventScript_FollowerLookAround},
    {sNeutralMsg04},
    {sNeutralMsg05, EventScript_FollowerLookAround},
    {sNeutralMsg06}, {sNeutralMsg07}, {sNeutralMsg08},
    {sNeutralMsg09, EventScript_FollowerDance},
    {sNeutralMsg10},
    {sNeutralMsg11, EventScript_FollowerLookAway},
    {sNeutralMsg12},
    {sNeutralMsg13, EventScript_FollowerLookAwayBark},
};

// Unconditional sad messages
static const u8 sSadMsg00[] = _("{STR_VAR_1} is dizzy.");
static const u8 sSadMsg01[] = _("{STR_VAR_1} is stepping on your\nfeet!");
static const u8 sSadMsg02[] = _("{STR_VAR_1} seems a little tired.");
// Conditional messages begin, index 3
static const u8 sSadMsg03[] = _("{STR_VAR_1} is not happy.");
static const u8 sSadMsg04[] = _("{STR_VAR_1} is going to fall down!\n");
static const u8 sSadMsg05[] = _("{STR_VAR_1} seems to be about to\nfall over!");
static const u8 sSadMsg06[] = _("{STR_VAR_1} is trying very hard to\nkeep up with you…");
static const u8 sSadMsg07[] = _("{STR_VAR_1} is nervous.");

const struct FollowerMsgInfo gFollowerSadMessages[] = {
    {sSadMsg00, EventScript_FollowerDizzy},
    {sSadMsg01}, {sSadMsg02},
    {sSadMsg03}, {sSadMsg04}, {sSadMsg05}, {sSadMsg06}, {sSadMsg07},
};

// Unconditional upset messages
static const u8 sUpsetMsg00[] = _("{STR_VAR_1} seems unhappy somehow…");
static const u8 sUpsetMsg01[] = _("{STR_VAR_1} is making an unhappy\nface.");
static const u8 sUpsetMsg02[] = _("…Your POKéMON seems a little\ncold.");
// Conditional messages, index 3
static const u8 sUpsetMsg03[] = _("{STR_VAR_1} is taking shelter in the\ngrass from the rain.");

const struct FollowerMsgInfo gFollowerUpsetMessages[] = {
    {sUpsetMsg00}, {sUpsetMsg01},
    {sUpsetMsg02, EventScript_FollowerIsShivering},
    {sUpsetMsg03},
};

// Unconditional angry messages
static const u8 sAngryMsg00[] = _("{STR_VAR_1} let out a roar!");
static const u8 sAngryMsg01[] = _("{STR_VAR_1} is making a face like\nits angry!");
static const u8 sAngryMsg02[] = _("{STR_VAR_1} seems to be angry for\nsome reason.");
static const u8 sAngryMsg03[] = _("Your POKéMON turned to face the\nother way, showing a defiant face.");
static const u8 sAngryMsg04[] = _("{STR_VAR_1} cried out.");

const struct FollowerMsgInfo gFollowerAngryMessages[] = {
    {sAngryMsg00}, {sAngryMsg01}, {sAngryMsg02},
    {sAngryMsg03, EventScript_FollowerLookAway},
    {sAngryMsg04},
};

// Unconditional pensive messages
static const u8 sPensiveMsg00[] = _("{STR_VAR_1} is looking down\nsteadily.");
static const u8 sPensiveMsg01[] = _("{STR_VAR_1} is surveying the area.");
static const u8 sPensiveMsg02[] = _("{STR_VAR_1} is peering down.");
static const u8 sPensiveMsg03[] = _("{STR_VAR_1} is somehow fighting off\nsleep…");
static const u8 sPensiveMsg04[] = _("{STR_VAR_1} seems to be wandering\naround.");
static const u8 sPensiveMsg05[] = _("{STR_VAR_1} is looking around\nabsentmindedly.");
static const u8 sPensiveMsg06[] = _("{STR_VAR_1} yawned very loudly!");
static const u8 sPensiveMsg07[] = _("{STR_VAR_1} is relaxing comfortably.");
static const u8 sPensiveMsg08[] = _("{STR_VAR_1} is staring steadfastly\nat your face.");
static const u8 sPensiveMsg09[] = _("{STR_VAR_1} is staring intently at\nyour face.");
static const u8 sPensiveMsg10[] = _("{STR_VAR_1} is focusing its\nattention on you.");
static const u8 sPensiveMsg11[] = _("{STR_VAR_1} is staring into the\ndepths.");
static const u8 sPensiveMsg12[] = _("{STR_VAR_1} is sniffing at the\nground.");
static const u8 sPensiveMsg13[] = _("Your POKéMON is staring intently at\nnothing.");
static const u8 sPensiveMsg14[] = _("{STR_VAR_1} focused with a sharp\ngaze!");
static const u8 sPensiveMsg15[] = _("{STR_VAR_1} is concentrating.");
static const u8 sPensiveMsg16[] = _("{STR_VAR_1} faced this way and\nnodded.");
static const u8 sPensiveMsg17[] = _("{STR_VAR_1} seems a bit nervous…");
static const u8 sPensiveMsg18[] = _("{STR_VAR_1} is looking at your\nfootprints.");
static const u8 sPensiveMsg19[] = _("{STR_VAR_1} is staring straight into\nyour eyes.");

const struct FollowerMsgInfo gFollowerPensiveMessages[] = {
    {sPensiveMsg00},
    {sPensiveMsg01, EventScript_FollowerLookAround},
    {sPensiveMsg02}, {sPensiveMsg03}, {sPensiveMsg04},
    {sPensiveMsg05, EventScript_FollowerLookAround},
    {sPensiveMsg06}, {sPensiveMsg07}, {sPensiveMsg08}, {sPensiveMsg09}, {sPensiveMsg10},
    {sPensiveMsg11, EventScript_FollowerLookAway},
    {sPensiveMsg12, EventScript_FollowerPokeGround},
    {sPensiveMsg13, EventScript_FollowerLookAway},
    {sPensiveMsg14}, {sPensiveMsg15}, {sPensiveMsg16}, {sPensiveMsg17}, {sPensiveMsg18}, {sPensiveMsg19},
};

// All 'love' messages are unconditional
static const u8 sLoveMsg00[] = _("{STR_VAR_1} suddenly started walking\ncloser!");
static const u8 sLoveMsg01[] = _("{STR_VAR_1} cheeks are becoming\nrosy!");
static const u8 sLoveMsg02[] = _("Woah! {STR_VAR_1} suddenly hugged\nyou!");
static const u8 sLoveMsg03[] = _("Woah! {STR_VAR_1} is suddenly\nplayful!");
static const u8 sLoveMsg04[] = _("{STR_VAR_1} is rubbing against your\nlegs!");
static const u8 sLoveMsg05[] = _("{STR_VAR_1} blushes.");
static const u8 sLoveMsg06[] = _("Ah! {STR_VAR_1} cuddles you!");
static const u8 sLoveMsg07[] = _("{STR_VAR_1} is regarding you with\nadoration!");
static const u8 sLoveMsg08[] = _("{STR_VAR_1} got closer to you.");
static const u8 sLoveMsg09[] = _("{STR_VAR_1} is keeping close to your\nfeet.");

const struct FollowerMsgInfo gFollowerLoveMessages[] = {
    {sLoveMsg00, EventScript_FollowerGetCloser},
    {sLoveMsg01},
    {sLoveMsg02, EventScript_FollowerCuddling},
    {sLoveMsg03},
    {sLoveMsg04, EventScript_FollowerCuddling},
    {sLoveMsg05},
    {sLoveMsg06, EventScript_FollowerCuddling},
    {sLoveMsg07},
    {sLoveMsg08, EventScript_FollowerGetCloser},
    {sLoveMsg09},
};

// Unconditional surprised messages
static const u8 sSurpriseMsg00[] = _("{STR_VAR_1} is in danger of falling\nover!");
static const u8 sSurpriseMsg01[] = _("{STR_VAR_1} bumped into you!");
static const u8 sSurpriseMsg02[] = _("{STR_VAR_1} doesn't seem to be used\nto its own name yet.");
static const u8 sSurpriseMsg03[] = _("{STR_VAR_1} is peering down.");
static const u8 sSurpriseMsg04[] = _("Your POKéMON stumbled and nearly\nfell!");
static const u8 sSurpriseMsg05[] = _("{STR_VAR_1} feels something and is\nhowling!");
static const u8 sSurpriseMsg06[] = _("{STR_VAR_1} seems refreshed!");
static const u8 sSurpriseMsg07[] = _("{STR_VAR_1} suddenly turned around\nand started barking!");
static const u8 sSurpriseMsg08[] = _("{STR_VAR_1} suddenly turned around!");
static const u8 sSurpriseMsg09[] = _("Your POKéMON was surprised that you\nsuddenly spoke to it!");
static const u8 sSurpriseMsg10[] = _("Sniff sniff, something smells really\ngood!");
static const u8 sSurpriseMsg11[] = _("{STR_VAR_1} feels refreshed.");
static const u8 sSurpriseMsg12[] = _("{STR_VAR_1} is wobbling and seems\nabout to fall over.");
static const u8 sSurpriseMsg13[] = _("{STR_VAR_1} is in danger of falling\nover.");
static const u8 sSurpriseMsg14[] = _("{STR_VAR_1} is walking along\ncautiously.");
static const u8 sSurpriseMsg15[] = _("{STR_VAR_1} is getting tense with\nnervous energy.");
static const u8 sSurpriseMsg16[] = _("{STR_VAR_1} sensed something strange\nand was surprised!");
static const u8 sSurpriseMsg17[] = _("{STR_VAR_1} is scared and snuggled\nup to you!");
static const u8 sSurpriseMsg18[] = _("{STR_VAR_1} is feeling an unusual\npresence…");
static const u8 sSurpriseMsg19[] = _("{STR_VAR_1} is getting tense with\nnervous energy.");
// Conditional messages, index 20
static const u8 sSurpriseMsg20[] = _("{STR_VAR_1} seems to be very\nsurprised that it is raining!");

const struct FollowerMsgInfo gFollowerSurpriseMessages[] = {
    {sSurpriseMsg00},
    {sSurpriseMsg01, EventScript_FollowerPokingPlayer},
    {sSurpriseMsg02}, {sSurpriseMsg03}, {sSurpriseMsg04}, {sSurpriseMsg05}, {sSurpriseMsg06},
    {sSurpriseMsg07, EventScript_FollowerLookAwayBark},
    {sSurpriseMsg08, EventScript_FollowerLookAway},
    {sSurpriseMsg09},
    {sSurpriseMsg10, EventScript_FollowerLookAround},
    {sSurpriseMsg11}, {sSurpriseMsg12}, {sSurpriseMsg13}, {sSurpriseMsg14}, {sSurpriseMsg15}, {sSurpriseMsg16},
    {sSurpriseMsg17, EventScript_FollowerCuddling},
    {sSurpriseMsg18},
    {sSurpriseMsg19, EventScript_FollowerLookAround},
    {sSurpriseMsg20},
};

// Unconditional curious messages
static const u8 sCuriousMsg00[] = _("Your POKéMON is looking around\nrestlessly for something.");
static const u8 sCuriousMsg01[] = _("Your POKéMON wasn't watching where\nit was going and ran into you!");
static const u8 sCuriousMsg02[] = _("Sniff, sniff! Is there something\nnearby?");
static const u8 sCuriousMsg03[] = _("{STR_VAR_1} is rolling a pebble\naround playfully.");
static const u8 sCuriousMsg04[] = _("{STR_VAR_1} is wandering around and\nsearching for something.");
static const u8 sCuriousMsg05[] = _("{STR_VAR_1} is sniffing at you.");
static const u8 sCuriousMsg06[] = _("{STR_VAR_1} seems to be a little\nhesitant…");

const struct FollowerMsgInfo gFollowerCuriousMessages[] = {
    {sCuriousMsg00, EventScript_FollowerLookAround},
    {sCuriousMsg01, EventScript_FollowerPokingPlayer},
    {sCuriousMsg02}, {sCuriousMsg03},
    {sCuriousMsg04, EventScript_FollowerLookAround},
    {sCuriousMsg05}, {sCuriousMsg06},
};

// Unconditional music messages
static const u8 sMusicMsg00[] = _("{STR_VAR_1} is showing off its\nagility!");
static const u8 sMusicMsg01[] = _("{STR_VAR_1} is moving around\nhappily!");
static const u8 sMusicMsg02[] = _("Woah! {STR_VAR_1} suddenly started\ndancing in happiness!");
static const u8 sMusicMsg03[] = _("{STR_VAR_1} is steadily keeping up\nwith you!");
static const u8 sMusicMsg04[] = _("{STR_VAR_1} seems to want to play\nwith you.");
static const u8 sMusicMsg05[] = _("{STR_VAR_1} is happy skipping about.");
static const u8 sMusicMsg06[] = _("{STR_VAR_1} is singing and humming.");
static const u8 sMusicMsg07[] = _("{STR_VAR_1} is nipping at your feet!");
static const u8 sMusicMsg08[] = _("{STR_VAR_1} turns around and looks\nat you.");
static const u8 sMusicMsg09[] = _("{STR_VAR_1} is working hard to show\noff its mighty power!");
static const u8 sMusicMsg10[] = _("Whoa! {STR_VAR_1} suddenly danced in\nhappiness!");
static const u8 sMusicMsg11[] = _("{STR_VAR_1} is cheerful!");
static const u8 sMusicMsg12[] = _("{STR_VAR_1} is jumping around in a\ncarefree way!");
static const u8 sMusicMsg13[] = _("Your POKéMON seems to be smelling a\nnostalgically familiar scent…");
// Conditional music messages, index 14
static const u8 sMusicMsg14[] = _("{STR_VAR_1} is very happy about the\nrain.");

const struct FollowerMsgInfo gFollowerMusicMessages[] = {
    {sMusicMsg00, EventScript_FollowerLookAround},
    {sMusicMsg01},
    {sMusicMsg02, EventScript_FollowerDance},
    {sMusicMsg03},
    {sMusicMsg04, EventScript_FollowerHopping},
    {sMusicMsg05, EventScript_FollowerHopping},
    {sMusicMsg06}, {sMusicMsg07}, {sMusicMsg08}, {sMusicMsg09},
    {sMusicMsg10, EventScript_FollowerDance},
    {sMusicMsg11},
    {sMusicMsg12, EventScript_FollowerHopping},
    {sMusicMsg13, EventScript_FollowerNostalgia},
    {sMusicMsg14}
};


static const u8 sPoisonedMsg00[] = _("{STR_VAR_1} is shivering with the\neffects of being poisoned.");

const struct FollowerMsgInfo gFollowerPoisonedMessages[] = {
    {sPoisonedMsg00, EventScript_FollowerIsShivering},
};
