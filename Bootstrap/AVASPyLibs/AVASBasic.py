## SYNTAX ##

PUSH = "PUSH"
INT ="~"
DIRECT = ">>"
ADD = "ADD"
COUT = "COUT"
HALT = "HALT"
HEAP = "HEAP"

## LOGGING ##

def log(log):
    print("| LOG } " + log)
def errlog(log):
    print("E| ERR | " + log)

## PARSER ##

def ADD_INTEGERS(line):
    log(line)
    local_line = str(line).strip()

def PUSH_HEAP():
    log(line)

def parser(fname):
    lnum = 0
    I_HEAP = []
    EVAL_HEAP = []
    file = open(fname, "r")
    for line in file.readlines():
        log(line.replace("\n", ""))  
        lnum + 1   
        if (ADD + INT) in line.strip():
            ADD_INTEGERS(line)
        