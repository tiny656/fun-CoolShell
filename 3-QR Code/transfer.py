import string
dest = string.ascii_lowercase
ori = "qvwdgazxubqfsnrhocitlkeymj"
test = "Wxgcg txgcg ui p ixgff, txgcg ui p epm. I gyhgwt mrl lig txg ixgff wrsspnd tr irfkg txui hcrvfgs, nre, hfgpig tcm liunz txg crt13 ra \"ixgff\" tr gntgc ngyt fgkgf."
str_trantab = string.maketrans(ori, dest)
print (test.translate(str_trantab))

'''
Where there is p shell, there is p wpy. I expect you use the shell commpnd to solve this problem, now, plepse try using the rot13 of "shell" to enter next level.
'''

def rot13(s,offSet=13):
    d={chr(i+c) : chr((i+offSet) % 26 + c) for i in range(26) for c in (65,97)}
    return ''.join([d.get(c, c) for c in s])

print rot13("shell")
# furyy