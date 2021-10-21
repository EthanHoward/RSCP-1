import sys
import os
from AVASPyLibs import AVASLang

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
        AVASLang.parser(sys.argv[1])
    else:
        log("AVAS Parser v" + version)
        log("Args: " + str(sys.argv))


if __name__ == "__main__":
    run()



