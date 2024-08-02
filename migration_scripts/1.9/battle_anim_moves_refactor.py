import re

def IsCommaMissing(line: str):
    sanitized_line = line.removesuffix('\n').strip()
    if sanitized_line.endswith('{') or sanitized_line.endswith('(') or sanitized_line.endswith(','):
        return False
    if not re.search(r'\.[A-Za-z0-9_]+', sanitized_line):
        return False
    return True

input_file = open('./src/data/moves_info.h', 'r')
lines = input_file.readlines()
input_file.close()


battle_anim_lines = []
moves_info_lines = []

move = None
bracketCount = 0
for line in lines:
    m = re.search(r'\[MOVE_([A-Za-z0-9_]+)\] =', line)
    if m:
        move = m.group(1)
        bracketCount = 0
        battle_anim_lines.append('extern const u8 Move_' + move + '[];\n')

    if move and re.search(r'\{', line):
        bracketCount = bracketCount + 1

    if move and re.search(r'\}', line):
        if (bracketCount == 1):
            moves_info_lines.append(8 * ' ' + '.battleAnimScript = Move_' + move + ',\n')
            move = None
        bracketCount = bracketCount - 1

    comment_split = line.split('//')
    if move and IsCommaMissing(comment_split[0]):
        line = comment_split[0].removesuffix('\n') + ',' + line[len(comment_split[0]):-1] + '\n'
    

    moves_info_lines.append(line)

output_file_mi = open('./src/data/moves_info.h', 'w')
output_file_mi.writelines(moves_info_lines)
output_file_mi.close()

output_file_bas = open('./include/battle_anim_scripts.h', 'w')
output_file_bas.writelines('#ifndef GUARD_BATTLE_ANIM_SCRIPTS_H\n')
output_file_bas.writelines('#define GUARD_BATTLE_ANIM_SCRIPTS_H\n\n')
output_file_bas.writelines(battle_anim_lines)
output_file_bas.writelines('\n#endif // GUARD_BATTLE_ANIM_SCRIPTS_H\n')
output_file_bas.close()

b_anim_scripts_s = open('./data/battle_anim_scripts.s', 'r')
lines = b_anim_scripts_s.read()
b_anim_scripts_s.close()

lines = re.sub(r'(Move_[A-Za-z0-9_]*)([:]+)', r'\1::', lines)

b_anim_scripts_s = open('./data/battle_anim_scripts.s', 'w')
b_anim_scripts_s.write(lines)
b_anim_scripts_s.close()
