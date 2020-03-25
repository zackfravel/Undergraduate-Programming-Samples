# --------------------------------------
# Zack Fravel
# 010646947
# CSCE 5014 Applications of graph Theory
# --------------------------------------
# hw4.py
# --------------------------------------

import random as rand
import networkx as nx

# Read directed edge list of email network and store into variable G
g = nx.read_edgelist("graph.txt", create_using=nx.DiGraph())

# Store list of strongly connected components, as subgraphs sorted from max to min size
strongly_connected_subgraphs = sorted(nx.strongly_connected_component_subgraphs(g), key=len, reverse=True)

# Set strongly_connected_subgraph[0] as largest_SCC after sorting
largest_SCC = strongly_connected_subgraphs[0]

# Set number of nodes of the SCC
scc_nodes = nx.number_of_nodes(strongly_connected_subgraphs[0])

# Calculate percentage of nodes and edges the SCC encompasses
largest_SCC_node_percentage = (scc_nodes/nx.number_of_nodes(g)) * 100

# Sample a random node from the SCC to check for IN and OUT components
checking_node = rand.sample(largest_SCC.nodes(), 1)[0]

# Create list of nodes for the IN component
# For all successors stemming from the checking node, append to the list if not already in it
in_component = []
for successor in nx.bfs_successors(g, checking_node):
    for element in successor:
        if element not in in_component:
            in_component.append(element)
        else:
            pass

# Calculate percentage of nodes the IN-Component encompasses
in_component_node_percentage = (len(in_component)/nx.number_of_nodes(g)) * 100

# Create list of nodes for the OUT component
# For all predecessors stemming from the checking node, append to the list if not already in it
out_component = []
for predecessor in nx.bfs_predecessors(g, checking_node):
    for element in predecessor:
        if element not in out_component:
            out_component.append(element)
        else:
            pass

# Calculate percentage of nodes the OUT-Component encompasses
out_component_node_percentage = (len(out_component)/nx.number_of_nodes(g)) * 100

# Calculate percentage of nodes the disconnected components encompass
# Calculated using the difference from the largest scc, in, and out components
disconnected_component_node_percentage = 100 - largest_SCC_node_percentage - in_component_node_percentage - \
                                         out_component_node_percentage

# Print results
print("\nbow-tie network analysis\n")

print("total nodes                     : ", "{:,}".format(len(g.nodes)))
print("total edges                     : ", "{:,}".format(len(g.edges)), "\n\n")

print("size of SCC (core)              : ", str(round(largest_SCC_node_percentage, 2)), "%", "-",
      "{:,}".format(scc_nodes))

print("size of in-component            : ", str(round(in_component_node_percentage, 2)), "%", "-",
      "{:,}".format(len(in_component)))

print("size of out-component           : ", str(round(out_component_node_percentage, 2)), "%", "-",
      "{:,}".format(len(out_component)))

print("size of disconnected components : ", str(round(disconnected_component_node_percentage, 2)), "%", "-",
      "{:,}".format(len(g.nodes()) - scc_nodes - len(in_component) - len(out_component)))
