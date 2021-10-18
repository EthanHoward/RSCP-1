import sys
import os

version = "0.0.1"

split = sys.argv

def log(log):
    print("/| LOG } " + log)
def parselog(log, ln):
    print("" + str(ln) +"| PARSE } " + log)
def errlog(log):
    print("E| ERR | " + log)

def run():
    if ".avas" in sys.argv[1]:
        log("Avas file supplied: " + sys.argv[1])
        parser(sys.argv[1])
    else:
        log("AVAS Parser v" + version)
        log("Args: " + str(sys.argv))

def parser(fname):
    file = open(fname, "r")
    ln = 0
    for line in file.readlines():
        if "@AVASType : script" in line.strip():
            errlog("Script type is not currently supported in the parser")
            exit()
        ln += 1
        parselog(line.strip(), ln)

if __name__ == "__main__":
    run()



