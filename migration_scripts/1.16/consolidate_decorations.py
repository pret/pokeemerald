import glob
import re
import os

if not os.path.exists("Makefile"):
    print("Please run this script from your root folder.")
    quit()

# Icons
## Read decoration/icon.h
with open("./src/data/decoration/icon.h", 'r') as file:
    source_content = file.read()

## Extract decoration info from decoration/icon.h
source_pattern = re.compile(r'(\[DECOR_.*\])\s*=\s(\{.*\})*')
source_data = {}
for match in source_pattern.findall(source_content):
    if len(match) == 2:
        decor_name, decor_icon = match
        source_data[decor_name] = (decor_icon)

## Read decoration/header.h content
with open("./src/data/decoration/header.h", 'r') as file:
    destination_content = file.read()

## Modify decoration/header.h content
def add_filter_data(match):
    decor_name = match.group(1)
    if decor_name in source_data:
        decor_icon = source_data[decor_name]
        print(f"Updating {decor_name}: adding {decor_icon}")
        return f'{match.group(0)}\n        .icon = {decor_icon},'
    else:
        return match.group(0)

destination_pattern = re.compile(r'(\[DECOR_[A-Z_0-9]+\])\s*=\s*{\n.*id.*\n.*name.*\n.*permission.*\n.*shape.*\n.*category.*\n.*price.*\n.*description.*\n.*tiles.*')
modified_content = destination_pattern.sub(add_filter_data, destination_content)

## Write the modified content back to decoration/header.h
with open("./src/data/decoration/header.h", 'w') as file:
    file.write(modified_content)
    print("decoration/header.h has been updated")

# Description
## Read decoration/description.h
with open("./src/data/decoration/description.h", 'r') as file:
    source_content = file.read()

## Extract decoration info from decoration/icon.h
source_pattern = re.compile(r'(DecorDesc_.*)\[\]\s*=\s_\(\n\s*(".*"\n\s*".*"(\n\s*".*")?)')
source_data = {}
for match in source_pattern.findall(source_content):
    if len(match) >= 2:
        decor_desc_name, decor_description, third_line = match
        source_data[decor_desc_name] = (decor_description)

## Read decoration/header.h content
with open("./src/data/decoration/header.h", 'r') as file:
    destination_content = file.read()

## Modify decoration/header.h content
def add_filter_data(match):
    decor_desc_name = match.group(2)
    if decor_desc_name in source_data:
        decor_description = source_data[decor_desc_name]
        print(f"Updating {decor_desc_name}: adding {decor_description}")
        return f'{match.group(1)}COMPOUND_STRING(\n        {decor_description}),'
    else:
        return match.group(0)

destination_pattern = re.compile(r'(description\s*=\s*)(DecorDesc_[A-Z_0-9]+),')
modified_content = destination_pattern.sub(add_filter_data, destination_content)
modified_content = modified_content.replace('        "', '            "')

## Write the modified content back to decoration/header.h
with open("./src/data/decoration/header.h", 'w') as file:
    file.write(modified_content)
    print("decoration/header.h has been updated")
