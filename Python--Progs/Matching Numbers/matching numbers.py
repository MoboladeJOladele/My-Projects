# Guess Game
import random

users_number = int(input("Enter a number between 1 and 10 > "))
computers_number = random.randint(1, 10)
if computers_number == users_number:
    print("Your guess is correct!")
else:
    print("That's a wrong guess. The number is meant to be", computers_number)
