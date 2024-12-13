#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'truckTour' function below.
#
# The function is expected to return an INTEGER.
# The function accepts 2D_INTEGER_ARRAY petrolpumps as parameter.
#

def truckTour(petrolpumps):
    # Initialize parameters
    n = len(petrolpumps)
    one_to_index = [0] * (n + 1)
    index_to_end = [0] * (n + 1)
    prefix_petro_fill = [0] * (n + 1)
    prefix_petro_consume = [0] * (n + 1)
    
    # Calculate the prefix petro consume and petro fill
    for index in range(1, n + 1): 
        prefix_petro_consume[index] = prefix_petro_consume[index - 1]
        prefix_petro_fill[index] = prefix_petro_fill[index - 1]
        prefix_petro_consume[index] += petrolpumps[index - 1][1]
        prefix_petro_fill[index] += petrolpumps[index - 1][0]
    
    # Calculate the one_to_index minimum petro from start
    total_current_petrol = petrolpumps[0][0] - petrolpumps[0][1]
    one_to_index[1] = 0
    for index in range(2, n + 1): 
        petrol_index = index - 1
        one_to_index[index] = one_to_index[index - 1]
        need_add_petrol_from_start = True if total_current_petrol < 0 else False
        if need_add_petrol_from_start == True: 
            one_to_index[index] += abs(total_current_petrol)
            total_current_petrol = 0
        total_current_petrol += petrolpumps[petrol_index][0] - petrolpumps[petrol_index][1]
        
    # Calculate the index_to_end minimum petro from start
    index_to_end[n] = 0
    for index in range(n - 1, 0, -1): 
        petrol_index = index - 1
        excess_next = petrolpumps[petrol_index][0] - petrolpumps[petrol_index][1]
        index_to_end[index] = excess_next - index_to_end[index + 1]
        index_to_end[index] = 0 if index_to_end[index] >= 0 else abs(index_to_end[index])
        
    # Check for each position
    for index in range(1, n + 1): 
        if index_to_end[index] != 0: 
            continue
        first_tour_fill = prefix_petro_fill[n] - prefix_petro_fill[index - 1]
        first_tour_consume = prefix_petro_consume[n] - prefix_petro_consume[index - 1]
        remain_petro_after_first_tour = first_tour_fill - first_tour_consume
        
        if (one_to_index[index] <= remain_petro_after_first_tour): 
            return index - 1
    

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input().strip())

    petrolpumps = []

    for _ in range(n):
        petrolpumps.append(list(map(int, input().rstrip().split())))

    result = truckTour(petrolpumps)

    fptr.write(str(result) + '\n')

    fptr.close()
