n = 10**6+1
c = [0]*n
ans = [0]*n
for  i in range(2,n):
    for j in range(i,n,i):
        # print(j)
        if(c[j]%2):
            ans[j]+=i
        else:
            ans[j]-=i
        c[j]+=1

t = int(input())


for _ in range(t):
    x = int(input())
    print(ans[x]+1)