#!/usr/bin/python
import httplib,urlparse

def httpExists(url):
  host,path = urlparse.urlsplit(url)[1:3]
#  print "test:> ",host,path
  if ":" in host:
    host,port = host.split(":", 1)
    try:
      port = int(port)
    except ValueError:
      print "invalid port number %r" % (port,)
      return False
  else:
    port = None

  try:
    connection = httplib.HTTPConnection(host,port=port)
    connection.request("HEAD", path)
    resp = connection.getresponse()
    if resp.status == 200:
      found = True
    elif resp.status == 301:
      found = httpExists(urlparse.urljoin(url,resp.getheader("location","")))
    elif resp.status == 302:
      found = httpExists(urlparse.urljoin(url,resp.getheader("location","")))
    else:
      print "Status %d %s : %s" % (resp.status, resp.reason, url)
      found = False
  except Exception,e:
    print e.__class__, e, url
    found = False
  return found

def _test():
  import httpExists
  import sys
  import httplib,urlparse

  url11 = urlparse.urlsplit(sys.argv[1])[0:1]
  url12 = urlparse.urlsplit(sys.argv[1])[1:2]
  url13 = urlparse.urlsplit(sys.argv[1])[2:3]
  print "test:> ",url11,url12,url13

  isOK = httpExists.httpExists(sys.argv[1])
  if isOK:
    print "isOK"
  else:
    print "isBAD"
if __name__ == "__main__":
  _test()

