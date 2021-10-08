#codechef ARRGRAPH (Snackdown advance) solution

from math import gcd 
tc=int(input())
for i in range(tc):
    n = int(input())
    arr=list(map(int,input().split()))
    brr = [0 for j in range(n)]
    if n==1:
        print(0)
        print(*arr)
        continue

    for j in range(n):
        for k in range(j+1,n):
            if gcd(arr[j],arr[k])==1:
                brr[k]=1
                brr[j]=1
    ans=0
    if brr.count(0)>=1:
        ans=1
        if arr[brr.index(0)]==47:
            arr[brr.index(0)]=46
        else:
            arr[brr.index(0)]=47
    
    print(ans)
    print(*arr)
