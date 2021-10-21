## SYNTAX ##

AND = "^"
PUSH = "PUSH"
DIRECT = ">>"
ADD = "ADD" # ADD uses int values to add two values
ADDF = "ADDF" # ADDF uses float values to add two values
CONCAT = "CONCAT" # Joins two string values to concat two string values
COUT = "COUT"
HALT = "HALT"
HEAP = "HEAP"

## VARS ##

file = 0

## LOGGING ##

def log(log):
    print("| LOG } " + log)
def errlog(log):
    print("E| ERR | " + log)

## PARSER ##

I_HEAP = []
EVAL_HEAP = []

def ADD_INTEGERS(line):
    log(line)
    local_line = str(line).strip().split(" ")
    int1 = int(local_line[1]) 
    int2 = int(local_line[2]) 
    log(str(int1 + int2))

def ADD_FLOATS(line):
    log(line)
    local_line = str(line).strip()

def CONCAT(line):
    log(line)

def PUSH_HEAP(line,value):
    log(line + " pushing to HEAP with value " + value)
    EVAL_HEAP.append(value)

def HALT(line):
    log(line)
    exit()

def parser(fname):
    lnum = 0
    file = open(fname, "r")
    for line in file.readlines():
        # ACTUAL PARSING
        lnum + 1   
        if ADD in line.strip() == True & AND + " " + PUSH + " " + HEAP in line.strip() == True:
            log("Adding and pushing to heap")
            l_int = ADD_INTEGERS(line)
            PUSH_HEAP(line, l_int)
        elif (ADD in line.strip()) == True & (AND + " " + PUSH + " " + HEAP in line.strip()) != True:
            ADD_INTEGERS(line)
        