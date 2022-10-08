import numpy as np

def fun(n, arr):
    i=np.zeros(n)
    for x in arr:
        i[x - 1]=1
    for m in range (n):
        if i[m]==0:
            return m + 1


n=int(input())
array=list(map(int,input().split()))
print(fun(n, array))