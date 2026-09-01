import argparse
import collections
import os
import subprocess
import sys

def address(string):
    if string.startswith("0x"):
        return int(string, base=0)
    else:
        return int(string, base=16)

parser = argparse.ArgumentParser(
    prog="find_func",
    description="Looks up a symbol in an ELF file by address",
)

parser.add_argument("filename")
parser.add_argument("address", type=address)

args = parser.parse_args()

try:
    f = open(args.filename, 'rb')
except FileNotFoundError:
    print("file not found: '{}'".format(args.filename))
    quit(2)

with f as file:
    if file.read(4) != b'\x7fELF':
        print("file not an ELF: '{}'".format(args.filename))
        quit(2)

result = subprocess.run(['arm-none-eabi-objdump', '-t', args.filename], stdout=subprocess.PIPE)

Symbol = collections.namedtuple('Symbol', 'name address_start address_end')

symbols = []

for line in result.stdout.decode('utf-8').splitlines():
    columns = line.split()
    if len(columns) in {5, 6} and "*ABS*" not in line:
        address_start = int(columns[0], base=16)
        size = int(columns[-2], base=16)
        name = columns[-1]
        symbols.append(Symbol(name=name, address_start=address_start, address_end=address_start + size))

found = False
closest_before = None
closest_after = None
for symbol in symbols:
    if symbol.address_start <= args.address < symbol.address_end:
        print("{} (offset {})".format(symbol.name, hex(args.address - symbol.address_start)))
        found = True
    elif not found:
        if args.address > symbol.address_end and (not closest_before or symbol.address_end > closest_before.address_end):
            closest_before = symbol
        if args.address < symbol.address_start and (not closest_after or symbol.address_start < closest_after.address_start):
            closest_after = symbol

if not found:
    print("no symbol found at address {}".format(hex(args.address)))
    if closest_before or closest_after:
        print("closest symbols:")
        if closest_before:
            print("{} at address [{}..{})".format(closest_before.name, hex(closest_before.address_start), hex(closest_before.address_end)))
        if closest_after:
            print("{} at address [{}..{})".format(closest_after.name, hex(closest_after.address_start), hex(closest_after.address_end)))
    quit(1)
