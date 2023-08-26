import random

score = 0 
for i in range(10):
    a = random.randint(1,10)
    b = random.randint(1,10)
    rep = a * b
    sugg = int(input("{} x {}= ?\n".format(a,b)))
    if (rep==sugg):
        score+=1
    else:
        score-=1

print("Your Score = ",score)