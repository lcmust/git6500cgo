#!/usr/bin/python
#coding=utf8
#filename:logs_ip-account.py
#date: 20121025-1300
'''
fd1 是源文件（待处理目标文件）第1个参数为空时默认为/home/love/test44.txt
fd2 是记录每个IP地址的次数的文件，第2个参数为统计结果的保存文件

TEST:
$ time /home/love/chengl6500/shell/logs_ip-account.py ./21-security_utf8_2.txt /tmp/new
start at:1351533275.09
over at:1351533290.1
use time:15 seconds
192.168.1.22 16590
192.168.1.21 17578
192.168.0.21 16464
125.70.76.189 14
118.112.57.242 4
221.237.208.210 3
127.0.0.1 6730
total match:57383

real    0m15.039s
user    0m14.933s
sys     0m0.088s

'''
import re
import os
import sys
import time
resultDict = {}

#参数1作为源文件，必须提供
if len(sys.argv) > 1:
    file_in = sys.argv[1]
    if (os.path.exists(file_in)):
        try:
            fd1 = open(file_in, 'r')
        except IOError, e:
            print e
    else:
        print "source file(%s) is not exists, so exit!" % sys.argv[1]
        exit(-1)
else:
    print "please input the source file, so exit!"
    exit(-1)

#参数2作为统计历史结果保存文件，如果提供此文件，则先从此文件读入历史统计数据
if len(sys.argv) > 2:
    file2_in = sys.argv[2]
    if (os.path.exists(file2_in)):
        fd2 = open(file2_in, 'r+')
        while True:
            input_pre = fd2.readline()
            if (input_pre == ""):
                fd2.seek(0)
                break
            count_pre = input_pre.split()
            resultDict[count_pre[0]] = int(count_pre[1])
            print count_pre[0], count_pre[1]
    else:
        fd2 = open(file2_in, 'w')
else:
    print "please input the target file, so exit!"
    exit(-1)

countMatch = 0
time_start = time.time()
reIPv4 = re.compile('(\d{1,3}\.){3}\d{1,3}')

'''
while True:
    fileLine = fd1.readline()
    if (fileLine == ""):
        break
    reResult = reIPv4.search(fileLine)
    if (reResult):
        #countMatch += 1
        if reResult.group() in resultDict:
            resultDict[reResult.group()] += 1
        else:
            resultDict[reResult.group()] = 1
        #print reResult.group()
        #print fileLine
'''
#process()与上面的代码块的执行速度完全相同
def process(fd1):
    while True:
        fileLine = fd1.readline()
        if not fileLine:
            break
        reResult = reIPv4.search(fileLine)
        if (reResult):
            #countMatch += 1
            if reResult.group() in resultDict:
                resultDict[reResult.group()] += 1
            else:
                resultDict[reResult.group()] = 1
process(fd1)
fd1.close()
time_end = time.time()
print "start at:" + str(time_start)
print "over at:" + str(time_end)
print "use time:%d seconds" % (int(time_end) - int(time_start))
for tmp in resultDict:
    countMatch += resultDict[tmp]
    print tmp, resultDict[tmp]
    fd2.write(str(tmp) + " " + str(resultDict[tmp]) + "\n")
fd2.close()
print "total match:" + str(countMatch)
