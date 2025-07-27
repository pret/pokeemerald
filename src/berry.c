#include "global.h"
#include "berry.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "event_scripts.h"
#include "field_control_avatar.h"
#include "fieldmap.h"
#include "item.h"
#include "item_menu.h"
#include "main.h"
#include "random.h"
#include "string_util.h"
#include "text.h"
#include "constants/event_object_movement.h"
#include "constants/items.h"

static u32 GetEnigmaBerryChecksum(struct EnigmaBerry *enigmaBerry);
static bool32 BerryTreeGrow(struct BerryTree *tree);
static u16 BerryTypeToItemId(u16 berry);
static u8 BerryTreeGetNumStagesWatered(struct BerryTree *tree);
static u8 GetNumStagesWateredByBerryTreeId(u8 id);
static u8 CalcBerryYieldInternal(u16 max, u16 min, u8 water);
static u8 CalcBerryYield(struct BerryTree *tree);
static u8 GetBerryCountByBerryTreeId(u8 id);
static u16 GetStageDurationByBerryType(u8);

#if FRENCH
static const u8 sBerryDescriptionPart1_Cheri[] = _("Donne de belles et délicates fleurs.");
static const u8 sBerryDescriptionPart2_Cheri[] = _("Cette BAIE rouge vif est très épicée.");
static const u8 sBerryDescriptionPart1_Chesto[] = _("L’épaisse peau et le fruit de cette");
static const u8 sBerryDescriptionPart2_Chesto[] = _("BAIE sont durs. Son goût est sec.");
static const u8 sBerryDescriptionPart1_Pecha[] = _("Délicieuse et très sucrée, cette BAIE");
static const u8 sBerryDescriptionPart2_Pecha[] = _("est très tendre. A manier doucement.");
static const u8 sBerryDescriptionPart1_Rawst[] = _("Si ses feuilles s’allongent quand elle");
static const u8 sBerryDescriptionPart2_Rawst[] = _("pousse, la BAIE devient très amère.");
static const u8 sBerryDescriptionPart1_Aspear[] = _("Cette BAIE ferme donne un jus très");
static const u8 sBerryDescriptionPart2_Aspear[] = _("riche. Elle est plutôt acide.");
static const u8 sBerryDescriptionPart1_Leppa[] = _("Pousse plus lentement que la CERIZ.");
static const u8 sBerryDescriptionPart2_Leppa[] = _("Plus elle est petite, meilleure elle est.");
static const u8 sBerryDescriptionPart1_Oran[] = _("Une drôle de BAIE aux saveurs");
static const u8 sBerryDescriptionPart2_Oran[] = _("variées. Elle pousse en 1/2 journée.");
static const u8 sBerryDescriptionPart1_Persim[] = _("Adore le soleil. La BAIE prend une");
static const u8 sBerryDescriptionPart2_Persim[] = _("couleur vive si elle y est exposée.");
static const u8 sBerryDescriptionPart1_Lum[] = _("Pousse lentement. Si elle est cultivée");
static const u8 sBerryDescriptionPart2_Lum[] = _("avec amour, elle peut donner 2 BAIES.");
static const u8 sBerryDescriptionPart1_Sitrus[] = _("Variété proche de l’ORAN. Cette");
static const u8 sBerryDescriptionPart2_Sitrus[] = _("grosse BAIE a une saveur pleine.");
static const u8 sBerryDescriptionPart1_Figy[] = _("Cette BAIE, qui a l’air déjà mâchée,");
static const u8 sBerryDescriptionPart2_Figy[] = _("regorge de substances épicées.");
static const u8 sBerryDescriptionPart1_Wiki[] = _("On dit que cette BAIE est bosselée");
static const u8 sBerryDescriptionPart2_Wiki[] = _("pour aider les POKéMON à l’attraper.");
static const u8 sBerryDescriptionPart1_Mago[] = _("Cette BAIE s’enroule en poussant.");
static const u8 sBerryDescriptionPart2_Mago[] = _("Plus elle s’enroule, meilleure elle est.");
static const u8 sBerryDescriptionPart1_Aguav[] = _("Sa fleur est un mets délicat. Elle peut");
static const u8 sBerryDescriptionPart2_Aguav[] = _("pousser sans lumière.");
static const u8 sBerryDescriptionPart1_Iapapa[] = _("Cette BAIE est grosse et acide. Il lui");
static const u8 sBerryDescriptionPart2_Iapapa[] = _("faut au moins un jour pour pousser.");
static const u8 sBerryDescriptionPart1_Razz[] = _("Cette BAIE rouge est un peu épicée.");
static const u8 sBerryDescriptionPart2_Razz[] = _("Il lui suffit de 4 heures pour pousser.");
static const u8 sBerryDescriptionPart1_Bluk[] = _("Cette BAIE est bleue, mais elle noircit");
static const u8 sBerryDescriptionPart2_Bluk[] = _("la langue quand on la mange.");
static const u8 sBerryDescriptionPart1_Nanab[] = _("C’est la septième BAIE découverte au");
static const u8 sBerryDescriptionPart2_Nanab[] = _("monde. Elle est sucrée.");
static const u8 sBerryDescriptionPart1_Wepear[] = _("Sa fleur est petite et blanche. Son");
static const u8 sBerryDescriptionPart2_Wepear[] = _("goût est entre l’amertume et l’acidité.");
static const u8 sBerryDescriptionPart1_Pinap[] = _("Peu résistante au vent et au froid.");
static const u8 sBerryDescriptionPart2_Pinap[] = _("Son fruit est épicé et sa peau acide.");
static const u8 sBerryDescriptionPart1_Pomeg[] = _("Qu’on l’arrose beaucoup ou pas,");
static const u8 sBerryDescriptionPart2_Pomeg[] = _("elle ne donne jamais plus de six BAIES.");
static const u8 sBerryDescriptionPart1_Kelpsy[] = _("Une variété rare en forme de racine.");
static const u8 sBerryDescriptionPart2_Kelpsy[] = _("Donne une très grande fleur.");
static const u8 sBerryDescriptionPart1_Qualot[] = _("Adore l’eau. Pousse très bien, même");
static const u8 sBerryDescriptionPart2_Qualot[] = _("quand il pleut tout le temps.");
static const u8 sBerryDescriptionPart1_Hondew[] = _("Une BAIE très chère et très rare.");
static const u8 sBerryDescriptionPart2_Hondew[] = _("Elle est délicieuse.");
static const u8 sBerryDescriptionPart1_Grepa[] = _("Malgré sa tendresse et sa rondeur,");
static const u8 sBerryDescriptionPart2_Grepa[] = _("cette BAIE est incroyablement acide.");
static const u8 sBerryDescriptionPart1_Tamato[] = _("Cette BAIE est extrêmement épicée.");
static const u8 sBerryDescriptionPart2_Tamato[] = _("Il lui faut longtemps pour pousser.");
static const u8 sBerryDescriptionPart1_Cornn[] = _("Une BAIE très ancienne. Elle ne pousse");
static const u8 sBerryDescriptionPart2_Cornn[] = _("que si elle est plantée en quantité.");
static const u8 sBerryDescriptionPart1_Magost[] = _("On raconte partout que cette BAIE a");
static const u8 sBerryDescriptionPart2_Magost[] = _("un goût très équilibré.");
static const u8 sBerryDescriptionPart1_Rabuta[] = _("Une variété rare recouverte de poils.");
static const u8 sBerryDescriptionPart2_Rabuta[] = _("Elle est plutôt amère.");
static const u8 sBerryDescriptionPart1_Nomel[] = _("Très acide. Une bouchée suffit à");
static const u8 sBerryDescriptionPart2_Nomel[] = _("perdre le goût pendant trois jours.");
static const u8 sBerryDescriptionPart1_Spelon[] = _("Cette BAIE rouge vif est très épicée.");
static const u8 sBerryDescriptionPart2_Spelon[] = _("Ses bosses donnent un extrait épicé.");
static const u8 sBerryDescriptionPart1_Pamtre[] = _("Dérive sur la mer. On ne sait pas");
static const u8 sBerryDescriptionPart2_Pamtre[] = _("d’où elle provient.");
static const u8 sBerryDescriptionPart1_Watmel[] = _("Une BAIE énorme, pouvant atteindre");
static const u8 sBerryDescriptionPart2_Watmel[] = _("50 cm. Terriblement sucrée.");
static const u8 sBerryDescriptionPart1_Durin[] = _("Une BAIE tellement amère que per-");
static const u8 sBerryDescriptionPart2_Durin[] = _("sonne n’en a jamais mangé telle quelle.");
static const u8 sBerryDescriptionPart1_Belue[] = _("D’aspect brillant et délicieux, elle est");
static const u8 sBerryDescriptionPart2_Belue[] = _("atrocement acide. Pousse lentement.");
static const u8 sBerryDescriptionPart1_Liechi[] = _("Une BAIE mystérieuse, censée");
static const u8 sBerryDescriptionPart2_Liechi[] = _("contenir le pouvoir de la mer.");
static const u8 sBerryDescriptionPart1_Ganlon[] = _("Une BAIE mystérieuse, censée");
static const u8 sBerryDescriptionPart2_Ganlon[] = _("contenir le pouvoir de la terre.");
static const u8 sBerryDescriptionPart1_Salac[] = _("Une BAIE mystérieuse, censée");
static const u8 sBerryDescriptionPart2_Salac[] = _("contenir le pouvoir du ciel.");
static const u8 sBerryDescriptionPart1_Petaya[] = _("Une BAIE mystérieuse, censée");
static const u8 sBerryDescriptionPart2_Petaya[] = _("contenir le pouvoir de la vie.");
static const u8 sBerryDescriptionPart1_Apicot[] = _("Une BAIE mystique. Impossible de dire");
static const u8 sBerryDescriptionPart2_Apicot[] = _("ce qu’elle donne, ni ce qu’on en fait.");
static const u8 sBerryDescriptionPart1_Lansat[] = _("On dit cette BAIE légendaire.");
static const u8 sBerryDescriptionPart2_Lansat[] = _("La garder est censé porter bonheur.");
static const u8 sBerryDescriptionPart1_Starf[] = _("Trop puissante, elle fut abandonnée");
static const u8 sBerryDescriptionPart2_Starf[] = _("au bout du monde. On parle de mirage.");
static const u8 sBerryDescriptionPart1_Enigma[] = _("Une BAIE très énigmatique qui");
static const u8 sBerryDescriptionPart2_Enigma[] = _("détiendrait le pouvoir des étoiles.");
#elif ITALIAN
static const u8 sBerryDescriptionPart1_Cheri[] = _("Fiorisce con bei fiorellini delicati. La");
static const u8 sBerryDescriptionPart2_Cheri[] = _("BACCA di un rosso vivo è molto pepata.");
static const u8 sBerryDescriptionPart1_Chesto[] = _("La scorza spessa e il frutto sono");
static const u8 sBerryDescriptionPart2_Chesto[] = _("durissimi. Ha un gusto molto secco.");
static const u8 sBerryDescriptionPart1_Pecha[] = _("BACCA molto dolce e gustosa.");
static const u8 sBerryDescriptionPart2_Pecha[] = _("Molto tenera, maneggiare con cura.");
static const u8 sBerryDescriptionPart1_Rawst[] = _("Se le foglie sono lunghe e ricce,");
static const u8 sBerryDescriptionPart2_Rawst[] = _("la BACCA diventa molto amara.");
static const u8 sBerryDescriptionPart1_Aspear[] = _("Questa dura BACCA è ricca di un succo");
static const u8 sBerryDescriptionPart2_Aspear[] = _("molto nutriente. È piuttosto aspra.");
static const u8 sBerryDescriptionPart1_Leppa[] = _("Matura più lenta della BACCALIEGIA. Le");
static const u8 sBerryDescriptionPart2_Leppa[] = _("BACCHE più piccole sono più saporite.");
static const u8 sBerryDescriptionPart1_Oran[] = _("Una BACCA speciale con sapori misti.");
static const u8 sBerryDescriptionPart2_Oran[] = _("Matura in mezza giornata.");
static const u8 sBerryDescriptionPart1_Persim[] = _("Ama la luce solare. Se esposta al sole,");
static const u8 sBerryDescriptionPart2_Persim[] = _("i colori della BACCA si fanno più vivi.");
static const u8 sBerryDescriptionPart1_Lum[] = _("Matura lentamente. Se coltivata con");
static const u8 sBerryDescriptionPart2_Lum[] = _("cura, può produrre due BACCHE.");
static const u8 sBerryDescriptionPart1_Sitrus[] = _("Strettamente collegata alla");
static const u8 sBerryDescriptionPart2_Sitrus[] = _("BACCARANCIA, ha un sapore rotondo.");
static const u8 sBerryDescriptionPart1_Figy[] = _("BACCA dall’aspetto rosicchiato");
static const u8 sBerryDescriptionPart2_Figy[] = _("ricca di sostanze pepate.");
static const u8 sBerryDescriptionPart1_Wiki[] = _("Pare che la consistenza grumosa");
static const u8 sBerryDescriptionPart2_Wiki[] = _("della BACCA aiuti i POKéMON a coglierla.");
static const u8 sBerryDescriptionPart1_Mago[] = _("La BACCA s’incurva crescendo,");
static const u8 sBerryDescriptionPart2_Mago[] = _("diventando più dolce e saporita.");
static const u8 sBerryDescriptionPart1_Aguav[] = _("Il fiore è molto delicato. Possiede la");
static const u8 sBerryDescriptionPart2_Aguav[] = _("rara capacità di crescere al buio.");
static const u8 sBerryDescriptionPart1_Iapapa[] = _("BACCA molto grande e aspra. Ci");
static const u8 sBerryDescriptionPart2_Iapapa[] = _("mette almeno un giorno per maturare.");
static const u8 sBerryDescriptionPart1_Razz[] = _("BACCA rossa e leggermente pepata.");
static const u8 sBerryDescriptionPart2_Razz[] = _("Matura velocemente in sole 4 ore.");
static const u8 sBerryDescriptionPart1_Bluk[] = _("Esternamente la BACCA è blu, ma");
static const u8 sBerryDescriptionPart2_Bluk[] = _("quando si mangia annerisce la lingua.");
static const u8 sBerryDescriptionPart1_Nanab[] = _("Questa BACCA dolce è la settima");
static const u8 sBerryDescriptionPart2_Nanab[] = _("scoperta al mondo.");
static const u8 sBerryDescriptionPart1_Wepear[] = _("Il fiore è piccolo e bianco. La BACCA");
static const u8 sBerryDescriptionPart2_Wepear[] = _("ha un sapore amaro e aspro.");
static const u8 sBerryDescriptionPart1_Pinap[] = _("Non resiste al freddo e al vento.");
static const u8 sBerryDescriptionPart2_Pinap[] = _("Il frutto è pepato e la buccia aspra.");
static const u8 sBerryDescriptionPart1_Pomeg[] = _("Per quanto venga annaffiata,");
static const u8 sBerryDescriptionPart2_Pomeg[] = _("non produce più di sei BACCHE.");
static const u8 sBerryDescriptionPart1_Kelpsy[] = _("Una specie rara a forma di radice.");
static const u8 sBerryDescriptionPart2_Kelpsy[] = _("Produce un fiore molto grande.");
static const u8 sBerryDescriptionPart1_Qualot[] = _("Adora l’acqua. Cresce forte anche in");
static const u8 sBerryDescriptionPart2_Qualot[] = _("luoghi con precipitazioni persistenti.");
static const u8 sBerryDescriptionPart1_Hondew[] = _("BACCA rara e preziosa,");
static const u8 sBerryDescriptionPart2_Hondew[] = _("oltre ad essere squisita.");
static const u8 sBerryDescriptionPart1_Grepa[] = _("Nonostante la morbida consistenza e");
static const u8 sBerryDescriptionPart2_Grepa[] = _("la forma rotonda, è molto aspra.");
static const u8 sBerryDescriptionPart1_Tamato[] = _("Questa BACCA è incredibilmente");
static const u8 sBerryDescriptionPart2_Tamato[] = _("pepata e lenta a maturare.");
static const u8 sBerryDescriptionPart1_Cornn[] = _("BACCA già conosciuta nell’antichità.");
static const u8 sBerryDescriptionPart2_Cornn[] = _("Cresce solo nelle colture intensive.");
static const u8 sBerryDescriptionPart1_Magost[] = _("BACCA conosciuta come frutto");
static const u8 sBerryDescriptionPart2_Magost[] = _("dal sapore agrodolce bilanciato.");
static const u8 sBerryDescriptionPart1_Rabuta[] = _("Una specie rara ricoperta da una");
static const u8 sBerryDescriptionPart2_Rabuta[] = _("fitta peluria. Sapore piuttosto amaro.");
static const u8 sBerryDescriptionPart1_Nomel[] = _("BACCA asperrima. Assaggiandola non");
static const u8 sBerryDescriptionPart2_Nomel[] = _("si sente più alcun sapore per 3 giorni.");
static const u8 sBerryDescriptionPart1_Spelon[] = _("BACCA rosso vivo. Le protuberanze");
static const u8 sBerryDescriptionPart2_Spelon[] = _("producono una sostanza molto pepata.");
static const u8 sBerryDescriptionPart1_Pamtre[] = _("È portata dalle onde del mare.");
static const u8 sBerryDescriptionPart2_Pamtre[] = _("Pare che cresca altrove.");
static const u8 sBerryDescriptionPart1_Watmel[] = _("Ne è stata scoperta una enorme con");
static const u8 sBerryDescriptionPart2_Watmel[] = _("diametro di 50 cm. È dolcissima.");
static const u8 sBerryDescriptionPart1_Durin[] = _("È talmente amara che nessuno è mai");
static const u8 sBerryDescriptionPart2_Durin[] = _("riuscito a mangiarla così com’è.");
static const u8 sBerryDescriptionPart1_Belue[] = _("È lucida e pare deliziosa, ma in realtà");
static const u8 sBerryDescriptionPart2_Belue[] = _("è molto aspra. Matura lentamente.");
static const u8 sBerryDescriptionPart1_Liechi[] = _("BACCA misteriosa. Si dice che");
static const u8 sBerryDescriptionPart2_Liechi[] = _("abbia in sé la forza del mare.");
static const u8 sBerryDescriptionPart1_Ganlon[] = _("BACCA misteriosa. Si dice che");
static const u8 sBerryDescriptionPart2_Ganlon[] = _("abbia in sé la forza della terra.");
static const u8 sBerryDescriptionPart1_Salac[] = _("BACCA misteriosa. Si dice che");
static const u8 sBerryDescriptionPart2_Salac[] = _("abbia in sé la forza del cielo.");
static const u8 sBerryDescriptionPart1_Petaya[] = _("BACCA misteriosa. Si dice che abbia in");
static const u8 sBerryDescriptionPart2_Petaya[] = _("sé la forza di tutti gli esseri viventi.");
static const u8 sBerryDescriptionPart1_Apicot[] = _("BACCA misteriosa. Non si sa come");
static const u8 sBerryDescriptionPart2_Apicot[] = _("usarla, né i possibili risultati.");
static const u8 sBerryDescriptionPart1_Lansat[] = _("È conosciuta come BACCA leggendaria.");
static const u8 sBerryDescriptionPart2_Lansat[] = _("Pare che porti gioia a chi la tiene.");
static const u8 sBerryDescriptionPart1_Starf[] = _("Quasi mai usata per il suo sapore così");
static const u8 sBerryDescriptionPart2_Starf[] = _("forte. È considerata un miraggio.");
static const u8 sBerryDescriptionPart1_Enigma[] = _("BACCA altamente enigmatica.");
static const u8 sBerryDescriptionPart2_Enigma[] = _("Pare possedere la forza delle stelle.");
#elif SPANISH
static const u8 sBerryDescriptionPart1_Cheri[] = _("Florece con bellas y delicadas flores.");
static const u8 sBerryDescriptionPart2_Cheri[] = _("Es de color rojo vivo y sabor picante.");
static const u8 sBerryDescriptionPart1_Chesto[] = _("Tiene la cáscara y el fruto duros.");
static const u8 sBerryDescriptionPart2_Chesto[] = _("No es nada jugosa.");
static const u8 sBerryDescriptionPart1_Pecha[] = _("Es dulce, rica y muy tierna.");
static const u8 sBerryDescriptionPart2_Pecha[] = _("Es muy delicada.");
static const u8 sBerryDescriptionPart1_Rawst[] = _("Si las hojas crecen mucho y se rizan,");
static const u8 sBerryDescriptionPart2_Rawst[] = _("el sabor de la BAYA se vuelve amargo.");
static const u8 sBerryDescriptionPart1_Aspear[] = _("Esta BAYA es dura y densa.");
static const u8 sBerryDescriptionPart2_Aspear[] = _("Da mucho zumo. Sabe bastante ácida.");
static const u8 sBerryDescriptionPart1_Leppa[] = _("Crece más despacio que otras BAYAS.");
static const u8 sBerryDescriptionPart2_Leppa[] = _("Cuanto más pequeña, más sabrosa.");
static const u8 sBerryDescriptionPart1_Oran[] = _("Es una BAYA particular. Crece en");
static const u8 sBerryDescriptionPart2_Oran[] = _("medio día y tiene mezcla de sabores.");
static const u8 sBerryDescriptionPart1_Persim[] = _("Le encanta el sol. Si está expuesta");
static const u8 sBerryDescriptionPart2_Persim[] = _("a él, el color de la piel se intensifica.");
static const u8 sBerryDescriptionPart1_Lum[] = _("Crece despacio. Si se cuida");
static const u8 sBerryDescriptionPart2_Lum[] = _("con cariño, puede dar dos brotes.");
static const u8 sBerryDescriptionPart1_Sitrus[] = _("Es de la familia de la ARANJA.");
static const u8 sBerryDescriptionPart2_Sitrus[] = _("Tiene un sabor bastante redondo.");
static const u8 sBerryDescriptionPart1_Figy[] = _("Tiene pinta de estar ya masticada.");
static const u8 sBerryDescriptionPart2_Figy[] = _("La pulpa tiene un sabor muy intenso.");
static const u8 sBerryDescriptionPart1_Wiki[] = _("Dicen que crece granulosa para que");
static const u8 sBerryDescriptionPart2_Wiki[] = _("los POKéMON puedan agarrarla mejor.");
static const u8 sBerryDescriptionPart1_Mago[] = _("Se va curvando durante su desarrollo");
static const u8 sBerryDescriptionPart2_Mago[] = _("tornándose más dulce y sabrosa.");
static const u8 sBerryDescriptionPart1_Aguav[] = _("La flor es exquisita. Su habilidad");
static const u8 sBerryDescriptionPart2_Aguav[] = _("para crecer sin luz la hace única.");
static const u8 sBerryDescriptionPart1_Iapapa[] = _("La BAYA es muy grande y ácida.");
static const u8 sBerryDescriptionPart2_Iapapa[] = _("Tarda al menos un día en crecer.");
static const u8 sBerryDescriptionPart1_Razz[] = _("La BAYA es roja y un pelín picante.");
static const u8 sBerryDescriptionPart2_Razz[] = _("Crece rápido, en sólo cuatro horas.");
static const u8 sBerryDescriptionPart1_Bluk[] = _("Por fuera es azul, pero te teñirá");
static const u8 sBerryDescriptionPart2_Bluk[] = _("de negro la boca si te la comes.");
static const u8 sBerryDescriptionPart1_Nanab[] = _("Ésta es la séptima BAYA descubierta");
static const u8 sBerryDescriptionPart2_Nanab[] = _("en todo el mundo. Es muy dulce.");
static const u8 sBerryDescriptionPart1_Wepear[] = _("La flor es pequeña y blanca. Tiene un");
static const u8 sBerryDescriptionPart2_Wepear[] = _("punto ácido y amargo al mismo tiempo.");
static const u8 sBerryDescriptionPart1_Pinap[] = _("Es muy débil ante el frío y el viento.");
static const u8 sBerryDescriptionPart2_Pinap[] = _("La pulpa es picante; y la piel, ácida.");
static const u8 sBerryDescriptionPart1_Pomeg[] = _("Se use la cantidad de agua que se use,");
static const u8 sBerryDescriptionPart2_Pomeg[] = _("siempre crecen seis BAYAS.");
static const u8 sBerryDescriptionPart1_Kelpsy[] = _("Ésta es una especie muy rara. Tiene");
static const u8 sBerryDescriptionPart2_Kelpsy[] = _("forma de raíz y da una flor grande.");
static const u8 sBerryDescriptionPart1_Qualot[] = _("Le encanta el agua. Crece más fuerte");
static const u8 sBerryDescriptionPart2_Qualot[] = _("donde hay continuas precipitaciones.");
static const u8 sBerryDescriptionPart1_Hondew[] = _("Es una BAYA carísima y muy poco");
static const u8 sBerryDescriptionPart2_Hondew[] = _("frecuente. Está exquisita.");
static const u8 sBerryDescriptionPart1_Grepa[] = _("Es tierna y redondita, pero de una");
static const u8 sBerryDescriptionPart2_Grepa[] = _("acidez increíble.");
static const u8 sBerryDescriptionPart1_Tamato[] = _("Está tan picante que hace que te arda");
static const u8 sBerryDescriptionPart2_Tamato[] = _("la boca. Tarda mucho en crecer.");
static const u8 sBerryDescriptionPart1_Cornn[] = _("Data de tiempos remotos. Puede que");
static const u8 sBerryDescriptionPart2_Cornn[] = _("no crezca si no se plantan muchas.");
static const u8 sBerryDescriptionPart1_Magost[] = _("Todo el mundo dice que su sabor");
static const u8 sBerryDescriptionPart2_Magost[] = _("guarda un equilibrio exquisito.");
static const u8 sBerryDescriptionPart1_Rabuta[] = _("Variedad muy poco común, recubierta");
static const u8 sBerryDescriptionPart2_Rabuta[] = _("de pelusa, y de sabor muy amargo.");
static const u8 sBerryDescriptionPart1_Nomel[] = _("Es muy ácida. Con sólo darle un bocado,");
static const u8 sBerryDescriptionPart2_Nomel[] = _("te deja sin paladar tres días.");
static const u8 sBerryDescriptionPart1_Spelon[] = _("Es de color rojo fuerte. Por los gránu-");
static const u8 sBerryDescriptionPart2_Spelon[] = _("los de la piel segrega jugo picante.");
static const u8 sBerryDescriptionPart1_Pamtre[] = _("No se está seguro de su procedencia.");
static const u8 sBerryDescriptionPart2_Pamtre[] = _("Flota a la deriva por el mar.");
static const u8 sBerryDescriptionPart1_Watmel[] = _("Es enorme. Algunas miden más de medio");
static const u8 sBerryDescriptionPart2_Watmel[] = _("metro. Es tremendamente dulce.");
static const u8 sBerryDescriptionPart1_Durin[] = _("Resulta amarga sólo con verla.");
static const u8 sBerryDescriptionPart2_Durin[] = _("Nadie se ha atrevido a probarla sola.");
static const u8 sBerryDescriptionPart1_Belue[] = _("Es brillante y tiene buena pinta, pero");
static const u8 sBerryDescriptionPart2_Belue[] = _("es más que ácida. Tarda en crecer.");
static const u8 sBerryDescriptionPart1_Liechi[] = _("Es misteriosa. Se dice que contiene");
static const u8 sBerryDescriptionPart2_Liechi[] = _("la fuerza del mar.");
static const u8 sBerryDescriptionPart1_Ganlon[] = _("Es intrigante. Se dice que contiene");
static const u8 sBerryDescriptionPart2_Ganlon[] = _("la fuerza de la tierra.");
static const u8 sBerryDescriptionPart1_Salac[] = _("Es muy rara. Se dice que contiene");
static const u8 sBerryDescriptionPart2_Salac[] = _("la fuerza del cielo.");
static const u8 sBerryDescriptionPart1_Petaya[] = _("Es misteriosa. Se dice que contiene");
static const u8 sBerryDescriptionPart2_Petaya[] = _("la fuerza de la vida.");
static const u8 sBerryDescriptionPart1_Apicot[] = _("Es extraña. No se sabe qué efectos");
static const u8 sBerryDescriptionPart2_Apicot[] = _("puede tener ni cómo se puede usar.");
static const u8 sBerryDescriptionPart1_Lansat[] = _("Se dice que es una BAYA legendaria.");
static const u8 sBerryDescriptionPart2_Lansat[] = _("Puede que haga feliz a su portador.");
static const u8 sBerryDescriptionPart1_Starf[] = _("Es tan fuerte que la dejaron en los");
static const u8 sBerryDescriptionPart2_Starf[] = _("confines del mundo. ¿Será de verdad?");
static const u8 sBerryDescriptionPart1_Enigma[] = _("Es enigmática. Dicen que encierra");
static const u8 sBerryDescriptionPart2_Enigma[] = _("la fuerza de las estrellas.");
#else //ENGLISH
static const u8 sBerryDescriptionPart1_Cheri[] = _("Blooms with delicate pretty flowers.");
static const u8 sBerryDescriptionPart2_Cheri[] = _("The bright red BERRY is very spicy.");
static const u8 sBerryDescriptionPart1_Chesto[] = _("The BERRY's thick skin and fruit are");
static const u8 sBerryDescriptionPart2_Chesto[] = _("very tough. It is dry-tasting all over.");
static const u8 sBerryDescriptionPart1_Pecha[] = _("Very sweet and delicious.");
static const u8 sBerryDescriptionPart2_Pecha[] = _("Also very tender - handle with care.");
static const u8 sBerryDescriptionPart1_Rawst[] = _("If the leaves grow long and curly,");
static const u8 sBerryDescriptionPart2_Rawst[] = _("the BERRY seems to grow very bitter.");
static const u8 sBerryDescriptionPart1_Aspear[] = _("The hard BERRY is dense with a rich");
static const u8 sBerryDescriptionPart2_Aspear[] = _("juice. It is quite sour.");
static const u8 sBerryDescriptionPart1_Leppa[] = _("Grows slower than CHERI and others.");
static const u8 sBerryDescriptionPart2_Leppa[] = _("The smaller the BERRY, the tastier.");
static const u8 sBerryDescriptionPart1_Oran[] = _("A peculiar BERRY with a mix of flavors.");
static const u8 sBerryDescriptionPart2_Oran[] = _("BERRIES grow in half a day.");
static const u8 sBerryDescriptionPart1_Persim[] = _("Loves sunlight. The BERRY's color");
static const u8 sBerryDescriptionPart2_Persim[] = _("grows vivid when exposed to the sun.");
static const u8 sBerryDescriptionPart1_Lum[] = _("Slow to grow. If raised with loving");
static const u8 sBerryDescriptionPart2_Lum[] = _("care, it may grow two BERRIES.");
static const u8 sBerryDescriptionPart1_Sitrus[] = _("Closely related to ORAN. The large");
static const u8 sBerryDescriptionPart2_Sitrus[] = _("BERRY has a well-rounded flavor.");
static const u8 sBerryDescriptionPart1_Figy[] = _("The BERRY, which looks chewed up,");
static const u8 sBerryDescriptionPart2_Figy[] = _("brims with spicy substances.");
static const u8 sBerryDescriptionPart1_Wiki[] = _("The BERRY is said to have grown lumpy");
static const u8 sBerryDescriptionPart2_Wiki[] = _("to help POKéMON grip it.");
static const u8 sBerryDescriptionPart1_Mago[] = _("The BERRY turns curvy as it grows.");
static const u8 sBerryDescriptionPart2_Mago[] = _("The curvier, the sweeter and tastier.");
static const u8 sBerryDescriptionPart1_Aguav[] = _("The flower is dainty. It is rare in its");
static const u8 sBerryDescriptionPart2_Aguav[] = _("ability to grow without light.");
static const u8 sBerryDescriptionPart1_Iapapa[] = _("The BERRY is very big and sour.");
static const u8 sBerryDescriptionPart2_Iapapa[] = _("It takes at least a day to grow.");
static const u8 sBerryDescriptionPart1_Razz[] = _("The red BERRY tastes slightly spicy.");
static const u8 sBerryDescriptionPart2_Razz[] = _("It grows quickly in just four hours.");
static const u8 sBerryDescriptionPart1_Bluk[] = _("The BERRY is blue on the outside, but");
static const u8 sBerryDescriptionPart2_Bluk[] = _("it blackens the mouth when eaten.");
static const u8 sBerryDescriptionPart1_Nanab[] = _("This BERRY was the seventh");
static const u8 sBerryDescriptionPart2_Nanab[] = _("discovered in the world. It is sweet.");
static const u8 sBerryDescriptionPart1_Wepear[] = _("The flower is small and white. It has a");
static const u8 sBerryDescriptionPart2_Wepear[] = _("delicate balance of bitter and sour.");
static const u8 sBerryDescriptionPart1_Pinap[] = _("Weak against wind and cold.");
static const u8 sBerryDescriptionPart2_Pinap[] = _("The fruit is spicy and the skin, sour.");
static const u8 sBerryDescriptionPart1_Pomeg[] = _("However much it is watered,");
static const u8 sBerryDescriptionPart2_Pomeg[] = _("it only grows up to six BERRIES.");
static const u8 sBerryDescriptionPart1_Kelpsy[] = _("A rare variety shaped like a root.");
static const u8 sBerryDescriptionPart2_Kelpsy[] = _("Grows a very large flower.");
static const u8 sBerryDescriptionPart1_Qualot[] = _("Loves water. Grows strong even in");
static const u8 sBerryDescriptionPart2_Qualot[] = _("locations with constant rainfall.");
static const u8 sBerryDescriptionPart1_Hondew[] = _("A BERRY that is very valuable and");
static const u8 sBerryDescriptionPart2_Hondew[] = _("rarely seen. It is very delicious.");
static const u8 sBerryDescriptionPart1_Grepa[] = _("Despite its tenderness and round");
static const u8 sBerryDescriptionPart2_Grepa[] = _("shape, the BERRY is unimaginably sour.");
static const u8 sBerryDescriptionPart1_Tamato[] = _("The BERRY is lip-bendingly spicy.");
static const u8 sBerryDescriptionPart2_Tamato[] = _("It takes time to grow.");
static const u8 sBerryDescriptionPart1_Cornn[] = _("A BERRY from an ancient era. May not");
static const u8 sBerryDescriptionPart2_Cornn[] = _("grow unless planted in quantity.");
static const u8 sBerryDescriptionPart1_Magost[] = _("A BERRY that is widely said to have");
static const u8 sBerryDescriptionPart2_Magost[] = _("a finely balanced flavor.");
static const u8 sBerryDescriptionPart1_Rabuta[] = _("A rare variety that is overgrown with");
static const u8 sBerryDescriptionPart2_Rabuta[] = _("hair. It is quite bitter.");
static const u8 sBerryDescriptionPart1_Nomel[] = _("Quite sour. Just one bite makes it");
static const u8 sBerryDescriptionPart2_Nomel[] = _("impossible to taste for three days.");
static const u8 sBerryDescriptionPart1_Spelon[] = _("The vividly red BERRY is very spicy.");
static const u8 sBerryDescriptionPart2_Spelon[] = _("Its warts secrete a spicy substance.");
static const u8 sBerryDescriptionPart1_Pamtre[] = _("Drifts on the sea from somewhere.");
static const u8 sBerryDescriptionPart2_Pamtre[] = _("It is thought to grow elsewhere.");
static const u8 sBerryDescriptionPart1_Watmel[] = _("A huge BERRY, with some over 20");
static const u8 sBerryDescriptionPart2_Watmel[] = _("inches discovered. Exceedingly sweet.");
static const u8 sBerryDescriptionPart1_Durin[] = _("Bitter to even look at. It is so");
static const u8 sBerryDescriptionPart2_Durin[] = _("bitter, no one has ever eaten it as is.");
static const u8 sBerryDescriptionPart1_Belue[] = _("It is glossy and looks delicious, but");
static const u8 sBerryDescriptionPart2_Belue[] = _("it is awfully sour. Takes time to grow.");
static const u8 sBerryDescriptionPart1_Liechi[] = _("A mysterious BERRY. It is rumored to");
static const u8 sBerryDescriptionPart2_Liechi[] = _("contain the power of the sea.");
static const u8 sBerryDescriptionPart1_Ganlon[] = _("A mysterious BERRY. It is rumored to");
static const u8 sBerryDescriptionPart2_Ganlon[] = _("contain the power of the land.");
static const u8 sBerryDescriptionPart1_Salac[] = _("A mysterious BERRY. It is rumored to");
static const u8 sBerryDescriptionPart2_Salac[] = _("contain the power of the sky.");
static const u8 sBerryDescriptionPart1_Petaya[] = _("A mysterious BERRY. It is rumored to");
static const u8 sBerryDescriptionPart2_Petaya[] = _("contain the power of all living things.");
static const u8 sBerryDescriptionPart1_Apicot[] = _("A very mystifying BERRY. No telling");
static const u8 sBerryDescriptionPart2_Apicot[] = _("what may happen or how it can be used.");
static const u8 sBerryDescriptionPart1_Lansat[] = _("Said to be a legendary BERRY.");
static const u8 sBerryDescriptionPart2_Lansat[] = _("Holding it supposedly brings joy.");
static const u8 sBerryDescriptionPart1_Starf[] = _("So strong, it was abandoned at the");
static const u8 sBerryDescriptionPart2_Starf[] = _("world's edge. Considered a mirage.");
static const u8 sBerryDescriptionPart1_Enigma[] = _("A completely enigmatic BERRY.");
static const u8 sBerryDescriptionPart2_Enigma[] = _("Appears to have the power of stars.");
#endif

const struct Berry gBerries[] =
{
    [ITEM_CHERI_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = LANGUAGE_STRING("CHERI", "CERIZ", "LIEGIA", "ZREZA"),
        .firmness = BERRY_FIRMNESS_SOFT,
        .size = 20,
        .maxYield = 3,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Cheri,
        .description2 = sBerryDescriptionPart2_Cheri,
        .stageDuration = 3,
        .spicy = 10,
        .dry = 0,
        .sweet = 0,
        .bitter = 0,
        .sour = 0,
        .smoothness = 25,
    },

    [ITEM_CHESTO_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = LANGUAGE_STRING("CHESTO", "MARON", "STAGNA", "ATANIA"),
        .firmness = BERRY_FIRMNESS_SUPER_HARD,
        .size = 80,
        .maxYield = 3,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Chesto,
        .description2 = sBerryDescriptionPart2_Chesto,
        .stageDuration = 3,
        .spicy = 0,
        .dry = 10,
        .sweet = 0,
        .bitter = 0,
        .sour = 0,
        .smoothness = 25,
    },

    [ITEM_PECHA_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = LANGUAGE_STRING("PECHA", "PECHA", "PESCA", "MELOC"),
        .firmness = BERRY_FIRMNESS_VERY_SOFT,
        .size = 40,
        .maxYield = 3,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Pecha,
        .description2 = sBerryDescriptionPart2_Pecha,
        .stageDuration = 3,
        .spicy = 0,
        .dry = 0,
        .sweet = 10,
        .bitter = 0,
        .sour = 0,
        .smoothness = 25,
    },

    [ITEM_RAWST_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = LANGUAGE_STRING("RAWST", "FRAIVE", "FRAGO", "SAFRE"),
        .firmness = BERRY_FIRMNESS_HARD,
        .size = 32,
        .maxYield = 3,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Rawst,
        .description2 = sBerryDescriptionPart2_Rawst,
        .stageDuration = 3,
        .spicy = 0,
        .dry = 0,
        .sweet = 0,
        .bitter = 10,
        .sour = 0,
        .smoothness = 25,
    },

    [ITEM_ASPEAR_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = LANGUAGE_STRING("ASPEAR", "WILLIA", "PERINA", "PERASI"),
        .firmness = BERRY_FIRMNESS_SUPER_HARD,
        .size = 50,
        .maxYield = 3,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Aspear,
        .description2 = sBerryDescriptionPart2_Aspear,
        .stageDuration = 3,
        .spicy = 0,
        .dry = 0,
        .sweet = 0,
        .bitter = 0,
        .sour = 10,
        .smoothness = 25,
    },

    [ITEM_LEPPA_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = LANGUAGE_STRING("LEPPA", "MEPO", "MELA", "ZANAMA"),
        .firmness = BERRY_FIRMNESS_VERY_HARD,
        .size = 28,
        .maxYield = 3,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Leppa,
        .description2 = sBerryDescriptionPart2_Leppa,
        .stageDuration = 4,
        .spicy = 10,
        .dry = 0,
        .sweet = 10,
        .bitter = 10,
        .sour = 10,
        .smoothness = 20,
    },

    [ITEM_ORAN_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = LANGUAGE_STRING("ORAN", "ORAN", "RANCIA", "ARANJA"),
        .firmness = BERRY_FIRMNESS_SUPER_HARD,
        .size = 35,
        .maxYield = 3,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Oran,
        .description2 = sBerryDescriptionPart2_Oran,
        .stageDuration = 3,
        .spicy = 10,
        .dry = 10,
        .sweet = 10,
        .bitter = 10,
        .sour = 10,
        .smoothness = 20,
    },

    [ITEM_PERSIM_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = LANGUAGE_STRING("PERSIM", "KIKA", "KI", "CAQUIC"),
        .firmness = BERRY_FIRMNESS_HARD,
        .size = 47,
        .maxYield = 3,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Persim,
        .description2 = sBerryDescriptionPart2_Persim,
        .stageDuration = 3,
        .spicy = 10,
        .dry = 10,
        .sweet = 10,
        .bitter = 10,
        .sour = 10,
        .smoothness = 20,
    },

    [ITEM_LUM_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = LANGUAGE_STRING("LUM", "PRINE", "PRUGNA", "ZIUELA"),
        .firmness = BERRY_FIRMNESS_SUPER_HARD,
        .size = 34,
        .maxYield = 2,
        .minYield = 1,
        .description1 = sBerryDescriptionPart1_Lum,
        .description2 = sBerryDescriptionPart2_Lum,
        .stageDuration = 12,
        .spicy = 10,
        .dry = 10,
        .sweet = 10,
        .bitter = 10,
        .sour = 10,
        .smoothness = 20,
    },

    [ITEM_SITRUS_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = LANGUAGE_STRING("SITRUS", "SITRUS", "CEDRO", "ZIDRA"),
        .firmness = BERRY_FIRMNESS_VERY_HARD,
        .size = 95,
        .maxYield = 3,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Sitrus,
        .description2 = sBerryDescriptionPart2_Sitrus,
        .stageDuration = 6,
        .spicy = 10,
        .dry = 10,
        .sweet = 10,
        .bitter = 10,
        .sour = 10,
        .smoothness = 20,
    },

    [ITEM_FIGY_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = LANGUAGE_STRING("FIGY", "FIGUY", "FICO", "HIGOG"),
        .firmness = BERRY_FIRMNESS_SOFT,
        .size = 100,
        .maxYield = 3,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Figy,
        .description2 = sBerryDescriptionPart2_Figy,
        .stageDuration = 6,
        .spicy = 10,
        .dry = 0,
        .sweet = 0,
        .bitter = 0,
        .sour = 0,
        .smoothness = 25,
    },

    [ITEM_WIKI_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = LANGUAGE_STRING("WIKI", "WIKI", "KIWI", "WIKI"),
        .firmness = BERRY_FIRMNESS_HARD,
        .size = 115,
        .maxYield = 3,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Wiki,
        .description2 = sBerryDescriptionPart2_Wiki,
        .stageDuration = 6,
        .spicy = 0,
        .dry = 10,
        .sweet = 0,
        .bitter = 0,
        .sour = 0,
        .smoothness = 25,
    },

    [ITEM_MAGO_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = LANGUAGE_STRING("MAGO", "MAGO", "MANGO", "ANGO"),
        .firmness = BERRY_FIRMNESS_HARD,
        .size = 126,
        .maxYield = 3,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Mago,
        .description2 = sBerryDescriptionPart2_Mago,
        .stageDuration = 6,
        .spicy = 0,
        .dry = 0,
        .sweet = 10,
        .bitter = 0,
        .sour = 0,
        .smoothness = 25,
    },

    [ITEM_AGUAV_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = LANGUAGE_STRING("AGUAV", "GOWAV", "GUAVA", "GUAYA"),
        .firmness = BERRY_FIRMNESS_SUPER_HARD,
        .size = 64,
        .maxYield = 3,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Aguav,
        .description2 = sBerryDescriptionPart2_Aguav,
        .stageDuration = 6,
        .spicy = 0,
        .dry = 0,
        .sweet = 0,
        .bitter = 10,
        .sour = 0,
        .smoothness = 25,
    },

    [ITEM_IAPAPA_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = LANGUAGE_STRING("IAPAPA", "PAPAYA", "PAIA", "PABAYA"),
        .firmness = BERRY_FIRMNESS_SOFT,
        .size = 223,
        .maxYield = 3,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Iapapa,
        .description2 = sBerryDescriptionPart2_Iapapa,
        .stageDuration = 6,
        .spicy = 0,
        .dry = 0,
        .sweet = 0,
        .bitter = 0,
        .sour = 10,
        .smoothness = 25,
    },

    [ITEM_RAZZ_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = LANGUAGE_STRING("RAZZ", "FRAMBY", "LAMPON", "FRAMBU"),
        .firmness = BERRY_FIRMNESS_VERY_HARD,
        .size = 120,
        .maxYield = 6,
        .minYield = 3,
        .description1 = sBerryDescriptionPart1_Razz,
        .description2 = sBerryDescriptionPart2_Razz,
        .stageDuration = 1,
        .spicy = 10,
        .dry = 10,
        .sweet = 0,
        .bitter = 0,
        .sour = 0,
        .smoothness = 20,
    },

    [ITEM_BLUK_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = LANGUAGE_STRING("BLUK", "REMU", "MORA", "ORAM"),
        .firmness = BERRY_FIRMNESS_SOFT,
        .size = 108,
        .maxYield = 6,
        .minYield = 3,
        .description1 = sBerryDescriptionPart1_Bluk,
        .description2 = sBerryDescriptionPart2_Bluk,
        .stageDuration = 1,
        .spicy = 0,
        .dry = 10,
        .sweet = 10,
        .bitter = 0,
        .sour = 0,
        .smoothness = 20,
    },

    [ITEM_NANAB_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = LANGUAGE_STRING("NANAB", "NANAB", "BANA", "LATANO"),
        .firmness = BERRY_FIRMNESS_VERY_HARD,
        .size = 77,
        .maxYield = 6,
        .minYield = 3,
        .description1 = sBerryDescriptionPart1_Nanab,
        .description2 = sBerryDescriptionPart2_Nanab,
        .stageDuration = 1,
        .spicy = 0,
        .dry = 0,
        .sweet = 10,
        .bitter = 10,
        .sour = 0,
        .smoothness = 20,
    },

    [ITEM_WEPEAR_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = LANGUAGE_STRING("WEPEAR", "REPOI", "PERA", "PERAGU"),
        .firmness = BERRY_FIRMNESS_SUPER_HARD,
        .size = 74,
        .maxYield = 6,
        .minYield = 3,
        .description1 = sBerryDescriptionPart1_Wepear,
        .description2 = sBerryDescriptionPart2_Wepear,
        .stageDuration = 1,
        .spicy = 0,
        .dry = 0,
        .sweet = 0,
        .bitter = 10,
        .sour = 10,
        .smoothness = 20,
    },

    [ITEM_PINAP_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = LANGUAGE_STRING("PINAP", "NANANA", "NANAS", "PINIA"),
        .firmness = BERRY_FIRMNESS_HARD,
        .size = 80,
        .maxYield = 6,
        .minYield = 3,
        .description1 = sBerryDescriptionPart1_Pinap,
        .description2 = sBerryDescriptionPart2_Pinap,
        .stageDuration = 1,
        .spicy = 10,
        .dry = 0,
        .sweet = 0,
        .bitter = 0,
        .sour = 10,
        .smoothness = 20,
    },

    [ITEM_POMEG_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = LANGUAGE_STRING("POMEG", "GRENA", "GRANA", "GRANA"),
        .firmness = BERRY_FIRMNESS_VERY_HARD,
        .size = 135,
        .maxYield = 6,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Pomeg,
        .description2 = sBerryDescriptionPart2_Pomeg,
        .stageDuration = 3,
        .spicy = 10,
        .dry = 0,
        .sweet = 10,
        .bitter = 10,
        .sour = 0,
        .smoothness = 20,
    },

    [ITEM_KELPSY_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = LANGUAGE_STRING("KELPSY", "ALGA", "LGA", "ALGAMA"),
        .firmness = BERRY_FIRMNESS_HARD,
        .size = 150,
        .maxYield = 6,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Kelpsy,
        .description2 = sBerryDescriptionPart2_Kelpsy,
        .stageDuration = 3,
        .spicy = 0,
        .dry = 10,
        .sweet = 0,
        .bitter = 10,
        .sour = 10,
        .smoothness = 20,
    },

    [ITEM_QUALOT_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = LANGUAGE_STRING("QUALOT", "QUALOT", "LOQUAT", "ISPERO"),
        .firmness = BERRY_FIRMNESS_HARD,
        .size = 110,
        .maxYield = 6,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Qualot,
        .description2 = sBerryDescriptionPart2_Qualot,
        .stageDuration = 3,
        .spicy = 10,
        .dry = 0,
        .sweet = 10,
        .bitter = 0,
        .sour = 10,
        .smoothness = 20,
    },

    [ITEM_HONDEW_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = LANGUAGE_STRING("HONDEW", "LONME", "MELON", "MELUCE"),
        .firmness = BERRY_FIRMNESS_HARD,
        .size = 162,
        .maxYield = 6,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Hondew,
        .description2 = sBerryDescriptionPart2_Hondew,
        .stageDuration = 3,
        .spicy = 10,
        .dry = 10,
        .sweet = 0,
        .bitter = 10,
        .sour = 0,
        .smoothness = 20,
    },

    [ITEM_GREPA_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = LANGUAGE_STRING("GREPA", "RESIN", "UVA", "UVAV"),
        .firmness = BERRY_FIRMNESS_SOFT,
        .size = 149,
        .maxYield = 6,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Grepa,
        .description2 = sBerryDescriptionPart2_Grepa,
        .stageDuration = 3,
        .spicy = 0,
        .dry = 10,
        .sweet = 10,
        .bitter = 0,
        .sour = 10,
        .smoothness = 20,
    },

    [ITEM_TAMATO_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = LANGUAGE_STRING("TAMATO", "TAMATO", "MODORO", "TAMATE"),
        .firmness = BERRY_FIRMNESS_SOFT,
        .size = 200,
        .maxYield = 4,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Tamato,
        .description2 = sBerryDescriptionPart2_Tamato,
        .stageDuration = 6,
        .spicy = 20,
        .dry = 10,
        .sweet = 0,
        .bitter = 0,
        .sour = 0,
        .smoothness = 30,
    },

    [ITEM_CORNN_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = LANGUAGE_STRING("CORNN", "SIAM", "VENA", "MAIS"),
        .firmness = BERRY_FIRMNESS_HARD,
        .size = 75,
        .maxYield = 4,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Cornn,
        .description2 = sBerryDescriptionPart2_Cornn,
        .stageDuration = 6,
        .spicy = 0,
        .dry = 20,
        .sweet = 10,
        .bitter = 0,
        .sour = 0,
        .smoothness = 30,
    },

    [ITEM_MAGOST_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = LANGUAGE_STRING("MAGOST", "MANGOU", "GOSTAN", "AOSTAN"),
        .firmness = BERRY_FIRMNESS_HARD,
        .size = 140,
        .maxYield = 4,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Magost,
        .description2 = sBerryDescriptionPart2_Magost,
        .stageDuration = 6,
        .spicy = 0,
        .dry = 0,
        .sweet = 20,
        .bitter = 10,
        .sour = 0,
        .smoothness = 30,
    },

    [ITEM_RABUTA_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = LANGUAGE_STRING("RABUTA", "RABUTA", "MBUTAN", "RAUTAN"),
        .firmness = BERRY_FIRMNESS_SOFT,
        .size = 226,
        .maxYield = 4,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Rabuta,
        .description2 = sBerryDescriptionPart2_Rabuta,
        .stageDuration = 6,
        .spicy = 0,
        .dry = 0,
        .sweet = 0,
        .bitter = 20,
        .sour = 10,
        .smoothness = 30,
    },

    [ITEM_NOMEL_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = LANGUAGE_STRING("NOMEL", "TRONCI", "LEMON", "MONLI"),
        .firmness = BERRY_FIRMNESS_SUPER_HARD,
        .size = 285,
        .maxYield = 4,
        .minYield = 2,
        .description1 = sBerryDescriptionPart1_Nomel,
        .description2 = sBerryDescriptionPart2_Nomel,
        .stageDuration = 6,
        .spicy = 10,
        .dry = 0,
        .sweet = 0,
        .bitter = 0,
        .sour = 20,
        .smoothness = 30,
    },

    [ITEM_SPELON_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = LANGUAGE_STRING("SPELON", "KIWAN", "MELOS", "WIKANO"),
        .firmness = BERRY_FIRMNESS_SOFT,
        .size = 133,
        .maxYield = 2,
        .minYield = 1,
        .description1 = sBerryDescriptionPart1_Spelon,
        .description2 = sBerryDescriptionPart2_Spelon,
        .stageDuration = 18,
        .spicy = 40,
        .dry = 10,
        .sweet = 0,
        .bitter = 0,
        .sour = 0,
        .smoothness = 70,
    },

    [ITEM_PAMTRE_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = LANGUAGE_STRING("PAMTRE", "PALMA", "PALMA", "PLAMA"),
        .firmness = BERRY_FIRMNESS_VERY_SOFT,
        .size = 244,
        .maxYield = 2,
        .minYield = 1,
        .description1 = sBerryDescriptionPart1_Pamtre,
        .description2 = sBerryDescriptionPart2_Pamtre,
        .stageDuration = 18,
        .spicy = 0,
        .dry = 40,
        .sweet = 10,
        .bitter = 0,
        .sour = 0,
        .smoothness = 70,
    },

    [ITEM_WATMEL_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = LANGUAGE_STRING("WATMEL", "STEKPA", "COMERO", "SAMBIA"),
        .firmness = BERRY_FIRMNESS_SOFT,
        .size = 250,
        .maxYield = 2,
        .minYield = 1,
        .description1 = sBerryDescriptionPart1_Watmel,
        .description2 = sBerryDescriptionPart2_Watmel,
        .stageDuration = 18,
        .spicy = 0,
        .dry = 0,
        .sweet = 40,
        .bitter = 10,
        .sour = 0,
        .smoothness = 70,
    },

    [ITEM_DURIN_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = LANGUAGE_STRING("DURIN", "DURIN", "DURIAN", "RUDION"),
        .firmness = BERRY_FIRMNESS_HARD,
        .size = 280,
        .maxYield = 2,
        .minYield = 1,
        .description1 = sBerryDescriptionPart1_Durin,
        .description2 = sBerryDescriptionPart2_Durin,
        .stageDuration = 18,
        .spicy = 0,
        .dry = 0,
        .sweet = 0,
        .bitter = 40,
        .sour = 10,
        .smoothness = 70,
    },

    [ITEM_BELUE_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = LANGUAGE_STRING("BELUE", "MYRTE", "RTILLO", "ANDANO"),
        .firmness = BERRY_FIRMNESS_VERY_SOFT,
        .size = 300,
        .maxYield = 2,
        .minYield = 1,
        .description1 = sBerryDescriptionPart1_Belue,
        .description2 = sBerryDescriptionPart2_Belue,
        .stageDuration = 18,
        .spicy = 10,
        .dry = 0,
        .sweet = 0,
        .bitter = 0,
        .sour = 40,
        .smoothness = 70,
    },

    [ITEM_LIECHI_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = LANGUAGE_STRING("LIECHI", "LICHII", "LICI", "LICHI"),
        .firmness = BERRY_FIRMNESS_VERY_HARD,
        .size = 111,
        .maxYield = 2,
        .minYield = 1,
        .description1 = sBerryDescriptionPart1_Liechi,
        .description2 = sBerryDescriptionPart2_Liechi,
        .stageDuration = 24,
        .spicy = 40,
        .dry = 0,
        .sweet = 40,
        .bitter = 0,
        .sour = 10,
        .smoothness = 80,
    },

    [ITEM_GANLON_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = LANGUAGE_STRING("GANLON", "LINGAN", "LONGAN", "GONLAN"),
        .firmness = BERRY_FIRMNESS_VERY_HARD,
        .size = 33,
        .maxYield = 2,
        .minYield = 1,
        .description1 = sBerryDescriptionPart1_Ganlon,
        .description2 = sBerryDescriptionPart2_Ganlon,
        .stageDuration = 24,
        .spicy = 0,
        .dry = 40,
        .sweet = 0,
        .bitter = 40,
        .sour = 0,
        .smoothness = 80,
    },

    [ITEM_SALAC_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = LANGUAGE_STRING("SALAC", "SAILAK", "SALAK", "ASLAC"),
        .firmness = BERRY_FIRMNESS_VERY_HARD,
        .size = 95,
        .maxYield = 2,
        .minYield = 1,
        .description1 = sBerryDescriptionPart1_Salac,
        .description2 = sBerryDescriptionPart2_Salac,
        .stageDuration = 24,
        .spicy = 0,
        .dry = 0,
        .sweet = 40,
        .bitter = 0,
        .sour = 40,
        .smoothness = 80,
    },

    [ITEM_PETAYA_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = LANGUAGE_STRING("PETAYA", "PITAYE", "PITAYA", "YAPATI"),
        .firmness = BERRY_FIRMNESS_VERY_HARD,
        .size = 237,
        .maxYield = 2,
        .minYield = 1,
        .description1 = sBerryDescriptionPart1_Petaya,
        .description2 = sBerryDescriptionPart2_Petaya,
        .stageDuration = 24,
        .spicy = 40,
        .dry = 0,
        .sweet = 0,
        .bitter = 40,
        .sour = 0,
        .smoothness = 80,
    },

    [ITEM_APICOT_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = LANGUAGE_STRING("APICOT", "ABRIKO", "COCCA", "ARICOC"),
        .firmness = BERRY_FIRMNESS_HARD,
        .size = 75,
        .maxYield = 2,
        .minYield = 1,
        .description1 = sBerryDescriptionPart1_Apicot,
        .description2 = sBerryDescriptionPart2_Apicot,
        .stageDuration = 24,
        .spicy = 0,
        .dry = 40,
        .sweet = 0,
        .bitter = 0,
        .sour = 40,
        .smoothness = 80,
    },

    [ITEM_LANSAT_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = LANGUAGE_STRING("LANSAT", "LANSAT", "LANGSA", "ZONLAN"),
        .firmness = BERRY_FIRMNESS_SOFT,
        .size = 97,
        .maxYield = 2,
        .minYield = 1,
        .description1 = sBerryDescriptionPart1_Lansat,
        .description2 = sBerryDescriptionPart2_Lansat,
        .stageDuration = 24,
        .spicy = 10,
        .dry = 10,
        .sweet = 10,
        .bitter = 10,
        .sour = 10,
        .smoothness = 30,
    },

    [ITEM_STARF_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = LANGUAGE_STRING("STARF", "FRISTA", "MBOLA", "ARABOL"),
        .firmness = BERRY_FIRMNESS_SUPER_HARD,
        .size = 153,
        .maxYield = 2,
        .minYield = 1,
        .description1 = sBerryDescriptionPart1_Starf,
        .description2 = sBerryDescriptionPart2_Starf,
        .stageDuration = 24,
        .spicy = 10,
        .dry = 10,
        .sweet = 10,
        .bitter = 10,
        .sour = 10,
        .smoothness = 30,
    },

    [ITEM_ENIGMA_BERRY - FIRST_BERRY_INDEX] =
    {
        .name = _("ENIGMA"),
        .firmness = BERRY_FIRMNESS_UNKNOWN,
        .size = 0,
        .maxYield = 2,
        .minYield = 1,
        .description1 = sBerryDescriptionPart1_Enigma,
        .description2 = sBerryDescriptionPart2_Enigma,
        .stageDuration = 24,
        .spicy = 40,
        .dry = 40,
        .sweet = 40,
        .bitter = 40,
        .sour = 40,
        .smoothness = 40,
    },
};

const struct BerryCrushBerryData gBerryCrush_BerryData[] = {
    [ITEM_CHERI_BERRY - FIRST_BERRY_INDEX]  = {.difficulty =  50, .powder =  20},
    [ITEM_CHESTO_BERRY - FIRST_BERRY_INDEX] = {.difficulty =  50, .powder =  20},
    [ITEM_PECHA_BERRY - FIRST_BERRY_INDEX]  = {.difficulty =  50, .powder =  20},
    [ITEM_RAWST_BERRY - FIRST_BERRY_INDEX]  = {.difficulty =  50, .powder =  20},
    [ITEM_ASPEAR_BERRY - FIRST_BERRY_INDEX] = {.difficulty =  50, .powder =  20},
    [ITEM_LEPPA_BERRY - FIRST_BERRY_INDEX]  = {.difficulty =  50, .powder =  30},
    [ITEM_ORAN_BERRY - FIRST_BERRY_INDEX]   = {.difficulty =  50, .powder =  30},
    [ITEM_PERSIM_BERRY - FIRST_BERRY_INDEX] = {.difficulty =  50, .powder =  30},
    [ITEM_LUM_BERRY - FIRST_BERRY_INDEX]    = {.difficulty =  50, .powder =  30},
    [ITEM_SITRUS_BERRY - FIRST_BERRY_INDEX] = {.difficulty =  50, .powder =  30},
    [ITEM_FIGY_BERRY - FIRST_BERRY_INDEX]   = {.difficulty =  60, .powder =  50},
    [ITEM_WIKI_BERRY - FIRST_BERRY_INDEX]   = {.difficulty =  60, .powder =  50},
    [ITEM_MAGO_BERRY - FIRST_BERRY_INDEX]   = {.difficulty =  60, .powder =  50},
    [ITEM_AGUAV_BERRY - FIRST_BERRY_INDEX]  = {.difficulty =  60, .powder =  50},
    [ITEM_IAPAPA_BERRY - FIRST_BERRY_INDEX] = {.difficulty =  60, .powder =  50},
    [ITEM_RAZZ_BERRY - FIRST_BERRY_INDEX]   = {.difficulty =  80, .powder =  70},
    [ITEM_BLUK_BERRY - FIRST_BERRY_INDEX]   = {.difficulty =  80, .powder =  70},
    [ITEM_NANAB_BERRY - FIRST_BERRY_INDEX]  = {.difficulty =  80, .powder =  70},
    [ITEM_WEPEAR_BERRY - FIRST_BERRY_INDEX] = {.difficulty =  80, .powder =  70},
    [ITEM_PINAP_BERRY - FIRST_BERRY_INDEX]  = {.difficulty =  80, .powder =  70},
    [ITEM_POMEG_BERRY - FIRST_BERRY_INDEX]  = {.difficulty = 100, .powder = 100},
    [ITEM_KELPSY_BERRY - FIRST_BERRY_INDEX] = {.difficulty = 100, .powder = 100},
    [ITEM_QUALOT_BERRY - FIRST_BERRY_INDEX] = {.difficulty = 100, .powder = 100},
    [ITEM_HONDEW_BERRY - FIRST_BERRY_INDEX] = {.difficulty = 100, .powder = 100},
    [ITEM_GREPA_BERRY - FIRST_BERRY_INDEX]  = {.difficulty = 100, .powder = 100},
    [ITEM_TAMATO_BERRY - FIRST_BERRY_INDEX] = {.difficulty = 130, .powder = 150},
    [ITEM_CORNN_BERRY - FIRST_BERRY_INDEX]  = {.difficulty = 130, .powder = 150},
    [ITEM_MAGOST_BERRY - FIRST_BERRY_INDEX] = {.difficulty = 130, .powder = 150},
    [ITEM_RABUTA_BERRY - FIRST_BERRY_INDEX] = {.difficulty = 130, .powder = 150},
    [ITEM_NOMEL_BERRY - FIRST_BERRY_INDEX]  = {.difficulty = 130, .powder = 150},
    [ITEM_SPELON_BERRY - FIRST_BERRY_INDEX] = {.difficulty = 160, .powder = 250},
    [ITEM_PAMTRE_BERRY - FIRST_BERRY_INDEX] = {.difficulty = 160, .powder = 250},
    [ITEM_WATMEL_BERRY - FIRST_BERRY_INDEX] = {.difficulty = 160, .powder = 250},
    [ITEM_DURIN_BERRY - FIRST_BERRY_INDEX]  = {.difficulty = 160, .powder = 250},
    [ITEM_BELUE_BERRY - FIRST_BERRY_INDEX]  = {.difficulty = 160, .powder = 250},
    [ITEM_LIECHI_BERRY - FIRST_BERRY_INDEX] = {.difficulty = 180, .powder = 500},
    [ITEM_GANLON_BERRY - FIRST_BERRY_INDEX] = {.difficulty = 180, .powder = 500},
    [ITEM_SALAC_BERRY - FIRST_BERRY_INDEX]  = {.difficulty = 180, .powder = 500},
    [ITEM_PETAYA_BERRY - FIRST_BERRY_INDEX] = {.difficulty = 180, .powder = 500},
    [ITEM_APICOT_BERRY - FIRST_BERRY_INDEX] = {.difficulty = 180, .powder = 500},
    [ITEM_LANSAT_BERRY - FIRST_BERRY_INDEX] = {.difficulty = 200, .powder = 750},
    [ITEM_STARF_BERRY - FIRST_BERRY_INDEX]  = {.difficulty = 200, .powder = 750},
    [ITEM_ENIGMA_BERRY - FIRST_BERRY_INDEX] = {.difficulty = 150, .powder = 200}
};

const struct BerryTree gBlankBerryTree = {};

// unused
void ClearEnigmaBerries(void)
{
    CpuFill16(0, &gSaveBlock1Ptr->enigmaBerry, sizeof(gSaveBlock1Ptr->enigmaBerry));
}

void SetEnigmaBerry(u8 *src)
{
    u32 i;
    u8 *dest = (u8 *)&gSaveBlock1Ptr->enigmaBerry;

    for (i = 0; i < sizeof(gSaveBlock1Ptr->enigmaBerry); i++)
        dest[i] = src[i];
}

static u32 GetEnigmaBerryChecksum(struct EnigmaBerry *enigmaBerry)
{
    u32 i;
    u32 checksum;
    u8 *dest;

    dest = (u8 *)enigmaBerry;
    checksum = 0;
    for (i = 0; i < sizeof(gSaveBlock1Ptr->enigmaBerry) - sizeof(gSaveBlock1Ptr->enigmaBerry.checksum); i++)
        checksum += dest[i];

    return checksum;
}

bool32 IsEnigmaBerryValid(void)
{
    if (!gSaveBlock1Ptr->enigmaBerry.berry.stageDuration)
        return FALSE;
    if (!gSaveBlock1Ptr->enigmaBerry.berry.maxYield)
        return FALSE;
    if (GetEnigmaBerryChecksum(&gSaveBlock1Ptr->enigmaBerry) != gSaveBlock1Ptr->enigmaBerry.checksum)
        return FALSE;
    return TRUE;
}

const struct Berry *GetBerryInfo(u8 berry)
{
    if (berry == ITEM_TO_BERRY(ITEM_ENIGMA_BERRY) && IsEnigmaBerryValid())
    {
        return (struct Berry *)(&gSaveBlock1Ptr->enigmaBerry.berry);
    }
    else
    {
        if (berry == BERRY_NONE || berry > ITEM_TO_BERRY(LAST_BERRY_INDEX))
            berry = ITEM_TO_BERRY(FIRST_BERRY_INDEX);
        return &gBerries[berry - 1];
    }
}

struct BerryTree *GetBerryTreeInfo(u8 id)
{
    return &gSaveBlock1Ptr->berryTrees[id];
}

bool32 ObjectEventInteractionWaterBerryTree(void)
{
    struct BerryTree *tree = GetBerryTreeInfo(GetObjectEventBerryTreeId(gSelectedObjectEvent));

    switch (tree->stage)
    {
    case BERRY_STAGE_PLANTED:
        tree->watered1 = TRUE;
        break;
    case BERRY_STAGE_SPROUTED:
        tree->watered2 = TRUE;
        break;
    case BERRY_STAGE_TALLER:
        tree->watered3 = TRUE;
        break;
    case BERRY_STAGE_FLOWERING:
        tree->watered4 = TRUE;
        break;
    default:
        return FALSE;
    }
    return TRUE;
}

bool8 IsPlayerFacingEmptyBerryTreePatch(void)
{
    if (GetObjectEventScriptPointerPlayerFacing() == BerryTreeScript
     && GetStageByBerryTreeId(GetObjectEventBerryTreeId(gSelectedObjectEvent)) == BERRY_STAGE_NO_BERRY)
        return TRUE;
    else
        return FALSE;
}

bool8 TryToWaterBerryTree(void)
{
    if (GetObjectEventScriptPointerPlayerFacing() != BerryTreeScript)
        return FALSE;
    else
        return ObjectEventInteractionWaterBerryTree();
}

void ClearBerryTrees(void)
{
    int i;

    for (i = 0; i < BERRY_TREES_COUNT; i++)
        gSaveBlock1Ptr->berryTrees[i] = gBlankBerryTree;
}

static bool32 BerryTreeGrow(struct BerryTree *tree)
{
    if (tree->stopGrowth)
        return FALSE;

    switch (tree->stage)
    {
    case BERRY_STAGE_NO_BERRY:
        return FALSE;
    case BERRY_STAGE_FLOWERING:
        tree->berryYield = CalcBerryYield(tree);
    case BERRY_STAGE_PLANTED:
    case BERRY_STAGE_SPROUTED:
    case BERRY_STAGE_TALLER:
        tree->stage++;
        break;
    case BERRY_STAGE_BERRIES:
        tree->watered1 = 0;
        tree->watered2 = 0;
        tree->watered3 = 0;
        tree->watered4 = 0;
        tree->berryYield = 0;
        tree->stage = BERRY_STAGE_SPROUTED;
        if (++tree->regrowthCount == 10)
            *tree = gBlankBerryTree;
        break;
    }
    return TRUE;
}

void BerryTreeTimeUpdate(s32 minutes)
{
    int i;
    struct BerryTree *tree;

    for (i = 0; i < BERRY_TREES_COUNT; i++)
    {
        tree = &gSaveBlock1Ptr->berryTrees[i];

        if (tree->berry && tree->stage && !tree->stopGrowth)
        {
            if (minutes >= GetStageDurationByBerryType(tree->berry) * 71)
            {
                *tree = gBlankBerryTree;
            }
            else
            {
                s32 time = minutes;

                while (time != 0)
                {
                    if (tree->minutesUntilNextStage > time)
                    {
                        tree->minutesUntilNextStage -= time;
                        break;
                    }
                    time -= tree->minutesUntilNextStage;
                    tree->minutesUntilNextStage = GetStageDurationByBerryType(tree->berry);
                    if (!BerryTreeGrow(tree))
                        break;
                    if (tree->stage == BERRY_STAGE_BERRIES)
                        tree->minutesUntilNextStage *= 4;
                }
            }
        }
    }
}

void PlantBerryTree(u8 id, u8 berry, u8 stage, bool8 allowGrowth)
{
    struct BerryTree *tree = GetBerryTreeInfo(id);

    *tree = gBlankBerryTree;
    tree->berry = berry;
    tree->minutesUntilNextStage = GetStageDurationByBerryType(berry);
    tree->stage = stage;
    if (stage == BERRY_STAGE_BERRIES)
    {
        tree->berryYield = CalcBerryYield(tree);
        tree->minutesUntilNextStage *= 4;
    }

    // Stop growth, to keep tree at this stage until the player has seen it
    // allowGrowth is always true for berry trees the player has planted
    if (!allowGrowth)
        tree->stopGrowth = TRUE;
}

void RemoveBerryTree(u8 id)
{
    gSaveBlock1Ptr->berryTrees[id] = gBlankBerryTree;
}

u8 GetBerryTypeByBerryTreeId(u8 id)
{
    return gSaveBlock1Ptr->berryTrees[id].berry;
}

u8 GetStageByBerryTreeId(u8 id)
{
    return gSaveBlock1Ptr->berryTrees[id].stage;
}

u8 ItemIdToBerryType(u16 item)
{
    u16 berry = item - FIRST_BERRY_INDEX;

    if (berry > LAST_BERRY_INDEX - FIRST_BERRY_INDEX)
        return ITEM_TO_BERRY(FIRST_BERRY_INDEX);
    else
        return ITEM_TO_BERRY(item);
}

static u16 BerryTypeToItemId(u16 berry)
{
    u16 item = berry - 1;

    if (item > LAST_BERRY_INDEX - FIRST_BERRY_INDEX)
        return FIRST_BERRY_INDEX;
    else
        return berry + FIRST_BERRY_INDEX - 1;
}

void GetBerryNameByBerryType(u8 berry, u8 *string)
{
    memcpy(string, GetBerryInfo(berry)->name, BERRY_NAME_LENGTH);
    string[BERRY_NAME_LENGTH] = EOS;
}

void GetBerryCountStringByBerryType(u8 berry, u8 *dest, u32 berryCount)
{
    GetBerryCountString(dest, GetBerryInfo(berry)->name, berryCount);
}

void AllowBerryTreeGrowth(u8 id)
{
    GetBerryTreeInfo(id)->stopGrowth = FALSE;
}

static u8 BerryTreeGetNumStagesWatered(struct BerryTree *tree)
{
    u8 count = 0;

    if (tree->watered1)
        count++;
    if (tree->watered2)
        count++;
    if (tree->watered3)
        count++;
    if (tree->watered4)
        count++;
    return count;
}

static u8 GetNumStagesWateredByBerryTreeId(u8 id)
{
    return BerryTreeGetNumStagesWatered(GetBerryTreeInfo(id));
}

// Berries can be watered at 4 stages of growth. The distribution is largely
// even but slightly prefers middle berry yields, since it uniformly draws from
// a subset of the total yield range.
static u8 CalcBerryYieldInternal(u16 max, u16 min, u8 water)
{
    u32 randMin;
    u32 randMax;
    u32 rand;
    u32 extraYield;

    if (water == 0)
    {
        return min;
    }
    else
    {
        randMin = (max - min) * (water - 1);
        randMax = (max - min) * (water);
        rand = randMin + Random() % (randMax - randMin + 1);

        // Round upwards
        if ((rand % NUM_WATER_STAGES) >= NUM_WATER_STAGES / 2)
            extraYield = rand / NUM_WATER_STAGES + 1;
        else
            extraYield = rand / NUM_WATER_STAGES;
        return extraYield + min;
    }
}

static u8 CalcBerryYield(struct BerryTree *tree)
{
    const struct Berry *berry = GetBerryInfo(tree->berry);
    u8 min = berry->minYield;
    u8 max = berry->maxYield;

    return CalcBerryYieldInternal(max, min, BerryTreeGetNumStagesWatered(tree));
}

static u8 GetBerryCountByBerryTreeId(u8 id)
{
    return gSaveBlock1Ptr->berryTrees[id].berryYield;
}

static u16 GetStageDurationByBerryType(u8 berry)
{
    return GetBerryInfo(berry)->stageDuration * 60;
}

void ObjectEventInteractionGetBerryTreeData(void)
{
    u8 id;
    u8 berry;
    u8 localId;
    u8 group;
    u8 num;

    id = GetObjectEventBerryTreeId(gSelectedObjectEvent);
    berry = GetBerryTypeByBerryTreeId(id);
    AllowBerryTreeGrowth(id);
    localId = gSpecialVar_LastTalked;
    num = gSaveBlock1Ptr->location.mapNum;
    group = gSaveBlock1Ptr->location.mapGroup;
    if (IsBerryTreeSparkling(localId, num, group))
        gSpecialVar_0x8004 = BERRY_STAGE_SPARKLING;
    else
        gSpecialVar_0x8004 = GetStageByBerryTreeId(id);
    gSpecialVar_0x8005 = GetNumStagesWateredByBerryTreeId(id);
    gSpecialVar_0x8006 = GetBerryCountByBerryTreeId(id);
    GetBerryCountStringByBerryType(berry, gStringVar1, gSpecialVar_0x8006);
}

void ObjectEventInteractionGetBerryName(void)
{
    u8 berryType = GetBerryTypeByBerryTreeId(GetObjectEventBerryTreeId(gSelectedObjectEvent));
    GetBerryNameByBerryType(berryType, gStringVar1);
}

void ObjectEventInteractionGetBerryCountString(void)
{
    u8 treeId = GetObjectEventBerryTreeId(gSelectedObjectEvent);
    u8 berry = GetBerryTypeByBerryTreeId(treeId);
    u8 count = GetBerryCountByBerryTreeId(treeId);
    GetBerryCountStringByBerryType(berry, gStringVar1, count);
}

void Bag_ChooseBerry(void)
{
    SetMainCallback2(CB2_ChooseBerry);
}

void ObjectEventInteractionPlantBerryTree(void)
{
    u8 berry = ItemIdToBerryType(gSpecialVar_ItemId);

    PlantBerryTree(GetObjectEventBerryTreeId(gSelectedObjectEvent), berry, BERRY_STAGE_PLANTED, TRUE);
    ObjectEventInteractionGetBerryTreeData();
}

void ObjectEventInteractionPickBerryTree(void)
{
    u8 id = GetObjectEventBerryTreeId(gSelectedObjectEvent);
    u8 berry = GetBerryTypeByBerryTreeId(id);

    gSpecialVar_0x8004 = AddBagItem(BerryTypeToItemId(berry), GetBerryCountByBerryTreeId(id));
}

void ObjectEventInteractionRemoveBerryTree(void)
{
    RemoveBerryTree(GetObjectEventBerryTreeId(gSelectedObjectEvent));
    SetBerryTreeJustPicked(gSpecialVar_LastTalked, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup);
}

bool8 PlayerHasBerries(void)
{
    return IsBagPocketNonEmpty(POCKET_BERRIES);
}

// Berry tree growth is frozen at their initial stage (usually, fully grown) until the player has seen the tree
// For all berry trees on screen, allow normal growth
void SetBerryTreesSeen(void)
{
    s16 cam_left;
    s16 cam_top;
    s16 left;
    s16 top;
    s16 right;
    s16 bottom;
    int i;

    GetCameraCoords(&cam_left, &cam_top);
    left = cam_left;
    top = cam_top + 3;
    right = cam_left + 14;
    bottom = top + 8;
    for (i = 0; i < OBJECT_EVENTS_COUNT; i++)
    {
        if (gObjectEvents[i].active && gObjectEvents[i].movementType == MOVEMENT_TYPE_BERRY_TREE_GROWTH)
        {
            cam_left = gObjectEvents[i].currentCoords.x;
            cam_top = gObjectEvents[i].currentCoords.y;
            if (left <= cam_left && cam_left <= right && top <= cam_top && cam_top <= bottom)
                AllowBerryTreeGrowth(gObjectEvents[i].trainerRange_berryTreeId);
        }
    }
}
