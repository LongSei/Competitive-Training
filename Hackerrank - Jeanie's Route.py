#!/bin/python3

import os
import sys
from collections import defaultdict

sys.setrecursionlimit(200000)

# Global variables for tree processing
adj_list = defaultdict(list)      # Dictionary instead of list
total = 0

# Preprocess the city and roads to construct the adjacency list
def preprocess(city, roads):
    for road in roads:
        u, v, w = road
        if u not in adj_list:
            adj_list[u] = []
        if v not in adj_list:
            adj_list[v] = []
        adj_list[u].append([v, w])
        adj_list[v].append([u, w])

# Depth-first search to calculate the amount of children and relevant edges
def dfs_one(node: int, parent: int, city):
    global total
    check = False
    
    if node in city:
        check = True
        
    temp = []
    
    for next_edge in adj_list.get(node, []):
        next_node, next_weight = next_edge
        
        check_next_node = False
        if next_node != parent:
            check_next_node = dfs_one(next_node, node, city)
        
        if check_next_node:
            total += next_weight * 2
        else: 
            temp.append(next_edge)
            
        check |= check_next_node
    
    for remove_edge in temp:
        next_node, next_weight = remove_edge
        # Remove the edge (next_node, next_weight) from the node's adjacency list
        adj_list[node] = [edge for edge in adj_list[node] if edge != remove_edge]
        # Also remove the reverse edge (because this is an undirected graph)
        adj_list[next_node] = [edge for edge in adj_list[next_node] if edge != (node, next_weight)]
    return check

# Calculate the maximum distance (diameter) in the tree
diameter = 0
def max_distance(node: int, parent: int, depth: int) -> int:
    global diameter
    max_previous = 0
    
    for next_edge in adj_list.get(node, []):
        next_node, next_weight = next_edge
        current_distance = max_distance(next_node, node, depth + next_weight) + next_weight
        
        if next_node != parent:
            diameter = max(diameter, current_distance + max_previous)
        
        if max_previous < current_distance:
            max_previous = current_distance
    
    diameter = max(diameter, max_previous + depth)
    return max_previous

# Main function to solve the problem
def jeanisRoute(city, roads):
    global total
    # Initialize and process the tree
    preprocess(city, roads)
    
    # Perform DFS starting from the first city
    dfs_one(city[0], city[0], city)
    
    # Compute the diameter of the tree and adjust the total
    max_distance(city[0], city[0], 0)
    total -= diameter
    
    return total

# Main input/output handling
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    nk = input().split()
    n = int(nk[0])  # Number of cities (nodes)
    k = int(nk[1])  # Number of special cities (k nodes)

    # Read the list of special cities
    city = list(map(int, input().rstrip().split()))

    # Read the roads (edges) of the tree
    roads = [list(map(int, input().rstrip().split())) for _ in range(n - 1)]

    # Call the main function to calculate the result
    result = jeanisRoute(city, roads)

    # Write the result to the output
    fptr.write(str(result) + '\n')
    fptr.close()
