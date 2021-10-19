import os
import subprocess

i = 1

def httpdev():
    os.system("simple.http.bat")
    

def node():
    os.system("nodedevenv.py")

#def progmgr(progname):
#    os.system("start cmd /c py " + progname.replace(".exe", ".py") +)

def timer(time_int):
    n = 0
    time_int = int(time_int)
    while n <= time_int:
        b = "00:" + time_int
        print (b, end="\r")
        time.sleep(1)
        n = n + 1

def VSCode():
    os.system("start VSCode\Code.exe")
    vss = subprocess.check_output("tasklist", shell=True)
    if "Code.exe" in vss:
        print("Code.exe started successfully")
    cmdrun()

def peazip():
    os.system("start pzip\peazip.exe")
    pzs = subprocess.check_output("tasklist", shell=True)
    if "peazip.exe" in pzs:
        print("Peazip.exe started successfully")
    cmdrun()

def bins():
    print("V - VSCode P - Peazip")
    while True:
        proginp = input("> ")
        if proginp == "V":
            VSCode()
            cmdrun()
        elif proginp == "v":
            VSCode()
            cmdrun()
        elif proginp == "P":
            peazip()
            cmdrun()
        elif proginp == "p":
            peazip()
            cmdrun()
safemode = True
def cmdrun():
    ### startup ###
    #if safemode == True:
        #print("bruh")
        #time.sleep(5)
        #safeinp = input(">")
        #if safeinp == "unlock":
        #    safemode = False 
        #    cmdrun()
        #else:
        #    print("Exiting in " + timerr("05"))
        #    
        #    exit()    
    os.system("color 01")
    while True:  
        rootdir = os.getlogin() + "@terminal:~$ "
        command = input(rootdir)
        if command == "httpdev":
            httpdev()
        if command == "bins":
            bins()
        if command == "node":
            node()
        if command != str:
            os.system(command)
        else:
            cmdrun()
    
cmdrun()
