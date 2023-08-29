a = int(input("A ="))
b = int(input("B ="))

print("A ={} ; B ={}".format(a,b))

aux = a
a = b
b = aux

# ou a,b = b,a

print("A ={} ; B ={}".format(a,b))