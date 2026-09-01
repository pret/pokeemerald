import re
import os

if not os.path.exists("Makefile"):
    print("Please run this script from your root folder.")
    quit()

#Hoenn
##include/constants/pokedex.h
hoennMacro = """

#if P_NEW_EVOS_IN_REGIONAL_DEX
#define HOENN_DEX_IF(config, ...) CAT(HOENN_DEX_IF_, config)(__VA_ARGS__)
#define HOENN_DEX_IF_0(...)
#define HOENN_DEX_IF_1(...) __VA_ARGS__
#else
#define HOENN_DEX_IF(config, ...)
#endif

#define FOREACH_SPECIES_IN_HOENN_DEX_ORDER(F) \\
"""

output = ""
crossEvo = False
lastSpecies = ""
hoennDone = False

with open("include/constants/pokedex.h", "r") as file:
    lines = file.readlines()
    for line in lines:
        if "HOENN_DEX_NONE" in line:
            output += line + """    #define HOENN_DEX_ENUM(name) HOENN_DEX_ ##name,
    FOREACH_SPECIES_IN_HOENN_DEX_ORDER(HOENN_DEX_ENUM)
    #undef HOENN_DEX_ENUM
"""
        elif "    HOENN_DEX_" in line:
            macroedSpecies = line.replace("HOENN_DEX_", "F(")
            lastSpecies = macroedSpecies.strip().replace(",", "")
            if crossEvo:
                hoennMacro += macroedSpecies.strip().replace(",", ")) \\")
            else:
                hoennMacro += macroedSpecies.replace(",", ") \\")
        elif "P_NEW_EVOS_IN_REGIONAL_DEX" in line and not hoennDone:
            crossEvo = True
            config = line.replace("#if P_NEW_EVOS_IN_REGIONAL_DEX && ", "").replace("\n", "")
            hoennMacro += f"    HOENN_DEX_IF({config}, "
        elif "#else" in line and crossEvo and not hoennDone:
            continue
        elif "#endif" in line and not hoennDone:
            if crossEvo:
                hoennMacro += "\n"
                crossEvo = False
            else:
                output += line
        else:
            if lastSpecies != "" and line == "};\n":
                hoennDone = True
            output += line

lineBeforeMacro = "#define POKEMON_SLOTS_NUMBER (NATIONAL_DEX_COUNT + 1)"
hoennMacro = hoennMacro.replace(lastSpecies + ") \\", lastSpecies + ")")
output = output.replace(lineBeforeMacro, lineBeforeMacro + hoennMacro)

with open("include/constants/pokedex.h", "w") as f:
    f.write(output)
    print("include/constants/pokedex.h has been updated")

##src/pokemon.c
output = ""
ifStatement = False
hoennToNational = False

with open("src/pokemon.c", "r") as file:
    lines = file.readlines()
    for line in lines:
        if "HOENN_TO_NATIONAL" in line and "#define" not in line:
            hoennToNational = True
        elif "#if P_NEW_EVOS_IN_REGIONAL_DEX" in line:
            ifStatement = True
        elif "#else" in line and ifStatement:
            continue
        elif "#endif" in line and ifStatement:
            ifStatement = False
        elif hoennToNational:
            output += "    FOREACH_SPECIES_IN_HOENN_DEX_ORDER(HOENN_TO_NATIONAL)\n" + line
            hoennToNational = False
        else:
            output += line

hoennToNationalDefine = "#define HOENN_TO_NATIONAL(name)     [HOENN_DEX_##name - 1] = NATIONAL_DEX_##name"
output = output.replace(hoennToNationalDefine, hoennToNationalDefine + ",")

with open("src/pokemon.c", "w") as f:
    f.write(output)
    print("src/pokemon.c has been updated")

#Kanto
##include/constants/pokedex.h
kantoMacro = """

#if P_NEW_EVOS_IN_REGIONAL_DEX
#define KANTO_DEX_IF(config, ...) CAT(KANTO_DEX_IF_, config)(__VA_ARGS__)
#define KANTO_DEX_IF_0(...)
#define KANTO_DEX_IF_1(...) __VA_ARGS__
#else
#define KANTO_DEX_IF(config, ...)
#endif

#define FOREACH_SPECIES_IN_KANTO_DEX_ORDER(F) \\
"""

output = ""
crossEvo = False
lastSpecies = ""

with open("include/constants/pokedex.h", "r") as file:
    lines = file.readlines()
    for line in lines:
        if "KANTO_DEX_NONE" in line:
            output += line + """    #define KANTO_DEX_ENUM(name) KANTO_DEX_ ##name,
    FOREACH_SPECIES_IN_KANTO_DEX_ORDER(KANTO_DEX_ENUM)
    #undef KANTO_DEX_ENUM
"""
        elif "    KANTO_DEX_" in line:
            macroedSpecies = line.replace("KANTO_DEX_", "F(")
            lastSpecies = macroedSpecies.strip().replace(",", "")
            if crossEvo:
                kantoMacro += macroedSpecies.strip().replace(",", ")) \\")
            else:
                kantoMacro += macroedSpecies.replace(",", ") \\")
        elif "P_NEW_EVOS_IN_REGIONAL_DEX" in line and line != "#if P_NEW_EVOS_IN_REGIONAL_DEX\n":
            crossEvo = True
            config = line.replace("#if P_NEW_EVOS_IN_REGIONAL_DEX && ", "").replace("\n", "")
            kantoMacro += f"    KANTO_DEX_IF({config}, "
        elif "#else" in line and crossEvo:
            continue
        elif "#endif" in line:
            if crossEvo:
                kantoMacro += "\n"
                crossEvo = False
            else:
                output += line
        else:
            output += line

lineBeforeMacro = "// Kanto Pokedex order"
kantoMacro = kantoMacro.replace(lastSpecies + ") \\", lastSpecies + ")")
output = output.replace(lineBeforeMacro, lineBeforeMacro + kantoMacro)

with open("include/constants/pokedex.h", "w") as f:
    f.write(output)
    print("include/constants/pokedex.h has been updated")

##src/pokemon.c
output = ""
ifStatement = False
kantoToNational = False

with open("src/pokemon.c", "r") as file:
    lines = file.readlines()
    for line in lines:
        if "KANTO_TO_NATIONAL" in line and "#define" not in line:
            kantoToNational = True
        elif "#if P_NEW_EVOS_IN_REGIONAL_DEX" in line:
            ifStatement = True
        elif "#else" in line and ifStatement:
            continue
        elif "#endif" in line and ifStatement:
            ifStatement = False
        elif kantoToNational:
            output += "    FOREACH_SPECIES_IN_KANTO_DEX_ORDER(KANTO_TO_NATIONAL)\n" + line
            kantoToNational = False
        else:
            output += line

kantoToNationalDefine = "#define KANTO_TO_NATIONAL(name)     [KANTO_DEX_##name - 1] = NATIONAL_DEX_##name"
output = output.replace(kantoToNationalDefine, kantoToNationalDefine + ",")

with open("src/pokemon.c", "w") as f:
    f.write(output)
    print("src/pokemon.c has been updated")
