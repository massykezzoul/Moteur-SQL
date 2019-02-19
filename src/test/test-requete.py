#!/usr/bin/python3

import sys,os,re

with open("req.sql") as file:
    for line in file :
        resultat = re.search("^(.+)\n$",line)
        os.system("../sql "+"\""+resultat.group(1)+"\"")