import sys
import math

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

mayan_num = []

def get_mayan_symbols(m,l):
    symbols = [ '' for i in xrange(20) ]
    for s in m:
        i = 0
        for j in xrange(20):
            symbols[j] = symbols[j] + s[i*l:(i+1)*l]
            i = i + 1
    return symbols

def to_mayan_number(r,s,l):
    lst = []

    for n in r:
        i   = 0
        sym = s[n]
        for j in xrange(l):
            lst.append(sym[i*l:(i+1)*l])
            i = i + 1

    return lst

def __get_number(s,symbols):
    for j in xrange(20):
        if s == symbols[j]:
            return j
    print >> sys.stderr, s
    return -1

def strcat (l):
    ret = ''
    for i in l:
        ret = ret + i
    return ret
            
    
def get_number(sz,n,h,s):
    nlst = []
    nsz  = sz / h

    for i in xrange(nsz):
        nlst.append(__get_number(strcat(n[i*h:(i+1)*h]),s))
    return nlst

def get_base10 (n):
    ret = 0
    i   = len(n) - 1
    for num in n:
        ret = ret + ( num * math.pow(20,i))
        i   = i -1
    return int(ret)

def to_base20(n):
    l = []
    while n >= 20:
        l.append(n % 20)
        n = n // 20
    l.append(n)
    return l[::-1]

l, h = [int(i) for i in raw_input().split()]

for i in xrange(h):
    numeral = raw_input()
    mayan_num.append(numeral)

symbols = get_mayan_symbols(mayan_num,l)

n1 = []    
n2 = []    
s1 = int(raw_input())
for i in xrange(s1):
    num_1line = raw_input()
    n1.append(num_1line)

s2 = int(raw_input())
for i in xrange(s2):
    num_2line = raw_input()
    n2.append(num_2line)
    
num1 =  get_number(s1,n1,h,symbols)
num2 =  get_number(s2,n2,h,symbols)
operation = raw_input()

n = get_base10(num1)

if operation == '+':
    n = n + get_base10(num2)
elif operation == '-':
    n = n - get_base10(num2)
elif operation == '*':
    n = n * get_base10(num2)
elif operation == '/':
    n = n / get_base10(num2)
    
r = to_base20(n)
mayan_result = to_mayan_number(r,symbols,l)
# Write an action using print
# To debug: print >> sys.stderr, "Debug messages..."
for x in mayan_result:
    print x

