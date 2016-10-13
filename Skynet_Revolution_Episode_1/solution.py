import sys
import math

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

# n: the total number of nodes in the level, including the gateways
# l: the number of links
# e: the number of exit gateways
NET  = {}
EXIT = []

def cut_exit(n,e,a):
    nodes = n[a]
    for ni in nodes:
        try:
            ei = e.index(ni)
        except:
            ei = -1
        if ei != -1:
            n[a].remove(ni)
            n[ni].remove(a)
            return a, ni
    # Cut aleatory exit
    for ei in e:
        if n[ei] != []:
            x = n[ei][0]
            n[ei].remove(x)
            n[x].remove(ei)
            return ei,x
            

n, l, e = [int(i) for i in raw_input().split()]
for i in xrange(l):
    # n1: N1 and N2 defines a link between these nodes
    n1, n2 = [int(j) for j in raw_input().split()]
    if not n1 in NET.keys():
        NET[n1] = []
    NET[n1].append(n2)
    if not n2 in NET.keys():
        NET[n2] = []
    NET[n2].append(n1)


    
for i in xrange(e):
    ei = int(raw_input())  # the index of a gateway node
    EXIT.append(ei)


# game loop
while True:
    si  = int(raw_input())  # The index of the node on which the Skynet agent is positioned this turn
    a,b = cut_exit(NET,EXIT,si) 
    # Write an action using print
    # To debug: print >> sys.stderr, "Debug messages..."


    # Example: 0 1 are the indices of the nodes you wish to sever the link between
    print "%d %d" % (a,b)
