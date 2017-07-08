#-*- coding:utf-8 -*-

import urllib,re
val = 2014
website = r'http://fun.coolshell.cn/n/'

with open("file-link.txt", 'w') as f:
    while True:
        try:
            val = urllib.urlopen(website+str(val)).read()
            f.write(val + '\n')
            print val
            if not re.match(r'[0-9]+', val): break
        except: pass