import sys
import math

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

MAP = { '0': [],
        '1': [('u','d'), ('l','d'),('r','d')],
        '2': [('r','l'), ('l','r')],
        '3': [('u','d')],
        '4': [('u','l'), ('r','d')],
        '5': [('u','r'), ('l','d')],
        '6': [('r','l'), ('l','r')],
        '7': [('u','d'), ('r','d')],
        '8': [('l','d'), ('r','d')],
        '9': [('u','d'), ('l','d')],
        '10': [('u','l')],
        '11': [('u','r')],
        '12': [('r','d')],
        '13': [('l','d')] }
        
# w: number of columns.
# h: number of rows.
m = []
w, h = [int(i) for i in raw_input().split()]
for i in xrange(h):
    line = raw_input()  # represents a line in the grid and contains W integers. Each integer represents one room of a given type.
    m.append(line.split(' '))
ex = int(raw_input())  # the coordinate along the X axis of the exit (not useful for this first mission, but must be read).


f = 'u'
# game loop
while True:
    xi, yi, pos = raw_input().split()
    xi = int(xi)
    yi = int(yi)
    t = m[yi][xi]

    p = MAP[t]
    if (f,'d') in p:
        y = yi + 1
        x = xi
        f = 'u' 
    elif (f,'r') in p:
        y = yi
        x = x + 1
        f = 'l'
    elif (f,'l') in p:
        y = yi
        x = xi - 1
        f = 'r'
    
    # Write an action using print
    # To debug: print >> sys.stderr, "Debug messages..."


    # One line containing the X Y coordinates of the room in which you believe Indy will be on the next turn.
    print "%d %d" % (x,y)
