#!/usr/bin/env python
import sys
args = len(sys.argv)
arg1 = arg2 =  arg3 = arg4 = ''
if args>1:
    arg1 = sys.argv[1]
if args>2:
    arg2 = sys.argv[2]
if args>3:
    arg3 = sys.argv[3]
if args>4:
    arg4 = sys.argv[4]
print arg1,arg2,arg3,arg4

__metaclass__ = type
class Person:
    def setName(self,name):
        self.name = name

    def getName(self):
        return self.name

    def greet(self):
        print "Hello, world! I'm %s (%s)." %(self.name, self)

    
foo = Person()
boo = Person()
foo.setName("foo")
boo.setName("boo")

boo.greet()
foo.greet()
boo.name = "change boo.name"
boo.greet()

if __name__ == "main":
    pass
