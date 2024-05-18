import glob
import re
import os

if not os.path.exists("Makefile"):
    print("Please run this script from your root folder.")
    quit()

# Read item_icon_table.h and extract the icon and palette information
for file in glob.glob('./src/data/item_icon_table.h'):
    with open(file, 'r') as f:
        icon_table_content = f.read()

# Extract item icon and palette data from item_icon_table.h
icon_table_pattern = re.compile(r'\[(ITEM_[A-Z_0-9]+)\]\s*=\s*\{([^,]+),\s*([^}]+)\}', re.MULTILINE)
icon_table_data = {}
for match in icon_table_pattern.findall(icon_table_content):
    if len(match) == 3:
        item_name, icon_pic, icon_palette = match
        icon_table_data[item_name] = (icon_pic, icon_palette)

# Read items.h content
for file in glob.glob('./src/data/items.h'):
    with open(file, 'r') as f:
        items_content = f.read()

# Modify items.h content
def add_icon_data(match):
    item_name = match.group(1)
    item_content = match.group(2)
    if item_name in icon_table_data:
        icon_pic, icon_palette = icon_table_data[item_name]
        print(f"Updating {item_name}: adding iconPic = {icon_pic}, iconPalette = {icon_palette}")
        return f'[{item_name}] =\n    {{{item_content}    .iconPic = {icon_pic},\n        .iconPalette = {icon_palette},\n    }},'
    else:
        return match.group(0)

item_pattern = re.compile(r'\[(ITEM_[A-Z_0-9]+)\]\s*=\s*\{([\s\S]*?)\},', re.DOTALL)
modified_items_content = item_pattern.sub(add_icon_data, items_content)

# Write the modified content back to items.h
for file in glob.glob('./src/data/items.h'):
    with open(file, 'w') as f:
        f.write(modified_items_content)
        print("items.h has been updated")
