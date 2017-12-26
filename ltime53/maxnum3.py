t=input()
t = int(t)
while t:
    n=input()
    i=len(n)
    a=0
    m=0
    while i:
            b=n[0:a]+n[a+1:]
            temp,b=b,int(b)
            if b%6==0 and b > m:
                    m=b
                    s=temp
            a+=1
            i-=1
    if m==0:
            print ("-1")
    else:
            print (s[:])
    t-=1
