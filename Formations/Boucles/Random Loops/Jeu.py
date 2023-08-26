import random

guess = random.randint(0,100)
x =int(input("Try to guess"))
s = 1
while(x!=guess):
    if (x>guess): print("its greater then")
    elif (x<guess): print("its less then")
    x =int(input("Try to guess"))
    s = s + 1

print(f"You tried {s} times :)")