import copy
from mmap import mmap, ACCESS_READ
from typing import Dict

def main():
    global base_file_name
    global function_name
    base_file_name = "pokenav"
    function_name = "sub_81C84E8"

    src_file_path = "src/%s.c" % base_file_name
    build_file_path = "build/emerald/src/%s.s" % base_file_name

    original_code = getArmCode(src_file_path, "thumb_func_start " + function_name, "thumb_func_end " + function_name)
    generated_code = getArmCode(build_file_path, ".type\t %s,function" % function_name, ".size\t " + function_name)

    if original_code:
        print("Original code:\n", str(process(original_code)))
    else:
        print("Original code not found.")

    if generated_code:
        print("Generated code:\t", str(process(generated_code)))
    else:
        print("generated code not found.")

class VarType:
    # One of: void, int, ptr, unknown, intOrPtr
    major_type: str = "unknown"

    size: int = None
    is_signed: bool = None
    pointed_to_type = None

    def __str__(self):
        if self.major_type == "unknown":
            return "void"
        elif self.major_type == "intOrPtr":
            return "u32"
        elif self.major_type == "ptr":
            return self.pointed_to_type + "*"
        elif self.major_type == "int":
            if self.is_signed:
                return "s" + self.size
            else:
                return "u" + self.size
        else:
            return self.major_type

class HexConst:
    original_string: str = None
    size: int = 32

    def __init__(self, str_value: str = None, int_value: int = None, byte_count: int = None):
        if str_value != None:
            assert(int_value == None)
            if str_value[0] == '#':
                self.original_string = str_value[1:]
            else:
                self.original_string = str_value
            self.size = 32
            if len(self.original_string) <= 2 or self.original_string[1] != 'x':
                self.original_string = intToHex(int(self.original_string), 32)
        elif int_value != None:
            assert(str_value == None)
            assert(byte_count != None)
            self.original_string = intToHex(int_value, byte_count)
            self.size = byte_count * 4

    def __str__(self):
        return "(u%s)%s" % (self.size, self.original_string)

class VarOrConst:
    is_var: bool = None
    var: str = None
    const: HexConst = None

    def __init__(self, value: str):
        if value[0].isalpha():
            self.is_var = True
            self.var = value
        else:
            self.is_var = False
            self.const = HexConst(str_value=value)
    
    def __str__(self):
        if self.is_var:
            return "Var(%s)" % self.var
        else:
            return "Const(%s)" % str(self.const)

class SSABlockLabel:
    name: str = None
    live_vars = {}

class BasicBlock:
    lines = None
    end_conditional = None
    unconditional_label: str = None
    true_label: str = None
    false_label: str = None

class AsmInstr:
    pass

class LabelInstr(AsmInstr):
    name: str = None

    def __init__(self, name: str):
        self.name = name
    
    def __str__(self):
        return self.name + ':'

class ConstantDataInstr(AsmInstr):
    data: VarOrConst = None

    def __init__(self, data: str):
        self.data = VarOrConst(data)

    def __str__(self):
        return ".data %s" % str(self.data)

class BinopInstr(AsmInstr):
    op: str = None
    dest: str = None
    src1: str = None
    src2: VarOrConst = None

    def __init__(self, op: str, dest: str, src1: str, src2: str):
        self.op = op
        self.dest = dest
        self.src1 = src1
        self.src2 = VarOrConst(src2)

    def __str__(self):
        return "%s = %s(%s, %s)" % (self.dest, self.op, self.src1, str(self.src2))

class UnopInstr(AsmInstr):
    op: str = None
    dest: str = None
    src: VarOrConst = None

    def __init__(self, op: str, dest: str, src: str):
        self.op = op
        self.dest = dest
        self.src = VarOrConst(src)

    def __str__(self):
        return "%s = %s(%s)" % (self.dest, self.op, str(self.src))

class BranchInstr(AsmInstr):
    op: str = None
    label: str = None

    def __init__(self, op, label):
        self.op = op
        self.label = label

    def __str__(self):
        return "%s %s" % (self.op, self.label)

class CompareInstr(AsmInstr):
    left: str = None
    right: str = None

    def __init__(self, left, right):
        self.left = left
        self.right = right

    def __str__(self):
        return "cmp %s, %s" % (self.left, self.right)

class LoadInstr(AsmInstr):
    size: int = None
    dest: str = None
    ptr: str = None
    offset: HexConst = None

    def __init__(self, size: int, dest: str, ptr: str, offset: HexConst):
        self.size = size
        self.dest = dest
        self.ptr = ptr
        self.offset = offset

    def __str__(self):
        return "%s = (u%s)(%s[%s])" % (self.dest, self.size, self.ptr, str(self.offset))

class StoreInstr(AsmInstr):
    size: int = None
    src: str = None
    ptr: str = None
    offset: HexConst = None

    def __init__(self, size: int, src: str, ptr: str, offset: HexConst):
        self.size = size
        self.src = src
        self.ptr = ptr
        self.offset = offset

    def __str__(self):
        return "%s[%s] = (u%s)%s" % (self.ptr, str(self.offset), self.size, self.src)

class LoadAddressInstr(AsmInstr):
    dest: str = None
    # Note: "Var" in this case means the address of a global
    # symbol (variable, label, or function name)
    const: VarOrConst = None

    def __init__(self, dest: str, literal: str):
        self.dest = dest
        self.const = VarOrConst(literal)

    def __str__(self):
        if self.const.is_var:
            return "%s = &%s" % (self.dest, self.const.var)
        else:
            return "%s = %s" % (self.dest, str(self.const))

class CallInstr(AsmInstr):
    name: str = None

    def __init__(self, name):
        self.name = name

    def __str__(self):
        return "call " + self.name

class ArmFunction:
    lines = []
    name: str = None
    blocks: Dict[str, BasicBlock] = []
    return_type: VarType = VarType()

    def __str__(self):
        ret = "{\n\tname: %s\n\treturn_type: %s\n\tblocks: {" % (self.name, self.return_type)
        for label, block in self.blocks:
            ret += "\n\t\t'%s': %s" % (label, block)
        if len(self.blocks) != 0:
            ret += "\n\t"
        ret += "}\n\tlines: ["
        for line in self.lines:
            ret += "\n\t\t" + str(line)
        if len(self.lines) != 0:
            ret += "\n\t"
        ret += "]\n}"

        return ret

def process(raw_asm: str):
    lines = splitIntoLines(raw_asm)

    func = ArmFunction()
    func.lines = lines
    func.name = function_name

    discard_header(func)
    discard_footer(func)
    remove_comments(func)
    parse_func(func)

    return func

# Search a file for matching arm code.
# Mmap approach based on: https://stackoverflow.com/questions/4940032/
def getArmCode(path: str, start_search_str: str, end_search_str: str) -> str:
    assert(path != None)

    with open(path) as file:
        file_bytes = mmap(file.fileno(), 0, access=ACCESS_READ)
        start_offset = file_bytes.find(start_search_str.encode())
        if start_offset == -1:
            return None
        
        end_offset = file_bytes.find(end_search_str.encode(), start_offset)
        if end_offset == -1:
            raise Exception("Error: %s found, but %s not found" % (start_search_str, end_search_str))
        
        return file_bytes[start_offset:end_offset + len(end_search_str)].decode()

def splitIntoLines(raw_asm: str) -> [str]:
    # Remove all tabs.
    raw_asm = raw_asm.replace('\t', ' ')

    # Split into lines and strip them
    lines = [line.strip() for line in raw_asm.split('\n')]

    DISCARD_LINES = ['', '.pool', '.align 2, 0', '.thumb_func']

    # Discard junk lines.
    lines = [line for line in lines if line not in DISCARD_LINES]

    return lines

# Split the input into separate functions
"""def separateIntoFuncs(lines: [str]) -> [[str]]:
    funcs = []
    current_func = []
    for line in lines:
        if line.startswith("thumb_func_start"):
            current_func = [line]
        elif line.startswith("thumb_func_end"):
            current_func.append(line)
            funcs.append(current_func)
        else:
            current_func.append(line)
    return funcs


# Extract the name of the function.
def find_name(func):
    name = func[0].split(' ')[1]
    # Delete the thumb_func_start line
    del func[0]
    # Delete the sub_43437922354230457: @527230472350 line.
    del func[0]
    del func[-1]
    return {
        "name": name,
        "asm": func
    }"""

# Ignore the pushing stuff.
def discard_header(func):
    header_end = 0
    for i, line in enumerate(func.lines):
        if line.startswith("push"):
            header_end = i
    
    for i in range(0, header_end + 1):
        del func.lines[0]

# Ignore popping stuff.
def discard_footer(func):
    footer_start = 0
    del func.lines[-1]
    for i, line in enumerate(func.lines):
        if line[0].isalpha():
            return_line = line

    for i, line in enumerate(func.lines):
        if line.startswith("pop"):
            footer_start = i
            break
    length = len(func.lines)
    for i in range(footer_start, length):
        del func.lines[-1]
    
    if return_line == "bx r0" or return_line == "bx lr":
        func.return_type.major_type = "void"
    elif return_line == "bx r1":
        func.return_type.major_type = "intOrPtr"
    else:
        raise Exception("Unrecognized return line '%s'" % return_line)

def remove_comments(func):
    for i in range(0, len(func.lines)):
        line = func.lines[i]
        comment_index = line.find('@')
        if comment_index != -1:
            func.lines[i] = line[:comment_index]

BINOPS = ['add', 'sub', 'lsr', 'asr', 'lsl']
UNOPS = ['neg', 'mvn']

def get_size_suffix(op: str) -> int:
    if len(op) == 3:
        return 32
    elif op[3] == 'b':
        return 8
    elif op[3] == 'h':
        return 16
    else:
        raise Exception("Unknown size suffix: %s" % op)

# Convert the lines into data structures.
def parse_asm(line: str) -> AsmInstr:
    if line[-1] == ':':
        if line[0] == '.':
            return LabelInstr(line[1:-1])
        else:
            return LabelInstr(line[:-1])

    op_cutoff_index = line.find(' ')
    op = line[:op_cutoff_index]
    rest = line[(op_cutoff_index + 1):]
    
    if op[0] == 'b':
        if op == 'bl':
            return CallInstr(rest)
        else:
            return BranchInstr(op, rest)

    tokens = [s.strip() for s in rest.split(',')]

    if op == 'cmp':
        return CompareInstr(tokens[0], tokens[1])
    elif op.startswith('mov'):
        return UnopInstr('mov', tokens[0], tokens[1])
    elif op[0:3] in BINOPS:
        if len(tokens) == 2:
            return BinopInstr(op, tokens[0], tokens[0], tokens[1])
        else:
            return BinopInstr(op, tokens[0], tokens[1], tokens[2])
    elif op[0:3] in UNOPS:
        return UnopInstr(op, tokens[0], tokens[1])
    elif op.startswith('ldr'):
        if tokens[1][0] == '=' or tokens[1][0] == '.':
            return LoadAddressInstr(tokens[0], tokens[1][1:])
        
        assert(tokens[1][0] == '[')
        size = get_size_suffix(op)

        ptr = None
        offset = None
        if len(tokens) == 2:
            ptr = tokens[1][1:-1]
            offset = HexConst(int_value=0, byte_count=2)
        else:
            ptr = tokens[1][1:]
            offset = HexConst(str_value=tokens[2][:-1])
        
        return LoadInstr(size, tokens[0], ptr, offset)
    elif op.startswith('str'):
        size = get_size_suffix(op)

        ptr = None
        offset = None
        if len(tokens) == 2:
            ptr = tokens[1][1:-1]
            offset = HexConst(int_value=0, byte_count=2)
        else:
            ptr = tokens[1][1:]
            offset = HexConst(str_value=tokens[2][:-1])

        return StoreInstr(size, tokens[0], ptr, offset)
    elif op == ".word":
        return ConstantDataInstr(rest)
    else:
        raise Exception("Unknown opcode: %s (%s)" % (op, line))
        
def parse_func(func):
    parsed = [parse_asm(line) for line in func.lines]
    func.lines = parsed

def get_regs_from_instr(instr: AsmInstr) -> (str, [str]):
    if type(instr) == ConstantDataInstr:
        return (None, None)
    elif type(instr) == BinopInstr:
        src_vars = [instr.src1]
        if instr.src2.is_var:
            src_vars.append(instr.src2.var)
        return (instr.dest, src_vars)
    elif type(instr) == UnopInstr:
        if instr.src.is_var:
            return (instr.dest, [instr.src])
        else:
            return (None, None)
    elif type(instr) == LoadAddressInstr:
        return (instr.dest, None)
    elif type(instr) == StoreInstr:
        return (None, [instr.ptr, instr.src])
    elif type(instr) == LoadInstr:
        return (instr.dest, [instr.ptr])
    elif type(instr) == CallInstr:
        return ('r0', None)
    else:
        raise Exception("Unknown instruction type: " + type(str(instr)))

def do_liveness_check(func):
    live_vars = {
        "r0": "a0",
        "r1": "a1",
        "r2": "a2",
        "r3": "a3"
    }
    local_var_count = 0
    for instr in func["asm"]:
        if instr["kind"] == "call":
            # Guess at params
            params = []
            for i in range(0, 4):
                reg = "r" + str(i)
                if reg in live_vars:
                    params.append(live_vars[reg])
                else:
                    # If an argument is guaranteed to be junk, then it's not an argument.
                    # If it's not an argument, the rest aren't either.
                    break
            instr["params"] = params
   
            # r1, r2, and r3 are clobbered.
            for reg in ["r1", "r2", "r3"]:
                if reg in live_vars:
                    del live_vars[reg]
            
            # r0 is clobbered, and replaced with a possible return value.
            name = "v" + str(local_var_count)
            live_vars["r0"] = name
            instr["return"] = name
            local_var_count += 1
        elif instr["kind"] == "branch":
            raise Exception("Branches not implemented yet.")
        elif instr["kind"] == "cmp":
            first = instr["first"]
            second = instr["second"]
            if first in live_vars:
                instr["first"] = live_vars[first]
            if second in live_vars:
                instr["second"] = live_vars[second]
                
        elif instr["kind"] == "store":
            src = instr["src"]
            ptr = instr["ptr"]
            offset = instr["offset"]
            if src in live_vars:
                instr["src"] = live_vars[src]
            if ptr in live_vars:
                instr["ptr"] = live_vars[ptr]
            if offset in live_vars:
                instr["offset"] = live_vars[offset]
        
        elif instr["kind"] == "load":
            # Evaluate ptr and offset first.
            ptr = instr["ptr"]
            offset = instr["offset"]
            if ptr in live_vars:
                instr["ptr"] = live_vars[ptr]
            if offset in live_vars:
                instr["offset"] = live_vars[offset]
            
            # Replace the destination with a new var.
            name = "v" + str(local_var_count)
            live_vars[instr["dest"]] = name
            instr["dest"] = name
            local_var_count += 1
        
        elif instr["kind"] == "loadAddress":
            # Replace the destination with a new var.
            name = "v" + str(local_var_count)
            live_vars[instr["dest"]] = name
            instr["dest"] = name
            local_var_count += 1
            
        elif instr["kind"] == "move":
            # Evaluate the source first.
            src = instr["src"]
            if src in live_vars:
                instr["src"] = live_vars[src]
            
            # Replace the destination with a new var.
            name = "v" + str(local_var_count)
            live_vars[instr["dest"]] = name
            instr["dest"] = name
            local_var_count += 1
        
        elif instr["kind"] == "normal":
            # Evaluate the sources first.
            src1 = instr["src1"]
            src2 = instr["src2"]
            if src1 in live_vars:
                instr["src1"] = live_vars[src1]
            if src2 in live_vars:
                instr["src2"] = live_vars[src2]
            
            # Replace the destination with a new var.
            name = "v" + str(local_var_count)
            live_vars[instr["dest"]] = name
            instr["dest"] = name
            local_var_count += 1
            
        else:
            raise Exception("Unknown instruction kind: " + str(instr))
            
    # Save the return value's name.
    if func["return_type"] != "void" and "r0" in live_vars:
        func["return_var"] = live_vars["r0"]
    
    return func
            
            
def print_ssa_as_asm(func):
    message = ""
    
    # Print out the header
    message += func["return_type"] + ' '
    message += func["name"] + '(a0, a1, a2, a3) {\n'
    
    # Print out each instruction.
    for instr in func["asm"]:
        message += '\t' + print_instr(instr) + '\n'
    
    # Print the return statement, if any.
    if "return_var" in func:
        message += "\treturn " + func["return_var"] + '\n'
    
    # Close the function.
    message += "}\n"
    
    return message

def print_instr(instr):
    if instr["kind"] == "branch":
        raise Exception("Branches not supported yet.")
    elif instr["kind"] == "cmp":
        return instr["op"] + ' ' + instr["first"] + ', ' + instr["second"]
    elif instr["kind"] == "normal":
        message = instr["dest"] + ' = '
        if instr["op"].startswith("add"):
            message += instr["src1"] + ' + ' + instr["src2"]
        elif instr["op"].startswith("and"):
            message += instr["src1"] + ' & ' + instr["src2"]
        elif instr["op"].startswith("neg"):
            message += instr["src1"] + ' * -1'
        else:
            message += instr["op"] + '(' + instr["src1"] + ', ' + instr["src2"] + ')'
        return message
    elif instr["kind"] == "call":
        message = instr["return"] + ' = ' + instr["label"] + '('
        for param in instr["params"]:
            message += param + ', '
        
        # Strip the last ', ' off.
        message = message[:-2]
        
        message += ')'
        return message
    elif instr["kind"] == "move":
        return instr["dest"] + ' = ' + instr["src"]
    elif instr["kind"] == "store":
        message = ""
        if instr["offset"] == "0" or instr["offset"] == "0x0":
            message = "*" + instr["ptr"]
        else:
            message = instr["ptr"] + '[' + instr["offset"] + ']'
        message += ' = ' + instr["src"]
        return message
    elif instr["kind"] == "load":
        message = instr["dest"] + ' = '
        if instr["offset"] == 0 or instr["offset"] == "0x0":
            message += "*" + instr["ptr"]
        else:
            message += instr["ptr"] + '[' + instr["offset"] + ']'
        return message
    elif instr["kind"] == "loadAddress":
        return instr["dest"] + ' = &' + instr["label"]
    else:
        raise Exception("Unknown instruction kind: " + str(instr))
        
# Source: https://stackoverflow.com/questions/6727875
def hexToInt(hexString, byteLength):
    value = int(hexString, 16)
    bitCount = byteLength * 8
    if value & (1 << (bitCount - 1)):
        value -= 1 << bitCount
    return value

# Source: https://stackoverflow.com/questions/7822956
def intToHex(value: int, byteLength: int) -> str:
    bitCount = byteLength * 8
    value = (value + (1 << bitCount)) % (1 << bitCount)
    return hex(value)

def instr_to_statement(instr, var_names):
    if instr["kind"] == "branch":
        raise Exception("Not implemented")
    elif instr["kind"] == "call":
        var_names[instr["return"]] = {
            "type": "unknown"
        }

        return {
            "kind": "=",
            "left": {
                "kind": "var",
                "name": instr["return"],
            },
            "right": {
                "kind": "call",
                "function": {
                    "kind": "symbolName",
                    "name": instr["label"]
                },
                "params": instr["params"],
            }
        }
    elif instr["kind"] == "cmp":
        raise Exception("Not implemented")
    elif instr["kind"] == "load":
        dest = instr["dest"]
        if instr["op"] == "ldr":
            var_names[dest] = {
                "type": "intOrPtr"
            }
        elif instr["op"] == "ldrh":
            var_names[dest] = {
                "type": "int",
                "size": "16",
                "sign": "unknown"
            }
        elif instr["op"] == "ldrb":
            var_names[dest] = {
                "type": "int",
                "size": "8",
                "sign": "unknown"
            }
        else:
            raise Exception("Unknown load instruction: " + str(instr))

        offsetExpr = {}
        if instr["offset"][0].isalpha():
            offsetExpr = {
                "kind": "var",
                "name": instr["offset"]
            }
        else:
            offsetExpr = {
                "kind": "const",
                "value": instr["offset"]
            }

        return {
            "kind": "=",
            "left": {
                "kind": "var",
                "name": dest
            },
            "right": {
                "kind": "ptrOffset",
                "ptr": {
                    "kind": "var",
                    "name": instr["ptr"]
                },
                "offset": offsetExpr
            }
        }
    elif instr["kind"] == "loadAddress":
        dest = instr["dest"]
        var_names[dest] = {
            "type": "ptr",
            "to_type": "unknown"
        }
        return {
            "kind": "=",
            "left": {
                "kind": "var",
                "name": dest
            },
            "right": {
                "kind": "symbolName",
                "name": instr["label"]
            }
        }
    elif instr["kind"] == "store":
        offsetExpr = {}
        if instr["offset"][0].isalpha():
            offsetExpr = {
                "kind": "var",
                "name": instr["offset"]
            }
        else:
            offsetExpr = {
                "kind": "const",
                "value": instr["offset"]
            }
        
        return {
            "kind": "=",
            "left": {
                "kind": "ptrOffset",
                "ptr": {
                    "kind": "var",
                    "name": instr["ptr"]
                },
                "offset": offsetExpr
            },
            "right": {
                "kind": "var",
                "name": instr["src"]
            }
        }
    elif instr["kind"] == "move":
        dest = instr["dest"]
        src = instr["src"]
        
        src_expr = {}
        if src[0].isalpha():
            src_type = var_names[src]
            var_names[dest] = copy.deepcopy(src_type)
            
            src_expr = {
                "kind": "var",
                "name": src
            }
        else:
            src_expr = {
                "kind": "const",
                "value": src
            }
        
        return {
            "kind": "=",
            "left": {
                "kind": "var",
                "name": dest
            },
            "right": src_expr
        }
    elif instr["kind"] == "normal":
        var_names[instr["dest"]] = {
            "type": "unknown"
        }
        return normal_instr_to_statement(instr)
    else:
        raise Exception("Unknown instruction kind: " + str(instr))

def normal_instr_to_statement(instr):
    op = instr["op"]
    src1 = instr["src1"]
    src2 = instr["src2"]
    dest = instr["dest"]
    src2_expr = {}
    if src2[0].isalpha():
        src2_expr = {
            "kind": "var",
            "name": src2
        }
    else:
        src2_expr = {
            "kind": "const",
            "value": src2
        }
    
    kind = ""
    number_of_params = 2
    if op.startswith("add"):
        kind = "+"
    elif op.startswith("sub"):
        kind = "-"
    elif op.startswith("lsl"):
        kind = "<<"
    elif op.startswith("lsr"):
        kind = ">> unsigned"
    elif op.startswith("ssr"):
        kind = ">> signed"
    elif op.startswith("and"):
        kind = "&"
    elif op.startswith("or"):
        kind = "|"
    elif op.startswith("neg"):
        kind = "neg"
        number_of_params = 1
    else:
        raise Exception("Unknown op: " + str(instr))
    
    right_expr = {}
    if number_of_params == 2:
        right_expr = {
            "kind": kind,
            "left": {
                "kind": "var",
                "name": src1
            },
            "right": src2_expr
        }
    else:
        right_expr = {
            "kind": kind,
            "left": {
                "kind": "var",
                "name": src1
            }
        }
        
    return {
        "kind": "=",
        "left": {
            "kind": "var",
            "name": dest
        },
        "right": right_expr
    }
        
def build_ast(func):
    statements = []
    var_names = {
        "a0": { "type": "unknown" },
        "a1": { "type": "unknown" },
        "a2": { "type": "unknown" },
        "a3": { "type": "unknown" }
    }
    for instr in func["asm"]:
        statements.append(instr_to_statement(instr, var_names))
    del func["asm"]
    func["statements"] = statements
    func["vars"] = var_names
    return func

""" Statement Docs

Anything other than the 'kind' field can have an arbitrary expression tree inside.

kinds:
    '=': assignment of right into left.
    '+', '-', '&', '|': add, subtract, and, or
    '<<': shift left
    '>> unsigned': shift right unsigned
    '>> signed': shift right signed
    'var': A variable with a name. Name is contained in 'name'.
    'const': A constant value. Value is contained in 'value'
    'ptrOffset': A pointer plus some offset. 'ptr' is the pointer, 'offset' is the offset.
    'neg': Negate the value in 'left'
    'symbolName': The address of some global symbol. The name of the symbol is in 'name'
    'call': A call to a function. Function address is in 'function', parameter list is in 'params'
"""
""

if __name__ == "__main__":
    main()