#-*- coding:utf-8 -*-


def to26(s):
    ret = 0
    for i in range(len(s)):
        ret *= 26
        ret += ord(s[i])-ord('A') + 1
    return ret

print to26("COOLSHELL") / to26("SHELL") # 85165

def from26(v):
    ret = ""
    while v != 0:
        ret += str(chr(26+ord('A')-1) if v%26==0 else chr(v%26+ord('A')-1))
        if (v%26 == 0):
            v -= 1
        v /= 26
    return ''.join(reversed(list(ret)))

print from26(85165) # DUYO