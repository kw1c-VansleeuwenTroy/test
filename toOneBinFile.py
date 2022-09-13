import os
from fnmatch import fnmatch

root = 'C:\\Users\\troyvs\\Desktop\\test\\Copy pump'
pattern = "*.lob"

with open("C:\\Users\\troyvs\\Desktop\\test\\Copy pump\\PROJECT.LOB", "w") as main:
    for path, subdirs, files in os.walk(root):
        for name in files:
            if fnmatch(name, pattern):
                with open(os.path.join(path, name),"r+b") as f:
                    main.writelines(f.readlines())