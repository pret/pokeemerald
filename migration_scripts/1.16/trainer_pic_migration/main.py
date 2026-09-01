import os


def check_root_folder():
    if not os.path.exists("Makefile"):
        print("Please run this script from your root folder.")
        quit()


def read_source_file():
    lines = []
    with open("src/data/graphics/trainers.h", "r") as source:
        parse = False
        for line in source:
            if "const struct TrainerSprite gTrainerSprites[]" in line:
                parse = True
                continue
            if parse:
                if line.strip() == "};":
                    break
                lines.append(line)
    return lines


def parse_trainer_entry(line):
    if "TRAINER_SPRITE" not in line:
        return None, None

    line = line.replace("TRAINER_SPRITE(", "").rstrip("), \n")
    lst = line.split(",")

    enum = lst[0].strip().replace("FRONT_", "")
    lst.pop(0)

    entries = ", ".join(entry.strip() for entry in lst)
    pic_content = f'{entries}'

    return enum, pic_content


def generate_enums(lines):
    with open("migration_scripts/1.16/trainer_pic_migration/enums.h", "w") as output:
        output.write(f"enum __attribute__((packed)) TrainerPicID\n")
        output.write(f"{{\n")

        for line in lines:
            enum, pic_content = parse_trainer_entry(line)
            if enum is None:
                output.write(f"    TRAINER_PIC_NONE,\n")
                continue
            output.write(f"    {enum},\n")

        output.write(f"}};")


def generate_table(lines):
    with open("migration_scripts/1.16/trainer_pic_migration/table.h", "w") as output:
        output.write(f'const struct TrainerPicInfo gTrainerPicInfo[TRAINER_PIC_COUNT] =\n')
        output.write(f'{{\n')

        for line in lines:
            enum, pic_content = parse_trainer_entry(line)

            if enum is None:
                output.write(f"    [TRAINER_PIC_NONE] =\n")
                output.write("    {\n")
                output.write(f"        .frontPic = TRAINER_FRONT_PIC(gTrainerFrontPic_None, gTrainerPalette_None),\n")
                output.write("    },\n")
                continue

            output.write(f"    [{enum}] =\n")
            output.write("    {\n")
            output.write(f"        .frontPic = TRAINER_FRONT_PIC({pic_content}),\n")
            output.write("    },\n")

        output.write(f'}};')


def main():
    check_root_folder()
    lines = read_source_file()
    generate_enums(lines)
    generate_table(lines)

    print("Generated files enums.h and table.h in the migration_scripts/1.16/trainer_pic_migration folder.")
    print("The script output requires to be manually added.")
    print("Inline (copy over) the content of the files to the right locations")

if __name__ == "__main__":
    main()
