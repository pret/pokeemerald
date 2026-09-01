import os

MAPS_DIR = "data/maps"

for root, dirs, files in os.walk(MAPS_DIR):
    for file in files:
        if not file.endswith(".json"):
            continue

        if file.endswith("_Frlg.json"):
            continue

        filepath = os.path.join(root, file)

        with open(filepath, "r", encoding="utf-8") as f:
            lines = f.readlines()

        # Skip if region already exists
        if any('"region"' in line for line in lines):
            continue

        new_lines = []
        inserted = False

        for i, line in enumerate(lines):
            new_lines.append(line)

            if '"music"' in line and not inserted:
                # Detect indentation from current line
                indent = line[:len(line) - len(line.lstrip())]

                region_line = f'{indent}"region": "REGION_HOENN",\n'
                new_lines.append(region_line)
                inserted = True

        if inserted:
            with open(filepath, "w", encoding="utf-8") as f:
                f.writelines(new_lines)

            print(f"Updated: {filepath}")

print("Done.")
