from numpy import array
T = array([int]*10)
n = 0
i = 2
while(n<10):
    j = 2
    while(j<=i//2 and i%j!=0):
        j = j + 1
    if (j>i//2):
        T[n] = i
        n = n + 1
    i = i + 1

print(T)