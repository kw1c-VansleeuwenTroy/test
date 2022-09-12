from __future__ import print_function
from sigmatek.lasal import batch, classes
import tempfile
import sys
import re
import os
import glob
sys.path.insert(0, os.path.dirname(os.path.realpath(__file__)))

def GetLastLine(file):
    with open(file) as file:
        for line in file:
            pass
        return line

os.chdir(os.path.dirname(os.path.realpath(__file__)))
NOTFOUND = -1
CWD = os.getcwd()
logFile = tempfile.gettempdir() + "\Lasal2.log"
processIDRegex = re.compile("P:[0-9]* ")
taskIDRegex = re.compile("T:[0-9]* ")
lastLine = GetLastLine(logFile)
processID = processIDRegex.search(lastLine).group()
# relative path from script to th project .lcp
projectPaths = ["Copy Pump.lcp"]

def ShowLogs(file=sys.stdout):
    taskID = taskIDRegex.search(lastLine).group()
    with open(logFile) as log:
        for idx, line in enumerate(log):
            lineProcessIDSearch = processIDRegex.search(line)
            lineTaskIDSearch = taskIDRegex.search(line)
            if(lineProcessIDSearch is None or lineTaskIDSearch is None):
                continue
            lineProcessID = lineProcessIDSearch.group()
            lineTaskID = lineTaskIDSearch.group()
            errorReportingCondition = line.find("(ERROR) Compiler") != NOTFOUND
            errorReportingCondition |= line.find("(WARN) Compiler") != NOTFOUND
            errorReportingCondition &= lineProcessID == processID
            errorReportingCondition &= lineTaskID == taskID
            if errorReportingCondition:
                toDelete = lineProcessID + lineTaskID
                logEntry = line.replace(toDelete, "", 1)
                print(logEntry, file=file)

def compile(projectPaths=[""], file=sys.stdout):
    for projectPath in projectPaths:
        projectName = projectPath.replace('.lcp', '') 
        print("start compiling " + projectName, file=file)
        if batch.Compile(batch.LoadProject(os.path.join(CWD, projectPath)), False) == True:
            ShowLogs(file)
            print("done compiling {}: success".format(projectName), file=file)
        else:
            ShowLogs(file)
            print("done compiling {}: failed".format(projectName), file=file)
    

if __name__ == '__main__':
    if os.path.exists('log1.log'):
        os.remove("log1.log")
        
    os.rename("log.log","log1.log")

    with open('log.log','w+') as out:
        compile(projectPaths, out)


