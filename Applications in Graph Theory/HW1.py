# --------------------------------------
# Zack Fravel
# 010646947
# Homework 1
# CSCE 5014 Applications of Graph Theory
# --------------------------------------
# HW1.py
#
# Read in multiple graphs and calculate
# their girth and diameter.
# --------------------------------------

import networkx as nx
import matplotlib.pyplot as plt

# Read in undirected graphs from .txt files using nx.read_edgelist function
G1 = nx.read_edgelist("graph1.txt")
G2 = nx.read_edgelist("graph2.txt")
G3 = nx.read_edgelist("graph3.txt")
G4 = nx.read_edgelist("graph4.txt")

# nx.draw(G2, with_labels=True)
# plt.show()


# Algorithm for finding the girth using a breadth-first-search
def girth(G):
    # Create list of nodes to search through and empty list of checked nodes
    toCheck = list(map(int,G.nodes()))
    checked = []
    checker = 0
    current_cycle = 10000000
    short_cycle = 10000000

    # perform this through the each node
    for n in G.nodes():
        # set the current node to toCheck[checker]
        # this checker value will increase on each iteration of the loop
        current_node = toCheck[checker]
        # add current_node to checked[] list
        checked.append(current_node)
        bounds = checked.__len__()
        neighbors = list(map(int,G.neighbors(n)))
        # Loop over all the neighbors
        for adj in neighbors:
            i = 0
            while i < bounds:
                if adj == checked[i]:
                    # Check for disconnected graph
                    # Check if a path exists between the current_node and root
                    if nx.has_path(G, '%s' % current_node, '%s' % 0 ):
                        current_cycle = nx.shortest_path_length(G, '%s' % current_node, '%s' % 0)
                    else:
                        print("Graph is disconnected")
                    # This solves the case for a complete graph, since the shortest path will always be one
                    # In a complete graph the shortest cycle is always 3
                    if G.degree('%s' % current_node) == len(G) - 1:
                        short_cycle = 3
                    # Invalidates paths of length 1 since it needs to be at least 2 away from the root to form a cycle
                    if current_cycle > 1:
                        current_cycle = current_cycle + 1
                        # If current_cycle is shorter than the previous short cycle, set new short_cycle
                        if current_cycle < short_cycle:
                            short_cycle = current_cycle
                i = i + 1
        checker = checker + 1

    if short_cycle == 10000000:
        print("There are no cycles, Graph has infinite girth.")
    else:
        print("Girth = ", short_cycle)


# Algorithm for finding the "Longest Shortest Path" or Diameter of G
def diameter(G):
    # Set original diameter to 0
    diam = 0
    # check for all nodes
    for n in G.nodes():
        # find the shortest path across the graph
        d = nx.shortest_path_length(G, n)
        # check for all paths on that node
        for key in d.keys():
            # if new path is longer than old path, then this is the new diameter
            if d[key] > diam:
                diam = d[key]

    # Print diameter
    print("Diameter = ", diam, "\n\n")


print("Graph 1")
girth(G1)
diameter(G1)

print("Graph 2")
girth(G2)
diameter(G2)

print("Graph 3")
girth(G3)
diameter(G3)

print("Graph 4")
girth(G4)
diameter(G4)
