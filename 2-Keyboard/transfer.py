import string
ori = ".pyfgcrl/=?+aoeuidhtns_qjkxbmwvz[]{}"
dest = "ertyuiop[]{}asdfghjkl;\"xcvbnm,./-=_+"
test = r"macb() ? lpcbyu(&gbcq/_\021\%ocq\012\0_=w(gbcq)/_dak._=}_ugb_[0q60)s+"
str_trantab = string.maketrans(ori, dest)
print (test.translate(str_trantab))