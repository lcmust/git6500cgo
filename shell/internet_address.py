#!/usr/bin/python
#codeing=UTF-8
import urllib
import urllib2
import re
import sys
import time
#print sys.argv
#for tmp in sys.argv:
#    print tmp
#print len(sys.argv)
if len(sys.argv) > 1:
    url1 = sys.argv[1]
else:
    url1 = "http://whereismyip.com"

try:
    req = urllib2.urlopen(url1)
except urllib2.URLError,e:
    print e
    sys.exit(-1)
page = req.read()
#re_ip = re.compile("\d{1,3}.\d{1,3}.\d{1,3}.\d{1,3}")
re_ip = re.compile("(\d{1,3}.){3}.\d{1,3}")
result = re_ip.search(page)
print "(" + time.asctime() +  ") Your internet address: " + result.group(0)
