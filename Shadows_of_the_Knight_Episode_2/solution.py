import sys
import math

#
# Return a Matrix of booleans WxH
def BooleanMatrix(w,h):
#    m = [True * w] * h
    m = [[True for i in xrange(h)] for j in xrange(w)]
    return m

#
# Distance beetwen two points
def distance (p0,p1):
    x0,y0 = p0
    x1,y1 = p1

    return math.sqrt((x0-x1)*(x0-x1)+(y0-y1)*(y0-y1))

def centroid(m, w, h):
    k = 0
    x = 0
    y = 0
    for j in xrange(h):
        for i in xrange(w):
            if m[i][j]:
                x = x + i
                y = y + j
                k = k + 1
    p = (x//k, y//k)
    return p

def check_centroid(p,c,m,w,h):
    # Needs discard old visited point
    print >> sys.stderr, c, w, h
    x,y = c
    if c in p and m[x][y]:
        if x+1 <= w-1 and m[x+1][y] and not (x+1,y) in p:
            return (x+1,y)
        if x-1 >= 0 and m[x-1][y] and not (x-1,y) in p:
            return (x-1,y)
        if x+1 <= w-1 and y+1 <= h-1 and m[x+1][y+1] and not (x+1,y+1) in p:
            return (x+1,y+1)
        if x+1 <= w-1 and y-1 >= 0 and m[x+1][y-1] and not (x+1,y-1) in p:
            return (x+1,y-1)
        if y+1 <=h-1 and m[x][y+1] and not (x,y+1) in p:
            return (x,y+1)
        if y-1 >= 0 and m[x][y-1] and not (x,y-1) in p:
            return (x,y-1)
        if x-1 >= 0 and y + 1 <= h-1 and m[x-1][y+1] and not (x-1,y+1) in p:
            return (x-1,y+1)
        if x-1 >= 0 and y - 1 >= 0 and m[x-1][y-1] and not (x-1,y-1) in p:
            return (x-1,y-1)
    return c
#
# Discard Points
def discard_points (p0, p1, m, w, h, d):
    if cmp_distance(d) == 1:
        for j in xrange(h):
            for i in xrange(w):
                if distance((i,j),p1) > distance((i,j),p0):
                    m[i][j] = False
        return

    if cmp_distance(d) == -1:
        for j in xrange(h):
            for i in xrange(w):
                if distance((i,j),p1) < distance((i,j),p0):
                    m[i][j] = False
        return

    if cmp_distance(d) == 0:
        for j in xrange(h):
            for i in xrange(w):
                if distance((i,j),p1) != distance((i,j),p0):
                    m[i][j] = False
        return
    return


#
# Change String temperature for number: 1:Warmer, -1:Colder, 0:Same
def cmp_distance(d):
    if d == 'WARMER':
        return 1
    if d == 'COLDER':
        return -1
    # SAME
    return 0


# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

# w: width of the building.
# h: height of the building.
w, h = [int(i) for i in raw_input().split()]
n = int(raw_input())  # maximum number of turns before game over.
x0, y0 = [int(i) for i in raw_input().split()]

M = BooleanMatrix(w,h)
P = []
# game loop
while True:
    bomb_dir = raw_input()  # Current distance to the bomb compared to previous distance (COLDER, WARMER, SAME or UNKNOWN)
    print >> sys.stderr,bomb_dir
    if bomb_dir == 'UNKNOWN':
        x1 = w/2
        y1 = h/2
#        x1, y1  = centroid(M,w,h)
    else:
        discard_points((x0,y0),(x1,y1),M,w,h,bomb_dir)
        x0 = x1
        y0 = y1
        x1, y1 = check_centroid(P,centroid(M,w,h),M,w,h)

    # Write an action using print
    # To debug: print >> sys.stderr, "Debug messages..."
    P.append((x1,y1))
    print >> sys.stderr, P
    print "%d %d" % (x1,y1)

