# --------------------------------------
# Zack Fravel
# 010646947
# CSCE 5014 Applications of graph Theory
# --------------------------------------
# HW2.py
#
# Analysis of  U.S. Senate roll call
# voting data using NetworkX
# --------------------------------------

# ################################################################### #
# IMPORTANT: HW2.py must be in the same directory as roll_call_votes  #
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


# Measure the cooperation of Senators against their experience
# This function is designed to take in a cumulative list of all the votes
def measure_cooperation_vs_experience(g):

    # Create lists to be used in the function
    # Cooperation lists didn't end up being used, could be used to extend further later on
    low_cooperation = []
    low_coop_exp = []
    medium_cooperation = []
    med_coop_exp = []
    high_cooperation = []
    high_coop_exp = []
    extreme_cooperation = []
    extr_coop_exp = []

    # For each node, add the experience for the Senator on each cooperation level
    for nodes in g.nodes():
        # Extreme Cooperation
        if g.node[nodes]['cooperation_level'] > 3000:
            extreme_cooperation.append(g.node[nodes])
            extr_coop_exp.append(g.node[nodes]['experience'])
        # High Cooperation
        elif 1500 < g.node[nodes]['cooperation_level'] <= 3000:
            high_cooperation.append(g.node[nodes])
            high_coop_exp.append(g.node[nodes]['experience'])
        # Medium Cooperation
        elif 500 < g.node[nodes]['cooperation_level'] <= 1500:
            medium_cooperation.append(g.node[nodes])
            med_coop_exp.append(g.node[nodes]['experience'])
        # Low Cooperation
        elif g.node[nodes]['cooperation_level'] <= 500:
            low_cooperation.append(g.node[nodes]['cooperation_level'])
            low_coop_exp.append(g.node[nodes]['experience'])

    # Create experience list
    exp_list = [low_coop_exp, med_coop_exp, high_coop_exp, extr_coop_exp]
    count = 0

    # Loop through each Senator's experience level for each level of cooperation
    for l in exp_list:

        new = 0
        experienced = 0
        very_experienced = 0
        long_standing = 0

        # Print cooperation level
        if count == 0:
            print("Low Cooperation")
            count += 1
        elif count == 1:
            print("Medium Cooperation")
            count += 1
        elif count == 2:
            print("High Cooperation")
            count += 1
        elif count == 3:
            print("Extreme Cooperation")

        print()

        # Loop through list and add respective experience levels
        # Experience levels were determined by number of votes participated in
        for e in l:
            if e <= 20:
                new += 1
            elif 20 < e <= 60:
                experienced += 1
            elif 60 < e <= 120:
                very_experienced += 1
            elif e > 120:
                long_standing += 1

        # Print experience levels
        print("New Senators              : ", new)
        print("Experienced Senators      : ", experienced)
        print("Very Experienced Senators : ", very_experienced)
        print("Long Standing Senators    : ", long_standing)
        print()

    pass


# Determine amount of homophily in a given graph of U.S. Senate votes
def measure_homophily(g):

    # List the number of edges and nodes for verification
    print(g.number_of_nodes(), "nodes")
    print(g.number_of_edges(), "total edges")
    count = 0
    for u, v in g.edges():
        if g[u][v]['opposed'] is True:
            count += 1
    print(count, "edges between Senators of opposing parties", '\n')

    republican_probability = 0
    democrat_probability = 0
    heterogeneous_weight = 0
    homogeneous_r_weight = 0
    homogeneous_d_weight = 0

    for node in g.nodes():
        if g.node[node]['party'] == 'R':
            republican_probability += 1
        else:
            democrat_probability += 1

    # p
    republican_probability = republican_probability / g.number_of_nodes()
    # q
    democrat_probability = democrat_probability / g.number_of_nodes()
    # 2pq
    cooperative_edge_probability = 2 * republican_probability * democrat_probability

    # Loop through edges and begin weighted to unweighted graph conversion process through averaging weights
    for u,v in g.edges():
        # If edge is opposing, add to heterogeneous weight
        if g[u][v]['opposed'] is True:
            heterogeneous_weight += g[u][v]['weight']
        # If not, add to homogeneous weight
        else:
            # Split between parties for later use?
            if g.node[u]['party'] == 'R':
                homogeneous_r_weight += g[u][v]['weight']
            else:
                homogeneous_d_weight += g[u][v]['weight']

    # Set weights
    homogeneous_weight = homogeneous_r_weight + homogeneous_d_weight
    combined_weight = heterogeneous_weight + homogeneous_weight

    # Set homophily threshold
    homophily_threshold = cooperative_edge_probability
    # Set percentages
    cross_party_percentage = heterogeneous_weight/combined_weight
    same_party_percentage = homogeneous_weight/combined_weight

    print("homophily evidence threshold :", homophily_threshold)
    print("cross-party percentage       :", cross_party_percentage)
    print("same-party percentage        :", same_party_percentage)
    print("     republican :", homogeneous_r_weight/homogeneous_weight)
    print("     democrat   :", homogeneous_d_weight/homogeneous_weight, '\n')

    # Determine homophily
    if (homophily_threshold - cross_party_percentage) < .1:
        print("There is slight evidence for homophily")
    elif (homophily_threshold - cross_party_percentage) < .2:
        print("There is moderate evidence for homophily")
    elif (homophily_threshold - cross_party_percentage) < .3:
        print("There is strong evidence for homophily")
    elif (homophily_threshold - cross_party_percentage) < .4:
        print("There is extremely strong evidence for homophily")

    # Print homophily percentage
    print(round(homophily_threshold - cross_party_percentage, 5), "%")

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
                g.add_edge(member[0].text, nodes, thickness=0.01, weight=1, opposed=False)

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
                g.add_node(members[0].text, position=(0, 0), experience=1, party='n/a', vote='n/a',
                           cooperation_level=0)

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

# Measure cooperation vs. experience
# Un-comment to include this in the run
# measure_cooperation_vs_experience(g)

# Measure homophily
measure_homophily(g)

# Assign positions from node attributes
position = nx.get_node_attributes(g, 'position')

# Set resolution of the plot
plt.figure(dpi=400)

# Draw graph
nx.draw(g, pos=position, node_color=color_map, node_size=8, width=edge_width,
        with_labels=True, font_size=4)

# Show plot
plt.show()
