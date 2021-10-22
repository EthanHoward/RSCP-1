## OTHER-CODE ##

class Node:
    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.next = None

class HashMap:
    def __init__(self):
        self.store = [None for _ in range(16)]
    def get(self, key):
        index = hash(key) & 15
        if self.store[index] is None:
            return None
        n = self.store[index]
        while True:
            if n.key == key:
                return n.value
            else:
                if n.next:
                    n = n.next
                else:
                    return None
    def put(self, key, value):
        nd = Node(key, value)
        index = hash(key) & 15
        n = self.store[index]
        if n is None:
            self.store[index] = nd
        else:
            if n.key == key:
                n.value = value
            else:
                while n.next:
                    if n.key == key:
                        n.value = value
                        return
                    else:
                        n = n.next
                n.next = nd

## SYNTAX ##

AND = "^"
PUT = "PUT"
DIRECT = ">>"
ADD = "ADD" # ADD uses int values to add two values
ADDF = "ADDF" # ADDF uses float values to add two values
CONCAT = "CONCAT" # Joins two string values to concat two string values
COUT = "COUT"
HALT = "HALT"
HEAP = "HEAP"

## VARS ##

file = 0

BIT_UB = 1023

## LOGGING ##

def log(log):
    print("| LOG } " + log)
def errlog(log):
    print("E| ERR | " + log)

## PARSER ##



HEAP = HashMap()

def ADD_INTEGERS(line):
    log(line)
    local_line = str(line).strip().split(" ")
    int1 = int(local_line[1]) 
    int2 = int(local_line[2]) 
    log(str(int1 + int2))
    return int1 + int2

def ADD_FLOATS(line):
    log(line)
    local_line = str(line).strip()

def CONCAT(line):
    log(line)

def PUT_HEAP(value):
    log("Bit " + str(Nibbles) + " Putting to HEAP with value " + value)
    HEAP.put(value, Nibbles)

def LIST_HEAP():
    log("Listing Heap with Nibbles = " + str(Nibbles))
    i = 0
    while i < Nibbles:
        EVAL = HEAP.get(i)
        log("Bit " + i + " " + EVAL)
        i += 1


def HALT(line):
    log(line)
    exit()

def parser(fname):
    lnum = 0
    file = open(fname, "r")
    for line in file.readlines():
        # ACTUAL PARSING
        lnum + 1    
        # if ADD in line.strip() == True & (AND + " " + PUT + " " + HEAP in line.strip()) == True:
        #     log("Adding and PUTing to heap")
        #     l_int = ADD_INTEGERS(line)
        #     PUT_HEAP(line, l_int)
        # elif (ADD in line.strip()) == True:
        #     ADD_INTEGERS(line)



def TEST():
    i = 0
    while i < BIT_UB:
        PUT_HEAP( str(i) + " Test Value")
        i += 1
    log("Stopped putting values => LIST_HEAP()")
    LIST_HEAP()
TEST()