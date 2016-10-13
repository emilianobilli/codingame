import sys
import math

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.


def count(g, i):
    if g[i] == []:
        return 1
    
    best = 0
    for next_node in g[i]:
        best = max(best, 1 + count(g,next_node))
    
    return best

G = {}

n = int(raw_input())  # the number of relationships of influence
for i in xrange(n):
    # x: a relationship of influence between two people (x influences y)
    x, y = [int(j) for j in raw_input().split()]
    if not x in G.keys():
        G[x] = []
    if not y in G.keys():
        G[y] = []
    G[x].append(y)
# Write an action using print
# To debug: print >> sys.stderr, "Debug messages..."

b = 0
for j in G.keys():
    b = max(b,count(G,j))

# The number of people involved in the longest succession of influences
print "%d" % b
