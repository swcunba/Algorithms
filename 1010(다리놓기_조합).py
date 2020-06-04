from math import factorial
t = int(input())
for i in range(0, t):
    n, m = map(int, input().split())
    result = factorial(m)/(factorial(n)*factorial(m-n))
    print(int(result))
