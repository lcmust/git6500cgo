#!/usr/bin/python
#coding=utf8
#filename:logs_multilines-toone2.py
#date: 20121025-1000
'''处理日志文件：将分散为多行的同一条日志记录，合并为一行（长行记录），主要是处理Windows系统的日志（另存为txt文件后，一条记录分散到多行中）
sys.argv[1]  待处理的日志文件名
sys.argv[2]  处理完成后将结果保存到的目标文件

$ time /home/love/chengl6500/shell/logs_multilines-toone2.py ./21-security_utf8.txt /tmp/new2
start at:1351436747.11
over at:1351436767.23
use time:20 seconds
process over: match= 276209  diff= 2624986 All= 2901195

real	0m20.156s
user	0m19.501s
sys	0m0.624s

将decode() encode()去除后再试：
    #fileLine1 = fd1.readline().decode('gbk')
    #for fileLine1 in fd1:
    for fileLine2 in fd1:
        #fileLine2 = fileLine1.decode('utf8')
        if (reDate.match(fileLine2)):
            countMatch += 1
            if (writeData):
                #fd2.write(writeData.encode('utf8') + '\n')
                fd2.write(writeData + '\n')
速度快了近2倍
$ time /home/love/chengl6500/shell/logs_multilines-toone2.py ./21-security_utf8.txt /tmp/new3
start at:1351438134.77
over at:1351438141.48
use time:7 seconds
process over: match= 276209  diff= 2624986 All= 2901195

real	0m6.739s
user	0m6.236s
sys	0m0.496s

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
        print "can't open the %s", sys.argv[1]
else:
    print "no source file or source is not exists, so exit!"
    exit(-1)

if (len(sys.argv) > 2):
    fd2 = open(sys.argv[2], 'w')
    if (not fd2):
        print "can't open the %s", sys.argv[2]
else:
    print "input arg2 as the target file!"
    exit(-1)

countMatch = 0
countDiff = 0

reDate = re.compile(r'\d{4}-\d{1,2}-\d{1,2}\s+\d{1,2}:\d{1,2}:\d{1,2}\s+\w+')
def process(fd1, fd2):
    global countMatch
    global countDiff
    writeData = ""
    a1 = 0
    #fileLine1 = fd1.readline().decode('gbk')
    #for fileLine1 in fd1:
    for fileLine2 in fd1:
        #fileLine2 = fileLine1.decode('utf8')
        if (reDate.search(fileLine2)):
            countMatch += 1
            if (writeData):
                #fd2.write(writeData.encode('utf8') + '\n')
                fd2.write(writeData + '\n')
                writeData = ""
            writeData = fileLine2.strip()
        else:
            writeData += fileLine2.strip()
            countDiff += 1
    else:
        if (writeData):
            fd2.write(writeData + '\n')
            #fd2.write(writeData.encode('utf8') + '\n')
            writeData = ""

process(fd1, fd2)
fd1.close()
fd2.close()
#time_end = time.asctime()
time_end = time.time()
print "start at:" + str(time_start)
print "over at:" + str(time_end)
print "use time:%d seconds" % (int(time_end) - int(time_start))
print "process over: match=", countMatch, " diff=", countDiff, "All=", countMatch+countDiff
