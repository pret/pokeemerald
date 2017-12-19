import os
import re

path = 'data'

asm_filenames = []
labels = {}
baseroms = []
new_baseroms = {}

# get data asm filenames
for (dirpath, dirnames, filenames) in os.walk(path):
    for filename in filenames:
        ext = os.path.splitext(filename)[1]
        if ext == '.s' or ext == '.inc':
            asm_filenames.append(os.path.join(dirpath, filename))

# get existing labels
with open('pokeemerald.map') as map_file:
    for line in map_file:
        m = re.match(r'^ +0x([0-9a-f]{8,8}) +([A-Za-z_][A-Za-z_0-9]*)$', line)
        if m:
            addr = int(m.group(1), 16)
            sym = m.group(2)
            labels[addr] = sym
            if addr >= 0x8000000 and addr < 0x81DB67C:
                labels[addr+1] = sym

# get baseroms
for filename in asm_filenames:
    with open(filename,encoding='utf8') as asm_file:
        for line in asm_file:
            m = re.match(r'^\s*\.incbin\s+"baserom.gba"\s*,\s*(0x[0-9a-fA-F]+|[0-9]+)\s*,\s*(0x[0-9a-fA-F]+|[0-9]+)', line)
            if m:
                file_offset = int(m.group(1), 0)
                size = int(m.group(2), 0)
                baseroms.append((file_offset, size))

# replace addresses with labels
for filename in asm_filenames:
    with open(filename,encoding='utf8') as asm_file:
        lines = asm_file.readlines()
    with open(filename,'w',encoding='utf8',newline='\n') as asm_file:
        for line in lines:
            label = ''
            m = re.match(r'^\s*.4byte\s+0x([0-9a-fA-F]+)\s*$', line)
            if m:
                addr = int(m.group(1), 16)
                if addr in labels:
                    label = labels[addr]
                else:
                    for (file_offset, size) in baseroms:
                        begin = 0x8000000 + file_offset
                        end = begin + size
                        if addr >= begin and addr < end:
                            label = 'gUnknown_{:08X}'.format(addr)
                            if file_offset not in new_baseroms:
                                new_baseroms[file_offset] = [file_offset]
                            new_file_offset = addr - 0x8000000
                            if new_file_offset not in new_baseroms[file_offset]:
                                new_baseroms[file_offset].append(new_file_offset)
                            break
            if label != '':
                asm_file.write('\t.4byte {}\n'.format(label))
            else:
                asm_file.write(line)

# split baseroms
for filename in asm_filenames:
    with open(filename,encoding='utf8') as asm_file:
        lines = asm_file.readlines()
    with open(filename,'w',encoding='utf8',newline='\n') as asm_file:
        for line in lines:
                m = re.match(r'^\s*\.incbin\s+"baserom.gba"\s*,\s*(0x[0-9a-fA-F]+|[0-9]+)\s*,\s*(0x[0-9a-fA-F]+|[0-9]+)', line)
                if m:
                    file_offset = int(m.group(1), 0)
                    size = int(m.group(2), 0)
                    end = file_offset + size
                    if file_offset in new_baseroms:
                        new_offsets = new_baseroms[file_offset]
                        new_offsets.sort()
                        for index, offset in enumerate(new_offsets[:-1]):
                            next_offset = new_offsets[index + 1]
                            cur_size = next_offset - offset
                            asm_file.write('gUnknown_{0:08X}:: @ {0:X}\n'.format(0x8000000 + offset))
                            asm_file.write('\t.incbin "baserom.gba", 0x{:x}, 0x{:x}\n\n'.format(offset, cur_size))
                        last_offset = new_offsets[-1]
                        asm_file.write('gUnknown_{0:08X}:: @ {0:X}\n'.format(0x8000000 + last_offset))
                        asm_file.write('\t.incbin "baserom.gba", 0x{:x}, 0x{:x}\n\n'.format(last_offset, end - last_offset))
                    else:
                        asm_file.write(line)
                else:
                    asm_file.write(line)
