from __future__ import print_function
from operator import contains
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
        project = batch.LoadProject(os.path.join(CWD, projectPath))
        if batch.Compile(project, False) == True:
            ShowLogs(file)
            print("done compiling {}: success".format(projectName), file=file)
            
        else:
            ShowLogs(file)
            print("done compiling {}: failed".format(projectName), file=file)

def GetProjectFiles(startDir):
    fileNames = []
    for _, dirs, files in os.walk(startDir):
        for dir in dirs:
            if not ".git" in dir:
                cDir = startDir + '\\' + dir
                # print(startDir + '\\' + dir)
                if os.path.isdir(cDir):
                    fileNames += GetProjectFiles(cDir)
                for fileName in glob.iglob(cDir + "\*.lcp"):
                    fileNames += [fileName]
        for file in files:
            if ".lcp" in file:
                print(file)


    return fileNames

if __name__ == '__main__':
    if os.path.exists('log1.log'):
        os.remove("log1.log")
    if os.path.exists('log.log'):
        os.rename("log.log","log1.log")

    with open('log.log','w+') as out:
        projects = GetProjectFiles(os.getcwd())
        print(projects, file=out)
        compile(projects, out)


