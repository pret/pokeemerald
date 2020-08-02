// jsonproc.cpp

#include "jsonproc.h"

#include <map>
#include <regex>
#include <string>
#include <vector>

using std::string;
using std::to_string;
using std::vector;

#include <inja.hpp>
using namespace inja;
using json = nlohmann::json;

std::map<string, string> customVars;

static vector<string> split(const string &value, const char separator)
{
    vector<string> splits;

    size_t start = 0, pos;
    while ((pos = value.find(separator, start)) != string::npos) {
        splits.push_back(value.substr(start, pos - start));
        start = pos + 1;
    }
    splits.push_back(value.substr(start));

    return splits;
}

static string replace(const string &valuearg, const string &substr, const string &newsubstr)
{
    return std::regex_replace(valuearg, std::regex(substr), newsubstr);
}


void set_custom_var(string key, string value)
{
    customVars[key] = value;
}

string get_custom_var(string key)
{
    return customVars[key];
}

int main(int argc, char *argv[])
{
    if (argc != 4)
        FATAL_ERROR("USAGE: jsonproc <json-filepath> <template-filepath> <output-filepath>\n");

    string jsonfilepath = argv[1];
    string templateFilepath = argv[2];
    string outputFilepath = argv[3];

    Environment env;

    // Add custom command callbacks.
    env.add_callback("doNotModifyHeader", 0, [jsonfilepath, templateFilepath](Arguments& args) {
        return "//\n// DO NOT MODIFY THIS FILE! It is auto-generated from " + jsonfilepath +" and Inja template " + templateFilepath + "\n//\n";
    });

    env.add_callback("subtract", 2, [](Arguments& args) {
        int minuend = args.at(0)->get<int>();
        int subtrahend = args.at(1)->get<int>();

        return minuend - subtrahend;
    });

    env.add_callback("setVar", 2, [=](Arguments& args) {
        string key = args.at(0)->get<string>();
        string value = args.at(1)->get<string>();
        set_custom_var(key, value);
        return "";
    });

    env.add_callback("setVarInt", 2, [=](Arguments& args) {
        string key = args.at(0)->get<string>();
        string value = to_string(args.at(1)->get<int>());
        set_custom_var(key, value);
        return "";
    });

    env.add_callback("getVar", 1, [=](Arguments& args) {
        string key = args.at(0)->get<string>();
        return get_custom_var(key);
    });

    env.add_callback("concat", 2, [](Arguments& args) {
        string first = args.at(0)->get<string>();
        string second = args.at(1)->get<string>();
        return first + second;
    });

    env.add_callback("removePrefix", 2, [](Arguments& args) {
        string rawValue = args.at(0)->get<string>();
        string prefix = args.at(1)->get<string>();
        string::size_type i = rawValue.find(prefix);
        if (i != 0)
            return rawValue;

        return rawValue.erase(0, prefix.length());
    });

    env.add_callback("removeSuffix", 2, [](Arguments& args) {
        string rawValue = args.at(0)->get<string>();
        string suffix = args.at(1)->get<string>();
        string::size_type i = rawValue.rfind(suffix);
        if (i == string::npos)
            return rawValue;

        return rawValue.substr(0, i);
    });

    /**
     * Convert a name to a C-compliant variable name
     */
    env.add_callback("cvar", 1, [](Arguments &args) {
        string name = args.at(0)->get<string>();
        name = replace(name, ". ", "_");
        name = replace(name, "-", "_");
        name = replace(name, "'", "");
        name = replace(name, "♀", "_F");
        name = replace(name, "♂", "_M");
        return name;
    });

    /**
     * Sort an array according to a particular key.
     * A "/" character is the field separator.
     * Objects missing any of the sort keys are
     * ordered first.
     */
    env.add_callback("sort", 2, [](Arguments &args) {
        const json *jsrc = args.at(0);
        json jarray = *jsrc;

        const vector<string> delims = split(args[1]->get<string>(), '/');

        std::sort(jarray.begin(), jarray.end(), [args, delims](const json &left, const json &right) {
            const json *jleft = &left;
            const json *jright = &right;
            for (const auto &delim : delims) {
                auto maybeleft = jleft->find(delim);
                auto mayberight = jright->find(delim);
                if (maybeleft == jleft->end()) {
                    return true;
                } else if (mayberight == jright->end()) {
                    return false;
                }
                jleft = &*maybeleft;
                jright = &*mayberight;
            }
            return jleft->get<int>() <= jright->get<int>();
        });
        return jarray;
    });

    // single argument is a json object
    env.add_callback("isEmpty", 1, [](Arguments& args) {
        return args.at(0)->empty();
    });

    try
    {
        env.write_with_json_file(templateFilepath, jsonfilepath, outputFilepath);
    }
    catch (const std::exception& e)
    {
        FATAL_ERROR("JSONPROC_ERROR: %s\n", e.what());
    }

    return 0;
}
