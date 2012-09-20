#!/usr/bin/python
#coding=utf8
import urllib
import urllib2
import base64
import time
url = "http://192.168.1.1/"
url = "http://192.168.1.1/index.asp"
user_agent = "Mozilla/4.0 (compatible; MSIE 5.5; Windows NT)"
username = 'admin'
password = '991230'
#headers = {'User-Agent':user_agent}
#headers['Authorization'] = base64.b64encode(username+":"+password)
headers = {'User-Agent':user_agent, \
           'Authorization': \
               "Basic "+base64.b64encode(username+":"+password)}
#print values['username'],values['password']
#print headers
#req = urllib2.Request(url, data, headers)
req = urllib2.Request(url=url, headers=headers)
try:
    response = urllib2.urlopen(req)
except (urllib2.HTTPError, urllib2.URLError),e:
    print e

page = response.read()
if response.getcode() == 200:
    print time.asctime(),"Access<" + url + "> is OK"
