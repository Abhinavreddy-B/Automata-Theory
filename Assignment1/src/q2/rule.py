#!/bin/python3

from src import *

def rule(cell_value: int, neighbors: "list[int]") -> int:
    sum = neighbors[0]+neighbors[1]+neighbors[2]+neighbors[3]+neighbors[4]+neighbors[5]+neighbors[6]+neighbors[7]
    # print(cell_value,cnt1,cnt2,cnt3,cnt4)
    if( sum < 2 and cell_value):
        return 0
    elif(sum > 3 and cell_value ):
        return 0
    elif( sum == 3 and ( not cell_value) ):
        return 1
    return cell_value
    