# mapjson.py

import os
import re
import sys
import json


def abort(message):
    print message
    sys.exit()


def write_text_file(filepath, text):
    with open(filepath, 'w') as f:
        f.write(text)


def generate_map_header_text(map_data, layouts_data):
    matched_layouts = filter(lambda layout: layout['id'] == map_data['layout'], layouts_data['layouts'])
    if len(matched_layouts) != 1:
        abort('Failed to find matching layout for "%s"' % (map_data['layout']))
    layout = matched_layouts[0]
    text = '%s:\n' % (map_data['name'])
    text += '\t.4byte %s\n' % (layout['name'])

    if 'shared_events_map' in map_data:
        text += '\t.4byte %s\n' % (map_data['shared_events_map'] + '_MapEvents')
    else:
        text += '\t.4byte %s\n' % (map_data['name'] + '_MapEvents')

    if 'shared_scripts_map' in map_data:
        text += '\t.4byte %s\n' % (map_data['shared_scripts_map'] + '_MapScripts')
    else:
        text += '\t.4byte %s\n' % (map_data['name'] + '_MapScripts')

    if map_data['connections'] is not None and len(map_data['connections']) > 0:
        text += '\t.4byte %s\n' % (map_data['name'] + '_MapConnections')
    else:
        text += '\t.4byte 0x0\n'

    text += '\t.2byte %s\n' % (map_data['music'])
    text += '\t.2byte %s\n' % (layout['id'])
    text += '\t.byte %s\n' % (map_data['region_map_section'])
    text += '\t.byte %s\n' % (int(map_data['requires_flash']))
    text += '\t.byte %s\n' % (map_data['weather'])
    text += '\t.byte %s\n' % (map_data['map_type'])
    text += '\t.2byte 0\n'
    text += '\tmap_header_flags allow_bike=%s, allow_escape_rope=%s, allow_run=%s, show_map_name=%s\n' % (int(map_data['allow_bike']), int(map_data['allow_escape_rope']), int(map_data['allow_running']), int(map_data['show_map_name']))
    text += '\t.byte %s\n\n' % (map_data['battle_scene'])
    return text


def generate_map_connections_text(map_data):
    if map_data['connections'] is None:
        return '\n'

    label = '%s_MapConnectionsList' % (map_data['name'])
    text = '%s:\n' % (label)
    for connection in map_data['connections']:
        text += '\tconnection %s, %s, %s\n' % (connection['direction'], connection['offset'], connection['map'])

    text += '\n%s_MapConnections:\n' % (map_data['name'])
    text += '\t.4byte %s\n' % (len(map_data['connections']))
    text += '\t.4byte %s\n\n' % (label)
    return text


def generate_map_events_text(map_data):
    if 'shared_events_map' in map_data:
        return '\n'

    text = ''
    if len(map_data['object_events']) > 0:
        objects_label = '%s_EventObjects' % (map_data['name'])
        text += '%s:\n' % (objects_label)
        for i, obj in enumerate(map_data['object_events']):
            text += '\tobject_event %s, %s, 0, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s\n' % (
                i + 1,
                obj['graphics_id'],
                obj['x'],
                obj['y'],
                obj['elevation'],
                obj['movement_type'],
                obj['movement_range_x'],
                obj['movement_range_y'],
                obj['trainer_type'],
                obj['trainer_sight_or_berry_tree_id'],
                obj['script'],
                obj['flag'])
        text += '\n'
    else:
        objects_label = '0x0'

    if len(map_data['warp_events']) > 0:
        warps_label = '%s_MapWarps' % (map_data['name'])
        text += '%s:\n' % (warps_label)
        for i, warp in enumerate(map_data['warp_events']):
            text += '\twarp_def %s, %s, %s, %s, %s\n' % (
                warp['x'],
                warp['y'],
                warp['elevation'],
                warp['dest_warp_id'],
                warp['dest_map'])
        text += '\n'
    else:
        warps_label = '0x0'

    if len(map_data['coord_events']) > 0:
        coords_label = '%s_MapCoordEvents' % (map_data['name'])
        text += '%s:\n' % (coords_label)
        for i, event in enumerate(map_data['coord_events']):
            if event['type'] == 'trigger':
                text += '\tcoord_event %s, %s, %s, %s, %s, %s\n' % (
                    event['x'],
                    event['y'],
                    event['elevation'],
                    event['var'],
                    event['var_value'],
                    event['script'])
            elif event['type'] == 'weather':
                text += '\tcoord_weather_event %s, %s, %s, %s\n' % (
                    event['x'],
                    event['y'],
                    event['elevation'],
                    event['weather'])
        text += '\n'
    else:
        coords_label = '0x0'

    if len(map_data['bg_events']) > 0:
        bgs_label = '%s_MapBGEvents' % (map_data['name'])
        text += '%s:\n' % (bgs_label)
        for i, event in enumerate(map_data['bg_events']):
            if event['type'] == 'sign':
                text += '\tbg_event %s, %s, %s, %s, %s\n' % (
                    event['x'],
                    event['y'],
                    event['elevation'],
                    event['player_facing_dir'],
                    event['script'])
            elif event['type'] == 'hidden_item':
                text += '\tbg_hidden_item_event %s, %s, %s, %s, %s\n' % (
                    event['x'],
                    event['y'],
                    event['elevation'],
                    event['item'],
                    event['flag'])
            elif event['type'] == 'secret_base':
                text += '\tbg_secret_base_event %s, %s, %s, %s\n' % (
                    event['x'],
                    event['y'],
                    event['elevation'],
                    event['secret_base_id'])
        text += '\n'
    else:
        bgs_label = '0x0'

    text += '%s_MapEvents::\n' % (map_data['name'])
    text += '\tmap_events %s, %s, %s, %s\n\n' % (objects_label, warps_label, coords_label, bgs_label)
    return text


def process_map(map_filepath, layouts_filepath):
    with open(map_filepath) as f:
        map_data = json.load(f)
    with open(layouts_filepath) as f:
        layouts_data = json.load(f)

    header_text = generate_map_header_text(map_data, layouts_data)
    events_text = generate_map_events_text(map_data)
    connections_text = generate_map_connections_text(map_data)

    files_dir = os.path.dirname(map_filepath)
    write_text_file(os.path.join(files_dir, 'header.inc'), header_text)
    write_text_file(os.path.join(files_dir, 'events.inc'), events_text)
    write_text_file(os.path.join(files_dir, 'connections.inc'), connections_text)


def generate_groups_text(groups_data):
    text = ''
    for group in groups_data['group_order']:
        text += '%s::\n' % (group)
        maps = groups_data[group]
        for map_name in maps:
            text += '\t.4byte %s\n' % (map_name)
        text += '\n'

    text += '\t.align 2\n'
    text += 'gMapGroups::\n'
    for group in groups_data['group_order']:
        text += '\t.4byte %s\n' % (group)
    text += '\n'
    return text


def index_of(in_list, value):
    try:
        index_value = in_list.index(value)
    except ValueError:
        index_value = sys.maxint
    return index_value


def generate_connections_text(groups_data):
    map_names = []
    for group in groups_data['group_order']:
        for map_name in groups_data[group]:
            map_names.append(map_name)

    if 'connections_include_order' in groups_data:
        map_names.sort(key=lambda x: index_of(groups_data['connections_include_order'], x))

    text = ''
    for map_name in map_names:
        text += '\t.include "data/maps/%s/connections.inc"\n' % (map_name)

    return text


def generate_headers_text(groups_data):
    map_names = []
    for group in groups_data['group_order']:
        for map_name in groups_data[group]:
            map_names.append(map_name)

    text = ''
    for map_name in map_names:
        text += '\t.include "data/maps/%s/header.inc"\n' % (map_name)

    return text


def generate_events_text(groups_data):
    map_names = []
    for group in groups_data['group_order']:
        for map_name in groups_data[group]:
            map_names.append(map_name)

    text = ''
    for map_name in map_names:
        text += '\t.include "data/maps/%s/events.inc"\n' % (map_name)

    return text


def generate_map_constants_text(groups_filepath, groups_data):
    file_dir = os.path.dirname(groups_filepath)
    text = '#ifndef GUARD_CONSTANTS_MAP_GROUPS_H\n'
    text += '#define GUARD_CONSTANTS_MAP_GROUPS_H\n\n'

    for i, group in enumerate(groups_data['group_order']):
        text += '// Map Group %s\n' % (i)
        map_ids = []
        max_length = 0
        for map_name in groups_data[group]:
            header_filepath = os.path.join(file_dir, map_name, 'map.json')
            with open(header_filepath) as f:
                map_data = json.load(f)
            map_ids.append(map_data['id'])
            if len(map_data['id']) > max_length:
                max_length = len(map_data['id'])

        for j, map_id in enumerate(map_ids):
            text += '#define %s%s(%s | (%s << 8))\n' % (map_id, " " * (max_length - len(map_id) + 1), j, i)

        text += '\n'

    text += '#define MAP_GROUPS_COUNT %s\n\n' % (len(groups_data['group_order']))
    text += '#endif  // GUARD_CONSTANTS_MAP_GROUPS_H\n'

    return text


def process_groups(groups_filepath):
    with open(groups_filepath) as f:
        groups_data = json.load(f)

    groups_text = generate_groups_text(groups_data)
    connections_text = generate_connections_text(groups_data)
    headers_text = generate_headers_text(groups_data)
    events_text = generate_events_text(groups_data)
    map_header_text = generate_map_constants_text(groups_filepath, groups_data)

    file_dir = os.path.dirname(groups_filepath)
    write_text_file(os.path.join(file_dir, 'groups.inc'), groups_text)
    write_text_file(os.path.join(file_dir, 'connections.inc'), connections_text)
    write_text_file(os.path.join(file_dir, 'headers.inc'), headers_text)
    write_text_file(os.path.join(file_dir, 'events.inc'), events_text)
    write_text_file(os.path.join(file_dir, '../../include/constants/map_groups.h'), map_header_text)


def generate_layout_headers_text(layouts_data):
    text = ''
    for layout in layouts_data['layouts']:
        border_label = layout['name'] + '_Border'
        blockdata_label = layout['name'] + '_Blockdata'
        text += '%s::\n' % (border_label)
        text += '\t.incbin "%s"\n\n' % (layout['border_filepath'])
        text += '%s::\n' % (blockdata_label)
        text += '\t.incbin "%s"\n\n' % (layout['blockdata_filepath'])
        text += '\t.align 2\n'
        text += '%s::\n' % (layout['name'])
        text += '\t.4byte %s\n' % (layout['width'])
        text += '\t.4byte %s\n' % (layout['height'])
        text += '\t.4byte %s\n' % (border_label)
        text += '\t.4byte %s\n' % (blockdata_label)
        text += '\t.4byte %s\n' % (layout['primary_tileset'])
        text += '\t.4byte %s\n\n' % (layout['secondary_tileset'])

    return text


def generate_layouts_table_text(layouts_data):
    text = '\t.align 2\n'
    text += '%s::\n' % (layouts_data['layouts_table_label'])
    for layout in layouts_data['layouts']:
        text += '\t.4byte %s\n' % (layout['name'])

    return text


def generate_layouts_constants_text(layouts_data):
    text = '#ifndef GUARD_CONSTANTS_LAYOUTS_H\n'
    text += '#define GUARD_CONSTANTS_LAYOUTS_H\n\n'
    for i, layout in enumerate(layouts_data['layouts']):
        text += '#define %s %s\n' % (layout['id'], i + 1)
    text += '\n'
    text += '#endif  // GUARD_CONSTANTS_LAYOUTS_H\n'
    return text


def process_layouts(layouts_filepath):
    with open(layouts_filepath) as f:
        layouts_data = json.load(f)

    layout_headers_text = generate_layout_headers_text(layouts_data)
    layouts_table_text = generate_layouts_table_text(layouts_data)
    layouts_constants_text = generate_layouts_constants_text(layouts_data)

    file_dir = os.path.dirname(layouts_filepath)
    write_text_file(os.path.join(file_dir, 'layouts.inc'), layout_headers_text)
    write_text_file(os.path.join(file_dir, 'layouts_table.inc'), layouts_table_text)
    write_text_file(os.path.join(file_dir, '../../include/constants/layouts.h'), layouts_constants_text)


def main():
    if len(sys.argv) < 2:
        abort('USAGE: python mapjson.py <mode> [options]')

    mode = sys.argv[1]
    if mode not in ['layouts', 'map', 'groups']:
        abort("ERROR: <mode> must be 'layouts', 'map', or 'groups'.")

    if mode == 'map':
        if len(sys.argv) != 4:
            abort('USAGE: python mapjson.py map <map_file> <layouts_file>')

        filepath = sys.argv[2]
        if not os.path.exists(filepath):
            abort('ERROR: Map file "%s" does not exist' % (filepath))

        layouts_filepath = sys.argv[3]
        if not os.path.exists(layouts_filepath):
            abort('ERROR: Layouts file "%s" does not exist' % (layouts_filepath))

        process_map(filepath, layouts_filepath)
    elif mode == 'groups':
        if len(sys.argv) != 3:
            abort('USAGE: python mapjson.py groups <groups_file>')

        filepath = sys.argv[2]
        if not os.path.exists(filepath):
            abort('ERROR: Map file "%s" does not exist' % (filepath))

        process_groups(filepath)
    elif mode == 'layouts':
        if len(sys.argv) != 3:
            abort('USAGE: python mapjson.py layouts <layouts_file>')

        filepath = sys.argv[2]
        if not os.path.exists(filepath):
            abort('ERROR: Layouts file "%s" does not exist' % (filepath))

        process_layouts(filepath)


if __name__ == '__main__':
    main()
