#!/usr/bin/env python3
""" Extract sprites from HGSS follower spritesheets. """
import os.path
from os.path import join as joinp
import subprocess
import sys
from glob import glob

import png
from tqdm import tqdm

import shutil

def stack_sprite(name, path):
    frames = [joinp(path, 'down', name), joinp(path, 'down', 'frame2', name),
              joinp(path, 'up', name), joinp(path, 'up', 'frame2', name),
              joinp(path, 'left', name), joinp(path, 'left', 'frame2', name)]
    output = joinp(path, name)
    subprocess.run(['convert'] + frames + ['+append', output], check=True)
    print(f'Stacked {output}')

def closest_color(c, palette):
    min_d = float('inf')
    best = 0
    r1, g1, b1 = c
    for i, (r2, g2, b2) in enumerate(palette[1:], 1):
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
    w, h, rows, info = inp.read()
    src_palette = tuple(c[:3] for c in inp.palette())
    new_rows = [[closest_color(src_palette[c][:3], target_palette) if c else 0 for c in row] for row in rows]
    with open(output_file, 'wb') as f:
        w = png.Writer(width=w, height=h, bitdepth=4, palette=target_palette)
        w.write(f, new_rows)

# Sprites from https://veekun.com/dex/downloads

def apply_front_palettes(ow_dir, project_root=''):
    mon_graphics = joinp(project_root, 'graphics', 'pokemon')
    for x in os.walk(ow_dir):
        current_dir = x[0]
        sub_dir = current_dir[len(ow_dir) + 1:1000]
        t = tqdm(sorted(glob(joinp(current_dir, '*.png'))))
        spaces = 0
        for path in t:
            name, _ = os.path.splitext(os.path.basename(path))
            name = joinp(sub_dir, name)
            # old_path = joinp(project_root, 'graphics', 'object_events', 'pics', 'pokemon', f'{name}.png')
            # new_path = joinp(project_root, 'graphics', 'object_events', 'pics', 'pokemon', name, 'follower.png')
            # os.mkdir(joinp(project_root, 'graphics', 'object_events', 'pics', 'pokemon', name))
            # shutil.move(old_path, new_path)
            spaces = min(max(len(name), spaces), 10)
            t.set_description(name + ' '*(spaces-len(name)))
            output_path = joinp(project_root, 'graphics', 'object_events', 'pics', 'pokemon', f'{name}.png')
            palette_path = joinp(mon_graphics, name, 'anim_front.png')
            try:
                apply_palette(palette_path, path, output_path)
            except Exception as e:
                palette_path = joinp(mon_graphics, name, 'front.png')
                try:
                    apply_palette(palette_path, path, output_path)
                except Exception as e2:
                    t.write(f'{name}: {e2.__class__.__name__}: {e2}', file=sys.stderr)


if __name__ == '__main__':
    apply_front_palettes('graphics/object_events/pics/pokemon')
