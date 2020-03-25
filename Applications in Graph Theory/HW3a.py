# --------------------------------------
# Zack Fravel
# 010646947
# CSCE 5014 Applications of graph Theory
# --------------------------------------
# HW3.py
#
# Analysis of  U.S. Senate roll call
# voting data using NetworkX
# --------------------------------------

# ################################################################### #
# IMPORTANT: HW3.py must be in the same directory as roll_call_votes  #
# ################################################################### #

# Program takes a directory of US roll call votes specified by folder number (101 - 115-2).
# The program parses the xml documents and generates a graph where each node
# represents a US senator and each edge corresponds to Senators voting the same way.
# The weight of an edge is the number of times the Senators voted the same way.
# The thickness of the edge on the produced plot is also an indication of cooperation.

import os
import networkx as nx
import matplotlib.pyplot as plt
import xml.etree.ElementTree as et


# Returns the path to all the .xml documents within one folder
def get_xml_path(filepath):

    xml_path_list = []

    for filename in os.listdir(filepath):

        if filename.endswith(".xml"):
            xml_path_list.append(os.path.join(filepath, filename))

    return xml_path_list


# Create signed graph from given graph of senators
def create_signed(g, n):
    for u, v in g.edges():
        # Voted the same
        if g[u][v]['weight'] >= n:
            # Positive Edge
            g[u][v]['sign'] = True
        # Voted differently greater than n times
        if (10 - g[u][v]['weight']) > n:
            # Negative Edge
            g[u][v]['sign'] = False

    pass


# Function for detecting balance
def detect_balance(g, a, b, c):
    # (+, +, +)
    if (g[a][b]['sign'] is True) and (g[a][c]['sign'] is True) and (g[b][c]['sign'] is True):
        return True
    # (+, -, -)
    elif (g[a][b]['sign'] is True) and (g[a][c]['sign'] is False) and (g[b][c]['sign'] is False):
        return True
    # (-, +, -)
    elif (g[a][b]['sign'] is False) and (g[a][c]['sign'] is True) and (g[b][c]['sign'] is False):
        return True
    # (-, -, +)
    elif (g[a][b]['sign'] is False) and (g[a][c]['sign'] is False) and (g[b][c]['sign'] is False):
        return True
    else:
        return False


# Function used to detect cycles and perform analysis
def detect_cycles(g):

    cycles = nx.cycle_basis(g)

    balanced = 0
    not_balanced = 0

    for cyc in cycles:

        a = cyc[0]
        b = cyc[1]
        c = cyc[2]

        if detect_balance(g, a, b, c) is True:
            # print("Graph is balanced")
            balanced += 1
        else:
            # print("Graph is not balanced")
            not_balanced += 1

    pass


# Add edges for a given senator on a given vote
def add_edges(g, member):

    global edge_width

    # Check all nodes
    for nodes in g.nodes():

        # Compare votes with current node
        if member[5].text == g.node[nodes]['vote']:

            # Edge already exists
            if g.has_edge(member[0].text, nodes):

                # Modify edge attributes (increase thickness and weight)
                g[member[0].text][nodes]['thickness'] += 0.01
                g[member[0].text][nodes]['weight'] += 1

                # If from opposing parties
                if g.node[member[0].text]['party'] != g.node[nodes]['party']:
                    # +1 to cooperation_level on each node
                    g.node[member[0].text]['cooperation_level'] += 1
                    g.node[nodes]['cooperation_level'] += 1

            # Edge doesn't exist
            else:

                # Add Edge
                g.add_edge(member[0].text, nodes, thickness=0.01, weight=1, opposed=False, sign=None)

                # Indicate opposition if Senators are in different parties
                if g.node[member[0].text]['party'] != g.node[nodes]['party']:
                    g[member[0].text][nodes]['opposed'] = True
                    # Add +1 to cooperation_level on each node
                    g.node[member[0].text]['cooperation_level'] += 1
                    g.node[nodes]['cooperation_level'] += 1

        # Remove all edges between senators and themselves
        if member[0].text == nodes:
            if g.has_edge(member[0].text, nodes):
                g.remove_edge(member[0].text, nodes)

    # Assign width attribute for each edge to the edge_width list
    for u, v in g.edges():
        edge_width = g[u][v]['thickness']

    pass


# Create a graph given a folder of roll call votes (XML documents)
def initialize_graph(g, folder):

    ry = 0  # Y-location variables for R nodes on plot
    dy = 0  # Y-location variables for D nodes on plot
    modify_flag = False

    # Loop through each roll call vote in each folder
    for file in folder:

        # Set XML file in folder to be parsed
        tree = et.parse(file)
        root = tree.getroot()
        print('\n', file, '\n')

        # Check for root structure
        if root[5].tag == 'modify_date':
            member_level = 17
            modify_flag = True
        else:
            member_level = 16

        # Loop through each senator in roll call vote
        for members in root[member_level]:

            # If node doesn't exist
            if members[0].text not in senators:

                # Add senator to list
                senators.append(members[0].text)
                # Add node
                g.add_node(members[0].text, position=(0, 0), experience=1, party='n/a', vote='n/a', cooperation_level=0)

                # Check for Republican or Democrat
                if members[3].text == 'R':

                    # Set node position
                    g.node[members[0].text]['position'] = (0, ry)
                    # Set node party affiliation
                    g.node[members[0].text]['party'] = 'R'
                    # Set node color
                    color_map.append('red')
                    # Increment position variable
                    ry += 0.3

                else:

                    # Set node position
                    g.node[members[0].text]['position'] = (1, dy)
                    # Set node party affiliation
                    g.node[members[0].text]['party'] = 'D'
                    # Set node color
                    color_map.append('blue')
                    # Increment position variable
                    dy += 0.3

            # If node already exists
            else:

                # Add experience point
                g.node[members[0].text]['experience'] += 1

            # Record vote and store to node
            if members[5].text == 'Yea':
                g.node[members[0].text]['vote'] = 'Yea'
            elif members[5].text == 'Nay':
                g.node[members[0].text]['vote'] = 'Nay'
            else:
                pass

            # Add edges to node
            add_edges(g, members)

        # Reset vote on each node so as to avoid incorrect edge creation
        for node in g.nodes():
            g.node[node]['vote'] = 'n/a'

    if modify_flag is True:
        print("This analysis contains modified votes")

    pass


# Create lists and graph
g = nx.Graph()      # Create graph
color_map = []      # Colors List for party affiliation
edge_width = []     # Use to record weight of each edge
senators = []       # List of senators

# Ask for user input
requested_folder = input("Enter folder number (101, 102, ... 115, 115-2): ")
folder_string = "roll_call_votes/"+requested_folder

# Initialize graph from the folder specified by the user
initialize_graph(g, get_xml_path(folder_string))

# Modify graph to be signed
# Input 'n' value here (6, 7, 8, 9, 10)
create_signed(g, 6)

# Detect cycles in graph and check edges
detect_cycles(g)
