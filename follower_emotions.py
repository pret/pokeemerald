""" Processes & outputs follower emotion messages """
import sys
import re
import textwrap

blank_regex = re.compile(r'\(?_+\)?')


# Converts a series of message lines to a better format
def convert_messages(infile, outfile='emotions.txt'):
    with open(infile, 'r') as f_in, open(outfile, 'w') as f_out:
        for line in f_in:
            line = line.rstrip('\n')
            if line and line[0] == '-':
                line = line[1:]
            line = line.lstrip()
            if not line:
                continue
            line = blank_regex.sub('{STR_VAR_1}', line)
            if line[-1] not in ('.', '?', '!', ':'):
                line += '.'
            print(line)
            f_out.write('\n' + line)

# Prepares a string for field-message display, performing line-wrapping, etc
# Does not add a terminator, as this is done by _("")
def prepare_string(s):
    lines = textwrap.wrap(s, width=36)  # Width of message window
    s = lines[0]
    for i, line in enumerate(lines[1:]):
        ending = r'\p' if i % 2 else r'\n'
        s += ending + line
    return s


# Exports up to n messages in C format to outfile
def export_messages(infile, outfile, n=None, indent=2):
    with open(infile, 'r') as f_in:
        lines = f_in.readlines()
        if n is not None:
            lines = lines[:n]
    with open(outfile, 'w') as f_out:
        codelines = [' '*indent + f'(const char []) _("{prepare_string(s)}"),' for s in lines]
        f_out.write('\n'.join(codelines))
    print(f'{len(lines)} lines written')
    return len(lines)


if __name__ == '__main__':
    export_messages('emotions.txt', 'emotions.h', n=15)
