import sys
import math

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

# n: the total number of nodes in the level, including the gateways
# l: the number of links
# e: the number of exit gateways
class Q(object):
    def __init__(self):
        self.queue = []

    def empty(self):
        if len(self.queue) == 0:
            return True
        return False
    
    def enqueue(self,v):
        self.queue.append(v)

    def dequeue(self):
        r = None
        if len(self.queue) > 0:
            r = self.queue[0]
            self.queue = self.queue[1:]
        return r

VISITED    = 1
NOTVISITED = 0

def iscutnode(graph, node, exit):
    for i in graph[node]:
        if i in exit:
            return True
    return False
    

def bfs (graph, node, exit):
    state    = {}
    distance = {}
    cutnode  = {}
       
    for v in graph.keys():
        state[v]    = NOTVISITED
        distance[v] = -1
        cutnode[v]  =  0
    
    state[node]    = VISITED
    distance[node] = 0
    q = Q()
    q.enqueue(node)
    while not q.empty():
        v = q.dequeue()
        for k in graph[v]:
            if state[k] == NOTVISITED and k not in exit:
                state[k]    = VISITED
                distance[k] = distance[v] + 1
                if iscutnode(graph,k,exit):
                    cutnode[k] = cutnode[v] + 1
                q.enqueue(k)

    return distance, cutnode
    
NET  = {}   
EXIT = []

TWO_EXIT_NODE = []

# Se deben identificar los vertices que tienen adyacencia son dos o mas salidas

def get_node_to_cut(n,e,a,ten):
    d,c = bfs(n,a,e)
    # Este BFS retorna la distancia y la cantidad de cut nodes
    # que tiene en el camino. Se deberia recortar aquel nodo
    # que tiene mas cut nodes en el camino. 
    node  = None
    first = True
    for t in ten:
        if first:
            first = False
            mi    = d[t] - c[t]
            node  = t
        else:
            if d[t]-c[t] < mi:
                mi = d[t]-c[t]
                node = t
    return node
        
def cut_exit(n,e,a,ten):
    # Nodos adyacentes a la posicion del agente
    nodes = n[a]
    # Busca si hay una salida
    # Adyacente a la posicion del Agente
    for ni in nodes:
        if ni in e:
            ei = e.index(ni)
            n[a].remove(ni)
            n[ni].remove(a)
            return a, ni
    
    # Busca si hay un nodo salto a salidas
    # Adyacente a la posicion del agente
    p = get_node_to_cut(n,e,a,ten)        
    if p is not None:
        nodes = n[p]
        for ni in nodes:
            if ni in e:
                ei = e.index(ni)
                n[p].remove(ni)
                n[ni].remove(p)
                ten.remove(p)
                return p, ni
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


# Identifica los nodos que tienen dos o mas salidas
for i in xrange(e):
    ei = int(raw_input())  # the index of a gateway node
    EXIT.append(ei)
    
for k in NET.keys():
    count = 0
    for e in EXIT:
        if e in NET[k]:
            count = count +1
    if count >= 2:
        TWO_EXIT_NODE.append(k)


# game loop
while True:
    si  = int(raw_input())  # The index of the node on which the Skynet agent is positioned this turn
    a,b = cut_exit(NET,EXIT,si,TWO_EXIT_NODE) 
    # Write an action using print
    # To debug: print >> sys.stderr, "Debug messages..."

    
    # Example: 0 1 are the indices of the nodes you wish to sever the link between
    print "%d %d" % (a,b)
