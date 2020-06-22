#!/usr/bin/env python3
""" Extract sprites from HGSS follower spritesheets. """
import os.path
import subprocess
import sys
from glob import glob

import png


SPRITESHEETS = [('gen1.png', 15, 11, 1)]
output_dir = 'sprites'
index_to_name = {}
with open('names.txt', 'r') as f:
    for line in f:
        index, name = line.split(' ')[:2]
        name = name.strip()
        index_to_name[int(index)] = name.lower()
name_to_index = {v: k for k, v in index_to_name.items()}
PKMN_GRAPHICS = os.path.join('graphics', 'pokemon')


def extract_sprites(spritesheet):
    path, width, height, offset = spritesheet
    for y in range(height):
        for x in range(width):
            if x == 3 and y == 0 or x == 10 and y == 1:
                continue
            output_path = os.path.join(output_dir, f'{offset:03d}.png')
            subprocess.run(['convert', '-extract', f'64x128+{x*(64+1)}+{y*(128+1)}', path, output_path], check=True)
            offset += 1


def stack_sprite(index, path):
    joinp = os.path.join
    name = f'{index:03d}.png'
    frames = [joinp(path, 'down', name), joinp(path, 'down', 'frame2', name),
              joinp(path, 'up', name), joinp(path, 'up', 'frame2', name),
              joinp(path, 'left', name), joinp(path, 'left', 'frame2', name)]
    output = joinp(path, f'{index_to_name[index]}.png')
    subprocess.run(['convert'] + frames + ['+append', output], check=True)
    print(f'Stacked {output}')

def canonicalize_names():
    for path in glob('overworld/**/*.png', recursive=True):
        head, tail = os.path.split(path)
        name, ext = os.path.splitext(tail)
        try:
            num = int(name)
        except ValueError:
            continue
        new_name = f'{num:03d}'
        new_path = os.path.join(head, new_name+ext)
        os.rename(path, new_path)
        print(path, '->', new_path)

def closest_color(c, palette):
    min_d = float('inf')
    best = 0
    r1, g1, b1 = c
    for i, (r2, g2, b2) in enumerate(palette):
        # Color diff from https://stackoverflow.com/questions/1847092/given-an-rgb-value-what-would-be-the-best-way-to-find-the-closest-match-in-the-d
        d = ((r2-r1)*0.30)**2 + ((g2-g1)*0.59)**2 + ((b2-b1)*0.11)**2
        if d < min_d:
            min_d = d
            best = i
    return best

def apply_palette(palette_file, input_file, output_file):  # Apply one file's palette to another
    plt = png.Reader(palette_file)
    plt.read()
    target_palette = tuple(c[:3] for c in plt.palette())
    inp = png.Reader(input_file)
    w, h, rows, _ = inp.read()
    src_palette = tuple(c[:3] for c in inp.palette())
    with open(output_file, 'wb') as f:
        new_rows = []
        for row in rows:
            new_rows.append([closest_color(src_palette[c], target_palette) for c in row])
        w = png.Writer(width=w, height=h, bitdepth=4, palette=target_palette)
        w.write(f, new_rows)

def paletteify(path, output_path=None):
    output_path = output_path or path
    joinp = os.path.join
    _, tail = os.path.split(path)
    species, _ = os.path.splitext(tail)
    front = png.Reader(joinp(PKMN_GRAPHICS, species, 'anim_front.png'))
    front.read()
    target_palette = tuple(c[:3] for c in front.palette())
    r, g, b = target_palette[0]
    color = f'rgb({r},{g},{b})'
    # Strip alpha color
    subprocess.run(['convert', path, '-background', color, '-alpha', 'remove', output_path], check=True)
    apply_palette(joinp(PKMN_GRAPHICS, species, 'anim_front.png'), output_path, output_path)

# Sprites from https://veekun.com/dex/downloads

if __name__ == '__main__':
    args = sys.argv[1:]
    if args:
        paletteify(args[0])
    else:
        f0 = open('graphics_info.h', 'w', buffering=1)
        f1 = open('pic_tables.h', 'w', buffering=1)
        f2 = open('event_graphics.h', 'w', buffering=1)
        f3 = open('spritesheet_extra.mk', 'w', buffering=1)
        for index in range(1, 386+1):
            stack_sprite(index, 'overworld')
            try:
                species = index_to_name[index]
                path = os.path.join('overworld', f'{species}.png')
                output_path = os.path.join('graphics', 'object_events', 'pics', 'pokemon', f'{species}.png')
                paletteify(path, output_path)
            except Exception as e:
                print(e.__class__.__name__, e, file=sys.stderr)
                continue
            d = 32 if species not in {'steelix', 'wailord', 'kyogre', 'groudon', 'rayquaza', 'lugia', 'ho_oh'} else 64
            line = f'[SPECIES_{species.upper()}] = {{0xFFFF, OBJ_EVENT_PAL_TAG_DYNAMIC, OBJ_EVENT_PAL_TAG_NONE, {d*16}, {d}, {d}, 2, SHADOW_SIZE_M, FALSE, FALSE, TRACKS_FOOT, &gObjectEventBaseOam_{d}x{d}, gObjectEventSpriteOamTables_{d}x{d}, gObjectEventImageAnimTable_Following, gObjectEventPicTable_{species.capitalize()}, gDummySpriteAffineAnimTable}},'
            f0.write(line + '\n')
            lines = [f'const struct SpriteFrameImage gObjectEventPicTable_{species.capitalize()}[] = {{']
            lines += [f'    overworld_frame(gObjectEventPic_{species.capitalize()}, 4, 4, {frame}),' for frame in range(6)]
            lines.append('};')
            f1.write('\n'.join(lines) + '\n')
            line = f'const u32 gObjectEventPic_{species.capitalize()}[] = INCBIN_U32("graphics/object_events/pics/pokemon/{species}.4bpp");'
            f2.write(line + '\n')
            lines = [f'$(OBJEVENTGFXDIR)/pokemon/{species}.4bpp: %.4bpp: %.png\n',
                     f'\t$(GFX) $< $@ -mwidth {int(d/8)} -mheight {int(d/8)}\n\n']
            f3.write(''.join(lines))
        f0.close()
        f1.close()
        f2.close()
        f3.close()
