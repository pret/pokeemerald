#include "global.h"

ALIGNED(4)
#if FRENCH
const u8 gText_MysteryEventBerry[] = _("Tu as obtenu une BAIE {STR_VAR_2}!\nPapa en a une à l’ARENE de CLEMENTI.");
const u8 gText_MysteryEventBerryTransform[] = _("La BAIE {STR_VAR_1} s’est transformée en\nune BAIE {STR_VAR_2}.");
const u8 gText_MysteryEventBerryObtained[] = _("Tu avais déjà obtenu la BAIE\n{STR_VAR_1}.");
const u8 gText_MysteryEventSpecialRibbon[] = _("Un RUBAN spécial a été remis au\nPOKéMON de ton équipe.");
const u8 gText_MysteryEventNationalDex[] = _("Tu peux maintenant accéder au\nMODE NATIONAL dans ton POKéDEX.");
const u8 gText_MysteryEventRareWord[] = _("Un mot rare a été ajouté.");
const u8 gText_MysteryEventSentOver[] = _("{STR_VAR_1} a été envoyé!");
const u8 gText_MysteryEventFullParty[] = _("Ton équipe est complète.\n{STR_VAR_1} ne peut pas être envoyé.");
const u8 gText_MysteryEventNewTrainer[] = _("Un nouveau DRESSEUR est arrivé\ndans la région de HOENN.");
static const u8 gText_MysteryEventNewAdversaryInBattleTower[] = _("A new adversary has arrived in the\nBATTLE TOWER."); // Unused
const u8 gText_MysteryEventCantBeUsed[] = _("Ces données ne peuvent être utilisées\ndans cette version.");
#elif ITALIAN
const u8 gText_MysteryEventBerry[] = _("Trovata una BACCA{STR_VAR_2}!\nIl papà ne ha una alla PALESTRA di\lPETALIPOLI.");
const u8 gText_MysteryEventBerryTransform[] = _("La BACCA{STR_VAR_1} è stata trasformata\nin BACCA{STR_VAR_2}.");
const u8 gText_MysteryEventBerryObtained[] = _("Hai già la BACCA{STR_VAR_1}.");
const u8 gText_MysteryEventSpecialRibbon[] = _("I POKéMON della tua squadra hanno\nricevuto in premio un FIOCCO speciale!");
const u8 gText_MysteryEventNationalDex[] = _("È stato aggiunto il DEX NAZIONALE\nal POKéDEX.");
const u8 gText_MysteryEventRareWord[] = _("È stata aggiunta una parola rara.");
const u8 gText_MysteryEventSentOver[] = _("{STR_VAR_1} è stato inviato!");
const u8 gText_MysteryEventFullParty[] = _("La tua squadra è già al completo.\nNon puoi aggiungere {STR_VAR_1}!");
const u8 gText_MysteryEventNewTrainer[] = _("È arrivato un nuovo ALLENATORE\nnella regione di HOENN.");
const u8 gText_MysteryEventNewAdversaryInBattleTower[] = _("A new adversary has arrived in the\nBATTLE TOWER.");
const u8 gText_MysteryEventCantBeUsed[] = _("Questi dati non possono essere\nutilizzati in questa versione.");
#elif SPANISH
const u8 gText_MysteryEventBerry[] = _("¡Obtuvo una BAYA {STR_VAR_2}!\nPAPÁ la tiene en el GIMNASIO\lde PETALIA.");
const u8 gText_MysteryEventBerryTransform[] = _("La BAYA {STR_VAR_1} se ha transformado\nen una BAYA {STR_VAR_2}.");
const u8 gText_MysteryEventBerryObtained[] = _("Ya tienes la BAYA {STR_VAR_1}.");
const u8 gText_MysteryEventSpecialRibbon[] = _("Tus POKéMON han conseguido\nuna CINTA especial.");
const u8 gText_MysteryEventNationalDex[] = _("La POKéDEX contiene ahora datos\nsobre el MODO NACIONAL.");
const u8 gText_MysteryEventRareWord[] = _("Se ha añadido una palabra extraña.");
const u8 gText_MysteryEventSentOver[] = _("¡Se ha enviado {STR_VAR_1}!");
const u8 gText_MysteryEventFullParty[] = _("Tu equipo está completo.\nNo se puede enviar {STR_VAR_1}.");
const u8 gText_MysteryEventNewTrainer[] = _("Ha llegado un nuevo ENTRENADOR\na HOENN.");
const u8 gText_MysteryEventNewAdversaryInBattleTower[] = _("A new adversary has arrived in the\nBATTLE TOWER.");
const u8 gText_MysteryEventCantBeUsed[] = _("No se pueden usar estos datos\nen esta versión.");
#else //ENGLISH
const u8 gText_MysteryEventBerry[] = _("Obtained a {STR_VAR_2} BERRY!\nDad has it at PETALBURG GYM.");
const u8 gText_MysteryEventBerryTransform[] = _("The {STR_VAR_1} BERRY transformed into\none {STR_VAR_2} BERRY.");
const u8 gText_MysteryEventBerryObtained[] = _("The {STR_VAR_1} BERRY has already been\nobtained.");
const u8 gText_MysteryEventSpecialRibbon[] = _("A special RIBBON was awarded to\nyour party POKéMON.");
const u8 gText_MysteryEventNationalDex[] = _("The POKéDEX has been upgraded\nwith the NATIONAL MODE.");
const u8 gText_MysteryEventRareWord[] = _("A rare word has been added.");
const u8 gText_MysteryEventSentOver[] = _("{STR_VAR_1} was sent over!");
const u8 gText_MysteryEventFullParty[] = _("Your party is full.\n{STR_VAR_1} could not be sent over.");
const u8 gText_MysteryEventNewTrainer[] = _("A new TRAINER has arrived in\nHOENN.");
static const u8 gText_MysteryEventNewAdversaryInBattleTower[] = _("A new adversary has arrived in the\nBATTLE TOWER."); // Unused
const u8 gText_MysteryEventCantBeUsed[] = _("This data can't be used in\nthis version.");
#endif
