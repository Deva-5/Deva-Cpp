import random

upper="ABCDEFGHIJKLMNOPQRSTUVWXYZ"
lower="abcdefghijklmnopqrstuvwxyz"
digits="1234567890"
character="!@#$%^&*()+-="

ans = upper+lower+digits+character

print("Enter the password size:")

n=int(input())

temp=random.sample(ans,n)

password ="".join(temp)

print(password)

