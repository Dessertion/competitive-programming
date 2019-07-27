import sys
input = sys.stdin.readline

n = int(input())
owo = []
owo2 = bin(n)

while n != 1:
    if n&1 == 1:
        n=n-1
        owo.append(1)
    n=n//2
    owo.append(0)

fib1 = 1
fib2 = 1

mod = int(1e9+7)
print(owo)
print(owo2)

while owo != []:
    if owo[-1] == 1:
        fib2=(fib1+fib2)%mod
        fib1=(fib2-fib1)%mod
    else:
        fib1,fib2=(fib1*((2*fib2)-fib1))%mod,(((fib2*fib2)%mod)+((fib1*fib1)%mod))%mod
    owo.pop()
print(fib1)