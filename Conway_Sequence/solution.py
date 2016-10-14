import sys
import math

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

def get_list (prev, times, actual):
    ret = []

    if times == actual:
        return prev

    ch = prev[0]
    i  = 1
    
    for c in prev[1:]:
        if c == ch:
            i = i + 1
        else:
            ret.append(i)
            ret.append(ch)
            ch = c
            i  = 1
    
    ret.append(i)
    ret.append(ch)        
    
    return get_list(ret, times, actual+1)

r = int(raw_input())
l = int(raw_input())

# Write an action using print
# To debug: print >> sys.stderr, "Debug messages..."
cs = get_list([r],l,1)

answer = ''
for c in cs:
    answer = answer + '%d ' % c

print answer[0:len(answer)-1]

