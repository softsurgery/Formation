from numpy import array

T1 = array([str]*20)
T2 = array([str]*20)

n = int(input("N="))
while(not(1<=n<=20)):
    n = int(input("N="))
    
for i in range(n):
    T1[i] = input("T[{}]=".format(i))
    while(not(T1[i] in ["A","C","T","G"])):
        T1[i] = input("T[{}]=".format(i))

for i in range(n):
    if (T1[i]=="A"):
        T2[i] = "U"
    elif(T1[i]=="C"):
        T2[i]="G"
    elif(T1[i]=="G"):
        T2[i]="C"
    else:
        T2[i]="A"
        
for i in range(n):
    print(T1[i])
for i in range(n):
    print("|",end="")
for i in range(n):
    print(T2[i])
    
