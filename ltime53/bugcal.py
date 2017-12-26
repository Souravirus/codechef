t = int(input())
while t>0:
    a,b=input().split()
    a=int(a)
    b=int(b)
    i, temp = 10, 0
    total = a + b
    total=int(total)
    while a or b:
        if (a % 10) + (b % 10) > 9: temp += i
        a, b, i = a // 10, b // 10, i * 10
    print(total - temp)
    t=t-1
