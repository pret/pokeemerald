import argparse
import collections
import re
import shutil
import subprocess

ToDelete = collections.namedtuple('ToDelete', 'path line_number')

def await_warning(line):
    if re.search(r"Warning: explicit waitstate follows implicit waitstate, ignoring", line):
        return (await_info, None)
    else:
        return (await_warning, None)

def await_info(line):
    if m := re.match(r"([^:]+):(\d+):  Info: macro invoked from here", line):
        return (await_warning, ToDelete(m.group(1), int(m.group(2))))
    else:
        # NOTE: Does not handle multiple stacked infos.
        return (await_warning, None)

def main():
    parser = argparse.ArgumentParser(
        prog="delete_implicit_waitstates",
        description="Deletes redundant explicit waitstates",
    )
    parser.add_argument("build")
    args = parser.parse_args()

    make = shutil.which("make")
    p = subprocess.Popen([make, "BUILD={}".format(args.build), "build/{}/data/event_scripts.o".format(args.build), "-W", "data/event_scripts.s"], stdout=subprocess.DEVNULL, stderr=subprocess.PIPE, text=True)

    to_deletes = collections.defaultdict(set)
    state = await_warning
    for line in p.stderr:
        (state, to_delete) = state(line)
        if to_delete:
            to_deletes[to_delete.path].add(to_delete.line_number)

    for path, line_numbers in to_deletes.items():
        with open(path, "r") as f:
            lines = f.readlines()
        with open(path, "w") as f:
            for line_number, line in enumerate(lines, 1):
                # HINT: 'waitstate' not in line implies that this
                # waitstate came from a macro. The user will have to
                # sort that out for themselves.
                if line_number not in line_numbers or 'waitstate' not in line:
                    f.write(line)

if __name__ == '__main__':
    main()
