#!/usr/bin/python
#coding=utf8
#filename:router-test_lj023.py
'''
'''
import urllib
import urllib2
import cookielib
import time
url1 = "http://192.168.10.14/"
url_login = url1 + "LoginCheck"
user_agent = "Mozilla/4.0 (compatible; MSIE 5.5; Windows NT)"
headers = {'User-Agent':user_agent}
values = {'Username':'admin', 'Password':'admin', 'checkEn':0, 'invalid':''}
datas = urllib.urlencode(values)

#print values['username'],values['password']
#print headers
#req = urllib2.Request(url, data, headers)
cookiejar = cookielib.MozillaCookieJar('/tmp/cookie_14router.txt')
cookieproc = urllib2.HTTPCookieProcessor(cookiejar)
opener = urllib2.build_opener(cookieproc)
req = urllib2.Request(url=url_login, data=datas, headers=headers)
try:
    response = opener.open(req)
except (urllib2.HTTPError, urllib2.URLError),e:
    print e

page = response.read()
if response.getcode() == 200:
    cookiejar.save(ignore_discard=True, ignore_expires=True)
    print time.asctime(),"Access<" + url_login + "> is OK"
    file_cookie = open('/tmp/cookie_14router.txt')
    for tmp in file_cookie:
        print tmp,
    urllib2.install_opener(opener)
    response2 = urllib2.urlopen(url1+'/index.asp')
    response3 = urllib2.urlopen(url1+"/advance.asp")
    response4 = urllib2.urlopen(url1+"/system_status.asp")
