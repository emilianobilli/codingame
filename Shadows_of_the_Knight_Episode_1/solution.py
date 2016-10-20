import sys
import math

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

# w: width of the building.
# h: height of the building.
w, h = [int(i) for i in raw_input().split()]
n = int(raw_input())  # maximum number of turns before game over.
x0, y0 = [int(i) for i in raw_input().split()]
xMin = 0
xMax = w-1
yMin = 0
yMax = h-1
# game loop
while True:
    bomb_dir = raw_input()  # the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)

    if bomb_dir == 'U':
        xMin = x0
        xMax = x0
        yMax = y0-1
    elif bomb_dir == 'D':
        xMin = x0
        xMax = x0
        yMin = y0+1
    elif bomb_dir == 'R':
        yMin = y0
        yMax = y0
        xMin = x0+1
    elif bomb_dir == 'L':
        yMin = y0
        yMax = y0
        xMax = x0-1
    elif bomb_dir == 'UL':
        xMax = x0-1
        yMax = y0-1
    elif bomb_dir == 'UR':
        yMax = y0-1
        xMin = x0+1
    elif bomb_dir == 'DL':
        yMin = y0+1
        xMax = x0-1
    elif bomb_dir == 'DR':
        yMin = y0+1
        xMin = x0+1
    
    print >> sys.stderr, bomb_dir, xMin, xMax, yMin, yMax
    x0 = (xMax + xMin) // 2
    y0 = (yMax + yMin) // 2
    # Write an action using print
    # To debug: print >> sys.stderr, "Debug messages..."


    # the location of the next window Batman should jump to.
    print "%d %d" % (x0, y0)
