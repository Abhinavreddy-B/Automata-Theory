from rule import *

configration = open('./q2/config.txt',"r")
[m,n,k] = configration.__next__().split(' ')
m = int(m)
n= int(n)
k = int(k)
arr = [[int(0) for x in range(0,m+2)] for y in range(0,n+2)]
for i in range(0,k):
    line = configration.readline()
    [x,y] = line.replace('\t',' ').strip('\n ').split(' ')
    x = int(x)
    y= int(y)
    arr[n - y + 1][x] = int(1)

for i in range(1,n+1):
    for j in range(1,m+1):
        if arr[i][j] == 0:
            # print('0',end="",file=f)
            print('\033[41mO\033[0m',end="")
        else:
            # print('1',end="",file=f)
            print('\033[42mX\033[0m',end="")
    print()
print("Initial state ^")

iterations = int(input("Enter the number of iterations: "))
arr_present = [[0 for x in range(0,m+2)] for y in range(0,n+2)]
arr_prev = [[0 for x in range(0,m+2)] for y in range(0,n+2)]
for i in range(0, n+2):
    for j in range(0, m+2):
        arr_present[i][j] = arr[i][j]
        arr_prev[i][j] = arr[i][j]

cnt = int(0)

while(iterations != -1):
    f = open('./q2/output.txt','w')
    completed = iterations
    while(completed != 0):
        for i in range(1,n+1):
            for j in range(1,m+1):
                arr_present[i][j] = rule(arr_prev[i][j],[arr_prev[i-1][j-1],arr_prev[i-1][j],arr_prev[i-1][j+1],arr_prev[i][j-1],arr_prev[i][j+1],arr_prev[i+1][j-1],arr_prev[i+1][j],arr_prev[i+1][j+1]])
        completed = completed - 1
        for i in range(0,n+2):
            for j in range(0,m+2):
                arr_prev[i][j] = arr_present[i][j]
        cnt=cnt+1

    for i in range(1,n+1):
        for j in range(1,m+1):
            if arr_prev[i][j] == 0:
                print('O',end="",file=f)
                print('\033[41mO\033[0m',end="")
            else:
                print('X',end="",file=f)
                print('\033[42mX\033[0m',end="")
        print(file=f)
        print()
    print("Iteration Number:",cnt,"\tDimensions:",m,"x",n)
    f.close()
    iterations = int(input("Enter the number of iterations: "))
