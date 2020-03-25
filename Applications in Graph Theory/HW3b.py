# --------------------------------------
# Zack Fravel
# 010646947
# CSCE 5014 Applications of graph Theory
# --------------------------------------
# experiment.py
#
# Simulation of randomized signed
# complete networks
# --------------------------------------

import random
import networkx as nx


# Function for generating a random boolean value
def decision(probability):

    return random.random() < probability


# Assigns random signs to all edges in graph using decision function
# True  = (+)
# False = (-)
def assign_signs():

    for u, v in g.edges():
        g[u][v]['sign'] = decision(.5)

    pass


# Chooses two random nodes in a triad and flips the sign of the edge joining them
def flip_random_sign(t):

    # Pick two random nodes
    random_a = random.choice(t)
    random_b = random.choice(t)

    # Avoid choosing the same random node
    while random_b == random_a:
        random_b = random.choice(t)

    # Flip the sign of the edge
    g[random_a][random_b]['sign'] = not g[random_a][random_b]['sign']

    pass


# Function to check if a triad is balanced
def balance_check(triad):

    a = triad[0]
    b = triad[1]
    c = triad[2]

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


# Function to check if a graph is balanced using list of triads
def balanced_graph_check(triads):

    if (all(balance_check(triad) is True for triad in triads)) is True:
        # print("Balanced Graph")
        return True
    else:
        # print("Graph is not balanced")
        return False


# Dynamic processes algorithm described in homework
# 1. Pick triad at random
# 2. If it's balanced, do nothing
# 3. Otherwise, choose one of the edges uniformly at random and flip its sign (balancing the triad)
def triad_analysis(triads):

    t = random.choice(triads)

    # If balanced
    if balance_check(t) is True:
        # Do nothing
        pass
    # If unbalanced, choose an edge at random and flip sign
    else:
        flip_random_sign(t)
        pass

    pass


process_count = 0                                    # Process count
process_limit = 100                                  # Process limit
iteration_count = 0                                  # Iteration count
iteration_limit = 1000000                            # Iteration limit
balanced_graphs = 0                                  # Balanced graphs count
iteration_average = 0                                # Iteration average

while process_count < process_limit:

    g = nx.complete_graph(10)  # Initialize complete graph with 10 nodes

    assign_signs()  # Create random signed graph

    tri = nx.triangles(g)  # Find triangles

    cliques = nx.enumerate_all_cliques(g)  # Find cliques (all nodes degree n-1)

    triad_cliques = [l for l in cliques if len(l) == 3]  # Stores edge list of all triads

    # Run the dynamic process for a maximum of 1,000,000 iterations
    while iteration_count < iteration_limit:

        # Check if graph is balanced
        if balanced_graph_check(triad_cliques) is True:
            # print("Balanced graph found!")
            # print("Iterations: ", iteration_count)
            iteration_average += iteration_count
            iteration_count = 0
            balanced_graphs += 1
            break
        else:
            triad_analysis(triad_cliques)

        iteration_count += 1

    process_count += 1

print('\n', balanced_graphs, "out of", 100, "graphs ended up balanced")
print('\n', "Average number of iterations was ", iteration_average/100)
