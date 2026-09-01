import re
import tempfile

font_infos_re = re.compile(
    r"struct\s+FontInfo\s+(?P<name>sFontInfos)\[\]\s+=[^{]*\{" # declaration & opening bracket
    r"(?P<elems>([^{}]*\{[^{}]*})+)" # array elements
    r"[^{}]*};", # closing bracket
    re.MULTILINE
)

text_on_windows_info_re = re.compile(
    r"struct\s+BattleWindowText\s+(?P<name>sTextOnWindowsInfo_[a-zA-Z0-9_]+)\[\]\s+=[^{]*\{" # declaration & opening bracket
    r"(?P<elems>([^{}]*\{[^{}]*})+)" # array elements
    r"[^{}]*};", # closing bracket
    re.MULTILINE
)

array_elem_re = re.compile(r"[^{}]*(\{[^{}]*})")

bg_color_re = re.compile(r"(?P<indent>\s*)\.bgColor\s*=\s*(?P<bg_color>[a-zA-Z0-9_]+)(?P<comma>,?)")

def replace_color_defs(m):
    s = m[0]
    if ".accentColor" not in s:
        s = bg_color_re.sub(lambda m: f'{m["indent"]}.bgColor = {m["bg_color"]},{m["indent"]}.accentColor = {m["bg_color"]}{m["comma"]}', s)
    s = s.replace(".bgColor", ".color.background")
    s = s.replace(".fgColor", ".color.foreground")
    s = s.replace(".shadowColor", ".color.shadow")
    s = s.replace(".accentColor", ".color.accent")

    return s

if __name__ == "__main__":
    with tempfile.TemporaryFile(mode="w+") as tmp:
        with open("src/text.c", 'r') as f:
            text_c = f.read()
        m = font_infos_re.search(text_c)
        if m is not None:
            print(f'src/text.c: Updating {m["name"]}...')
            font_infos_elems = m.group("elems")
            fi_start, fi_end = m.span("elems")

            tmp.write(text_c[:fi_start])
            edited = array_elem_re.sub(replace_color_defs, font_infos_elems)
            tmp.write(edited)
            tmp.write(text_c[fi_end:])

            tmp.seek(0)

            with open("src/text.c", "w") as f:
                f.write(tmp.read())
        else:
            print("Couldn't find sFontInfos!")

    with tempfile.TemporaryFile(mode="w+") as tmp:
        with open("src/battle_message.c", 'r') as f:
            text_c = f.read()


        search_start = 0
        while (m := text_on_windows_info_re.search(text_c, search_start)) is not None:
            print(f'src/battle_message.c: Updating {m["name"]}...')
            text_on_windows_elems = m.group("elems")
            match_start, match_end = m.span("elems")

            tmp.write(text_c[search_start:match_start])
            edited = array_elem_re.sub(replace_color_defs, text_on_windows_elems)
            tmp.write(edited)
            search_start = match_end

        tmp.write(text_c[search_start:])
        tmp.seek(0)

        with open("src/battle_message.c", "w") as f:
            f.write(tmp.read())
