#!/usr/bin/python

try:
    filename = raw_input("Enter file name:")
    fobj = open(filename, 'r')

    for eachline in fobj:
        print eachline,
        raise IOError

    fobj.close()
except IOError,e:
    print 'file open error:',e
