import re
import os

if not os.path.exists("Makefile"):
    print("Please run this script from your root folder.")
    quit()

for easy_chat_file in ["actions", "adjectives", "battle", "conditions", "endings", "events", "feelings", "greetings",
                       "hobbies", "lifestyle", "misc", "people", "speech", "status", "time", "trainer",
                       "trendy_saying", "voices"]:
    filePath = f"./src/data/easy_chat/easy_chat_group_{easy_chat_file}.h"

    # Read easy chat file
    with open(filePath, "r") as f:
        source_content = f.read()

    # Extract text from easy chat file
    source_pattern = re.compile(r'const u8 gEasyChatWord_(.*)\[\]\s*=\s_(\(".*"\))*')
    source_data = {}
    for match in source_pattern.findall(source_content):
        if len(match) == 2:
            var_name, easy_chat_text = match
            source_data[var_name] = (easy_chat_text)

    # Read easy chat file content
    with open(filePath, "r") as f:
        destination_content = f.read()

    # Modify easy chat file content
    def add_filter_data(match):
        var_name = match.group(1)
        if var_name in source_data:
            easy_chat_text = source_data[var_name]
            print(f"Updating {var_name}: adding {easy_chat_text}")
            return f'.text = COMPOUND_STRING{easy_chat_text},'
        else:
            return match.group(0)

    destination_pattern = re.compile(r'.text = gEasyChatWord_(.*),')
    modified_content = destination_pattern.sub(add_filter_data, destination_content)

    # Write the modified content back to easy chat file
    with open(filePath, "w") as f:
        f.write(modified_content)
        print(f"{easy_chat_file}.h has been updated")
