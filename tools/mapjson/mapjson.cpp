// mapjson.cpp

#include <iostream>
using std::cout; using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <algorithm>
using std::sort; using std::find;

#include <map>
using std::map;

#include <fstream>
using std::ofstream; using std::ifstream;

#include <sstream>
using std::ostringstream;

#include <limits>
using std::numeric_limits;

#include "json11.h"
using json11::Json;

#include "mapjson.h"


string read_text_file(string filepath) {
    ifstream in_file(filepath);

    if (!in_file.is_open())
        FATAL_ERROR("Cannot open file %s for reading.\n", filepath.c_str());

    string text;

    in_file.seekg(0, std::ios::end);
    text.resize(in_file.tellg());

    in_file.seekg(0, std::ios::beg);
    in_file.read(&text[0], text.size());

    in_file.close();

    return text;
}

void write_text_file(string filepath, string text) {
    ofstream out_file(filepath, std::ofstream::binary);

    if (!out_file.is_open())
        FATAL_ERROR("Cannot open file %s for writing.\n", filepath.c_str());

    out_file << text;

    out_file.close();
}

string generate_map_header_text(Json map_data, Json layouts_data, string version) {
    string map_layout_id = map_data["layout"].string_value();

    vector<Json> matched;

    for (auto &field : layouts_data["layouts"].array_items()) {
        if (map_layout_id == field["id"].string_value())
            matched.push_back(field);
    }

    if (matched.size() != 1)
        FATAL_ERROR("Failed to find matching layout for %s.\n", map_layout_id.c_str());

    Json layout = matched[0];

    ostringstream text;

    text << "@\n@ DO NOT MODIFY THIS FILE! It is auto-generated from data/maps/" 
         << map_data["name"].string_value() 
         << "/map.json\n@\n\n";

    text << map_data["name"].string_value() << ":\n"
         << "\t.4byte " << layout["name"].string_value() << "\n";

    if (map_data.object_items().find("shared_events_map") != map_data.object_items().end())
        text << "\t.4byte " << map_data["shared_events_map"].string_value() << "_MapEvents\n";
    else
        text << "\t.4byte " << map_data["name"].string_value() << "_MapEvents\n";

    if (map_data.object_items().find("shared_scripts_map") != map_data.object_items().end())
        text << "\t.4byte " << map_data["shared_scripts_map"].string_value() << "_MapScripts\n";
    else
        text << "\t.4byte " << map_data["name"].string_value() << "_MapScripts\n";

    if (map_data.object_items().find("connections") != map_data.object_items().end()
     && map_data["connections"].array_items().size() > 0)
        text << "\t.4byte " << map_data["name"].string_value() << "_MapConnections\n";
    else
        text << "\t.4byte 0x0\n";

    text << "\t.2byte " << map_data["music"].string_value() << "\n"
         << "\t.2byte " << layout["id"].string_value() << "\n"
         << "\t.byte "  << map_data["region_map_section"].string_value() << "\n"
         << "\t.byte "  << map_data["requires_flash"].bool_value() << "\n"
         << "\t.byte "  << map_data["weather"].string_value() << "\n"
         << "\t.byte "  << map_data["map_type"].string_value() << "\n"
         << "\t.2byte 0\n";

    if (version == "ruby")
        text << "\t.byte " << map_data["show_map_name"].bool_value() << "\n";
    else if (version == "emerald")
        text << "\tmap_header_flags "
             << "allow_cycling=" << map_data["allow_cycling"].bool_value() << ", "
             << "allow_escaping=" << map_data["allow_escaping"].bool_value() << ", "
             << "allow_running=" << map_data["allow_running"].bool_value() << ", "
             << "show_map_name=" << map_data["show_map_name"].bool_value() << "\n";

     text << "\t.byte " << map_data["battle_scene"].string_value() << "\n\n";

    return text.str();
}

string generate_map_connections_text(Json map_data) {
    if (map_data["connections"] == Json())
        return string("\n");

    ostringstream text;

    text << "@\n@ DO NOT MODIFY THIS FILE! It is auto-generated from data/maps/" 
         << map_data["name"].string_value() 
         << "/map.json\n@\n\n";

    text << map_data["name"].string_value() << "_MapConnectionsList:\n";

    for (auto &connection : map_data["connections"].array_items()) {
        text << "\tconnection "
             << connection["direction"].string_value() << ", "
             << connection["offset"].int_value() << ", "
             << connection["map"].string_value() << "\n";
    }

    text << "\n" << map_data["name"].string_value() << "_MapConnections:\n"
         << "\t.4byte " << map_data["connections"].array_items().size() << "\n"
         << "\t.4byte " << map_data["name"].string_value() << "_MapConnectionsList\n\n";

    return text.str();
}

string generate_map_events_text(Json map_data) {
    if (map_data.object_items().find("shared_events_map") != map_data.object_items().end())
        return string("\n");

    ostringstream text;

    text << "@\n@ DO NOT MODIFY THIS FILE! It is auto-generated from data/maps/" 
         << map_data["name"].string_value() 
         << "/map.json\n@\n\n";

    string objects_label, warps_label, coords_label, bgs_label;

    if (map_data["object_events"].array_items().size() > 0) {
        objects_label = map_data["name"].string_value() + "_ObjectEvents";
        text << objects_label << ":\n";
        for (unsigned int i = 0; i < map_data["object_events"].array_items().size(); i++) {
            auto obj_event = map_data["object_events"].array_items()[i];
            text << "\tobject_event " << i + 1 << ", "
                 << obj_event["graphics_id"].string_value() << ", 0, "
                 << obj_event["x"].int_value() << ", "
                 << obj_event["y"].int_value() << ", "
                 << obj_event["elevation"].int_value() << ", "
                 << obj_event["movement_type"].string_value() << ", "
                 << obj_event["movement_range_x"].int_value() << ", "
                 << obj_event["movement_range_y"].int_value() << ", "
                 << obj_event["trainer_type"].string_value() << ", "
                 << obj_event["trainer_sight_or_berry_tree_id"].string_value() << ", "
                 << obj_event["script"].string_value() << ", "
                 << obj_event["flag"].string_value() << "\n";
        }
        text << "\n";
    } else {
        objects_label = "0x0";
    }

    if (map_data["warp_events"].array_items().size() > 0) {
        warps_label = map_data["name"].string_value() + "_MapWarps";
        text << warps_label << ":\n";
        for (auto &warp_event : map_data["warp_events"].array_items()) {
            text << "\twarp_def "
                 << warp_event["x"].int_value() << ", "
                 << warp_event["y"].int_value() << ", "
                 << warp_event["elevation"].int_value() << ", "
                 << warp_event["dest_warp_id"].int_value() << ", "
                 << warp_event["dest_map"].string_value() << "\n";
        }
        text << "\n";
    } else {
        warps_label = "0x0";
    }

    if (map_data["coord_events"].array_items().size() > 0) {
        coords_label = map_data["name"].string_value() + "_MapCoordEvents";
        text << coords_label << ":\n";
        for (auto &coord_event : map_data["coord_events"].array_items()) {
            if (coord_event["type"].string_value() == "trigger") {
                text << "\tcoord_event "
                     << coord_event["x"].int_value() << ", "
                     << coord_event["y"].int_value() << ", "
                     << coord_event["elevation"].int_value() << ", "
                     << coord_event["var"].string_value() << ", "
                     << coord_event["var_value"].string_value() << ", "
                     << coord_event["script"].string_value() << "\n";
            }
            else if (coord_event["type"] == "weather") {
                text << "\tcoord_weather_event "
                     << coord_event["x"].int_value() << ", "
                     << coord_event["y"].int_value() << ", "
                     << coord_event["elevation"].int_value() << ", "
                     << coord_event["weather"].string_value() << "\n";
            }
        }
        text << "\n";
    } else {
        coords_label = "0x0";
    }

    if (map_data["bg_events"].array_items().size() > 0) {
        bgs_label = map_data["name"].string_value() + "_MapBGEvents";
        text << bgs_label << ":\n";
        for (auto &bg_event : map_data["bg_events"].array_items()) {
            if (bg_event["type"] == "sign") {
                text << "\tbg_event "
                     << bg_event["x"].int_value() << ", "
                     << bg_event["y"].int_value() << ", "
                     << bg_event["elevation"].int_value() << ", "
                     << bg_event["player_facing_dir"].string_value() << ", "
                     << bg_event["script"].string_value() << "\n";
            }
            else if (bg_event["type"] == "hidden_item") {
                text << "\tbg_hidden_item_event "
                     << bg_event["x"].int_value() << ", "
                     << bg_event["y"].int_value() << ", "
                     << bg_event["elevation"].int_value() << ", "
                     << bg_event["item"].string_value() << ", "
                     << bg_event["flag"].string_value() << "\n";
            }
            else if (bg_event["type"] == "secret_base") {
                text << "\tbg_secret_base_event "
                     << bg_event["x"].int_value() << ", "
                     << bg_event["y"].int_value() << ", "
                     << bg_event["elevation"].int_value() << ", "
                     << bg_event["secret_base_id"].string_value() << "\n";
            }
        }
        text << "\n";
    } else {
        bgs_label = "0x0";
    }

    text << map_data["name"].string_value() << "_MapEvents::\n"
         << "\tmap_events " << objects_label << ", " << warps_label << ", "
         << coords_label << ", " << bgs_label << "\n\n";

    return text.str();
}

string get_directory_name(string filename) {
    size_t dir_pos = filename.find_last_of("/\\");

    return filename.substr(0, dir_pos + 1);
}

void process_map(string map_filepath, string layouts_filepath, string version) {
    string mapdata_err, layouts_err;

    string mapdata_json_text = read_text_file(map_filepath);
    string layouts_json_text = read_text_file(layouts_filepath);

    Json map_data = Json::parse(mapdata_json_text, mapdata_err);
    if (map_data == Json())
        FATAL_ERROR("%s\n", mapdata_err.c_str());

    Json layouts_data = Json::parse(layouts_json_text, layouts_err);
    if (layouts_data == Json())
        FATAL_ERROR("%s\n", layouts_err.c_str());

    string header_text = generate_map_header_text(map_data, layouts_data, version);
    string events_text = generate_map_events_text(map_data);
    string connections_text = generate_map_connections_text(map_data);

    string files_dir = get_directory_name(map_filepath);
    write_text_file(files_dir + "header.inc", header_text);
    write_text_file(files_dir + "events.inc", events_text);
    write_text_file(files_dir + "connections.inc", connections_text);
}

string generate_groups_text(Json groups_data) {
    ostringstream text;

    text << "@\n@ DO NOT MODIFY THIS FILE! It is auto-generated from data/maps/map_groups.json\n@\n\n";

    for (auto &key : groups_data["group_order"].array_items()) {
        string group = key.string_value();
        text << group << "::\n";
        auto maps = groups_data[group].array_items();
        for (Json &map_name : maps)
            text << "\t.4byte " << map_name.string_value() << "\n";
        text << "\n";
    }

    text << "\t.align 2\n" << "gMapGroups::\n";
    for (auto &group : groups_data["group_order"].array_items())
        text << "\t.4byte " << group.string_value() << "\n";
    text << "\n";

    return text.str();
}

string generate_connections_text(Json groups_data) {
    vector<Json> map_names;

    for (auto &group : groups_data["group_order"].array_items())
    for (auto map_name : groups_data[group.string_value()].array_items())
        map_names.push_back(map_name);

    vector<Json> connections_include_order = groups_data["connections_include_order"].array_items();

    if (connections_include_order.size() > 0)
        sort(map_names.begin(), map_names.end(), [connections_include_order](const Json &a, const Json &b) {
            auto iter_a = find(connections_include_order.begin(), connections_include_order.end(), a);
            if (iter_a == connections_include_order.end())
                iter_a = connections_include_order.begin() + numeric_limits<int>::max();
            auto iter_b = find(connections_include_order.begin(), connections_include_order.end(), b);
            if (iter_b == connections_include_order.end())
                iter_b = connections_include_order.begin() + numeric_limits<int>::max();
            return iter_a < iter_b;
        });

    ostringstream text;

    text << "@\n@ DO NOT MODIFY THIS FILE! It is auto-generated from data/maps/map_groups.json\n@\n\n";

    for (Json map_name : map_names)
        text << "\t.include \"data/maps/" << map_name.string_value() << "/connections.inc\"\n";

    return text.str();
}

string generate_headers_text(Json groups_data) {
    vector<string> map_names;

    for (auto &group : groups_data["group_order"].array_items())
    for (auto map_name : groups_data[group.string_value()].array_items())
        map_names.push_back(map_name.string_value());

    ostringstream text;

    text << "@\n@ DO NOT MODIFY THIS FILE! It is auto-generated from data/maps/map_groups.json\n@\n\n";

    for (string map_name : map_names)
        text << "\t.include \"data/maps/" << map_name << "/header.inc\"\n";

    return text.str();
}

string generate_events_text(Json groups_data) {
    vector<string> map_names;

    for (auto &group : groups_data["group_order"].array_items())
    for (auto map_name : groups_data[group.string_value()].array_items())
        map_names.push_back(map_name.string_value());

    ostringstream text;

    text << "@\n@ DO NOT MODIFY THIS FILE! It is auto-generated from data/maps/map_groups.json\n@\n\n";

    for (string map_name : map_names)
        text << "\t.include \"data/maps/" << map_name << "/events.inc\"\n";

    return text.str();
}

string generate_map_constants_text(string groups_filepath, Json groups_data) {
    string file_dir = get_directory_name(groups_filepath);
    char dir_separator = file_dir.back();

    ostringstream text;

    text << "#ifndef GUARD_CONSTANTS_MAP_GROUPS_H\n"
         << "#define GUARD_CONSTANTS_MAP_GROUPS_H\n\n";

    text << "//\n// DO NOT MODIFY THIS FILE! It is auto-generated from data/maps/map_groups.json\n//\n\n";

    int group_num = 0;

    for (auto &group : groups_data["group_order"].array_items()) {
        text << "// Map Group " << group_num << "\n";
        vector<Json> map_ids;
        size_t max_length = 0;

        for (auto &map_name : groups_data[group.string_value()].array_items()) {
            string header_filepath = file_dir + map_name.string_value() + dir_separator + "map.json";
            string err_str;
            Json map_data = Json::parse(read_text_file(header_filepath), err_str);
            map_ids.push_back(map_data["id"]);
            if (map_data["id"].string_value().length() > max_length)
                max_length = map_data["id"].string_value().length();
        }

        int map_id_num = 0;
        for (Json map_id : map_ids) {
            text << "#define " << map_id.string_value() << string((max_length - map_id.string_value().length() + 1), ' ')
                 << "(" << map_id_num++ << " | (" << group_num << " << 8))\n";
        }
        text << "\n";

        group_num++;
    }

    text << "#define MAP_GROUPS_COUNT " << group_num << "\n\n";
    text << "#endif // GUARD_CONSTANTS_MAP_GROUPS_H\n";

    return text.str();
}

void process_groups(string groups_filepath) {
    string err;
    Json groups_data = Json::parse(read_text_file(groups_filepath), err);

    if (groups_data == Json())
        FATAL_ERROR("%s\n", err.c_str());

    string groups_text = generate_groups_text(groups_data);
    string connections_text = generate_connections_text(groups_data);
    string headers_text = generate_headers_text(groups_data);
    string events_text = generate_events_text(groups_data);
    string map_header_text = generate_map_constants_text(groups_filepath, groups_data);

    string file_dir = get_directory_name(groups_filepath);
    char s = file_dir.back();

    write_text_file(file_dir + "groups.inc", groups_text);
    write_text_file(file_dir + "connections.inc", connections_text);
    write_text_file(file_dir + "headers.inc", headers_text);
    write_text_file(file_dir + "events.inc", events_text);
    write_text_file(file_dir + ".." + s + ".." + s + "include" + s + "constants" + s + "map_groups.h", map_header_text);
}

string generate_layout_headers_text(Json layouts_data) {
    ostringstream text;

    text << "@\n@ DO NOT MODIFY THIS FILE! It is auto-generated from data/layouts/layouts.json\n@\n\n";

    for (auto &layout : layouts_data["layouts"].array_items()) {
        string border_label = layout["name"].string_value() + "_Border";
        string blockdata_label = layout["name"].string_value() + "_Blockdata";
        text << border_label << "::\n"
             << "\t.incbin \"" << layout["border_filepath"].string_value() << "\"\n\n"
             << blockdata_label << "::\n"
             << "\t.incbin \"" << layout["blockdata_filepath"].string_value() << "\"\n\n"
             << "\t.align 2\n"
             << layout["name"].string_value() << "::\n"
             << "\t.4byte " << layout["width"].int_value() << "\n"
             << "\t.4byte " << layout["height"].int_value() << "\n"
             << "\t.4byte " << border_label << "\n"
             << "\t.4byte " << blockdata_label << "\n"
             << "\t.4byte " << layout["primary_tileset"].string_value() << "\n"
             << "\t.4byte " << layout["secondary_tileset"].string_value() << "\n\n";
    }

    return text.str();
}

string generate_layouts_table_text(Json layouts_data) {
    ostringstream text;

    text << "@\n@ DO NOT MODIFY THIS FILE! It is auto-generated from data/layouts/layouts.json\n@\n\n";

    text << "\t.align 2\n"
         << layouts_data["layouts_table_label"].string_value() << "::\n";

    for (auto &layout : layouts_data["layouts"].array_items())
        text << "\t.4byte " << layout["name"].string_value() << "\n";

    return text.str();
}

string generate_layouts_constants_text(Json layouts_data) {
    ostringstream text;

    text << "#ifndef GUARD_CONSTANTS_LAYOUTS_H\n"
         << "#define GUARD_CONSTANTS_LAYOUTS_H\n\n";

    text << "//\n// DO NOT MODIFY THIS FILE! It is auto-generated from data/layouts/layouts.json\n//\n\n";

    int i = 0;
    for (auto &layout : layouts_data["layouts"].array_items())
        text << "#define " << layout["id"].string_value() << " " << ++i << "\n";

    text << "\n#endif // GUARD_CONSTANTS_LAYOUTS_H\n";

    return text.str();
}

void process_layouts(string layouts_filepath) {
    string err;
    Json layouts_data = Json::parse(read_text_file(layouts_filepath), err);

    if (layouts_data == Json())
        FATAL_ERROR("%s\n", err.c_str());

    string layout_headers_text = generate_layout_headers_text(layouts_data);
    string layouts_table_text = generate_layouts_table_text(layouts_data);
    string layouts_constants_text = generate_layouts_constants_text(layouts_data);

    string file_dir = get_directory_name(layouts_filepath);
    char s = file_dir.back();

    write_text_file(file_dir + "layouts.inc", layout_headers_text);
    write_text_file(file_dir + "layouts_table.inc", layouts_table_text);
    write_text_file(file_dir + ".." + s + ".." + s + "include" + s + "constants" + s + "layouts.h", layouts_constants_text);
}

int main(int argc, char *argv[]) {
    if (argc < 3)
        FATAL_ERROR("USAGE: mapjson <mode> <game-version> [options]\n");

    char *version_arg = argv[2];
    string version(version_arg);
    if (version != "emerald" && version != "ruby")
        FATAL_ERROR("ERROR: <game-version> must be 'emerald' or 'ruby'.\n");

    char *mode_arg = argv[1];
    string mode(mode_arg);
    if (mode != "layouts" && mode != "map" && mode != "groups")
        FATAL_ERROR("ERROR: <mode> must be 'layouts', 'map', or 'groups'.\n");

    if (mode == "map") {
        if (argc != 5)
            FATAL_ERROR("USAGE: mapjson map <game-version> <map_file> <layouts_file>\n");

        string filepath(argv[3]);
        string layouts_filepath(argv[4]);

        process_map(filepath, layouts_filepath, version);
    }
    else if (mode == "groups") {
        if (argc != 4)
            FATAL_ERROR("USAGE: mapjson groups <game-version> <groups_file>\n");

        string filepath(argv[3]);

        process_groups(filepath);
    }
    else if (mode == "layouts") {
        if (argc != 4)
            FATAL_ERROR("USAGE: mapjson layouts <game-version> <layouts_file>\n");

        string filepath(argv[3]);

        process_layouts(filepath);
    }

    return 0;
}
