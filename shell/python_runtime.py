#!/usr/bin/python
from time import time
def test():
    t = time()
    lista=[1,2,3,4,5,6,7,8,9,13,34,53,42,44]
    listb=[2,4,6,9,23]
    intersection=[]
    for i in range (1000000):
        for a in lista:
            for b in listb:
                if a == b:
                    intersection.append(a)

    print "list in func(test), total run time:", time()-t

def test_set():
    t = time()
    lista=[1,2,3,4,5,6,7,8,9,13,34,53,42,44]
    listb=[2,4,6,9,23]
    intersection=[]
    for i in range(1000000):
        intersection.append(list(set(lista)&set(listb)))
    print "set in func(test_set), total run time:", time()-t

t = time()
lista=[1,2,3,4,5,6,7,8,9,13,34,53,42,44]
listb=[2,4,6,9,23]
intersection=[]
for i in range (1000000):
    for a in lista:
        for b in listb:
            if a == b:
                intersection.append(a)

print "list not in func, total run time:", time()-t
##runtime(db6sda8_python2.6.6: 19.9267392159)

t = time()
lista=[1,2,3,4,5,6,7,8,9,13,34,53,42,44]
listb=[2,4,6,9,23]
intersection=[]
for i in range(1000000):
    intersection.append(list(set(lista)&set(listb)))
print "set not in func, total run time:", time()-t
#runtime(db6sda8_python2.6.6: 5.93210506439)

test()
###runtime(db6sda8_python2.6.6: 10.7789461613)
test_set()
###runtime(db6sda8_python2.6.6: 7.41557717323)
