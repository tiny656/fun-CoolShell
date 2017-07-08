#-*- coding:utf-8 -*-
import hashlib,sys,os

result = "e48d316ed573d3273931e19f9ac9f9e6039a4242"
with open("9-queens.txt") as f:
    queens_9_res =  f.readline().split(',')
    for res in queens_9_res:
        data = "zWp8LGn01wxJ7" + str(res) + "\n"
        if hashlib.sha1(data).hexdigest() == result:
            print res

# answers: 953172864