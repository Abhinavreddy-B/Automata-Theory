#!/bin/python3

from src import *

def rule(cell_value: int, neighbors: "list[int]") -> int: 
    if(neighbors[3] == int(1)):
        return int(1)
    return cell_value
        # Other functionality to run the simulation and render the state