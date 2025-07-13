length = int(input("How long should the sequence be? "))

# A typical Fibonacci Sequence starts with two numbers, 0 and 1. I set this outside the loop to ensure an accurate calcualtion
prev = 0
num = 1

# We get our Sequence
for i in range(length):
    print(prev)
    temp = prev
    prev = num
    num += temp
