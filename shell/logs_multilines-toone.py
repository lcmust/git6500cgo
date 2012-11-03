#!/usr/bin/python
#coding=utf8
#filename:logs_multilines-toone.py
#date: 20121025-1000
'''处理日志文件：将分散为多行的同一条日志记录，合并为一行（长行记录），主要是处理Windows系统的日志（另存为txt文件后，一条记录分散到多行中）
sys.argv[1]  待处理的日志文件名
sys.argv[2]  处理完成后将结果保存到的目标文件

$ time /home/love/chengl6500/shell/logs_multilines-toone.py ./21-security_utf8.txt /tmp/new1
start at:1351436551.15
over at:1351436575.77
use time: 24 seconds
process over: match= 276209  diff= 2624986 All= 2901195

real	0m24.660s
user	0m24.026s
sys	0m0.596s

将decode() encode()去除后再试：
#fileLine1 = fd1.readline().decode('gbk')
#fileLine1 = fd1.readline().decode('utf8')
fileLine1 = fd1.readline()
......
        #fileLine2 = fd1.readline().decode('gbk')
        #fileLine2 = fd1.readline().decode('utf8')
        fileLine2 = fd1.readline()
        if (fileLine2 == ""):
            #fd2.write(writeData.encode('utf8') + '\n')
            fd2.write(writeData + '\n')

速度快了近1倍
$ time /home/love/chengl6500/shell/logs_multilines-toone.py ./21-security_utf8.txt /tmp/new2
start at:1351438016.48
over at:1351438028.29
use time: 12 seconds
process over: match= 276209  diff= 2624986 All= 2901195

real	0m11.844s
user	0m10.881s
sys	0m0.460s

'''
import re
import sys
import os
import time
#time_start = time.asctime()
time_start = time.time()

if (len(sys.argv) > 1):
    if (os.path.exists(sys.argv[1])):
        fd1 = open(sys.argv[1], 'r')
    else:
        print "can't open the %s" % sys.argv[1]
else:
    print "input arg1 as the source file, so exit!"
    exit(-1)

if (len(sys.argv) > 2):
    fd2 = open(sys.argv[2], 'w')
    if (not fd2):
        print "can't open the %s" % sys.argv[2]
else:
    print "input arg2 as the target file!"
    exit(-1)

countMatch = 0
countDiff = 0
wirteData = ""
reDate = re.compile(r'^\d{4}-\d{1,2}-\d{1,2}\s+\d{1,2}:\d{1,2}:\d{1,2}.*')
#fileLine1 = fd1.readline().decode('gbk')
#fileLine1 = fd1.readline().decode('utf8')
fileLine1 = fd1.readline()
if (fileLine1 == ""):
    exit(2)
if (reDate.match(fileLine1)):
    countMatch += 1
    writeData = fileLine1.strip()
    while True:
        #fileLine2 = fd1.readline().decode('gbk')
        #fileLine2 = fd1.readline().decode('utf8')
        fileLine2 = fd1.readline()
        if (fileLine2 == ""):
            #fd2.write(writeData.encode('utf8') + '\n')
            fd2.write(writeData + '\n')
            break
        if (not reDate.match(fileLine2)):
            writeData += fileLine2.strip()
            countDiff += 1
            continue
        else:
            #fd2.write(writeData.encode('utf8') + '\n')
            fd2.write(writeData + '\n')
            writeData = fileLine2.strip()
            countMatch += 1
fd1.close()
fd2.close()
#time_end = time.asctime()
time_end = time.time()
print "start at:" + str(time_start)
print "over at:" + str(time_end)
print "use time: %d seconds" % (int(time_end) - int(time_start))
print "process over: match=", countMatch, " diff=", countDiff, "All=", countMatch+countDiff
