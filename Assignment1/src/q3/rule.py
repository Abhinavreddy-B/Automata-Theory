#!/bin/python3

from src import *

def rule(cell_value: int, neighbors: "list[int]") -> int:
    if( neighbors[1] == int(1) or neighbors[6] == int(1) ):
        return 1
    return cell_value
    