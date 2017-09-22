T=int(input())
for i in range (T):
    N=int(input())
    arr = [int(x) for x in input().split()]
    barr = [int(x) for x in input().split()]
    maxi=0
    count=0
    for m in range(0,N):
        for j in range (0,N):
            num=(arr[m])*(barr[j])
            if(num>maxi):
                maxi=num
                count=1
            elif(num==maxi):
                count=count+1
    print(count)
