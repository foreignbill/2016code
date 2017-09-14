/**************************************************************
    Problem: 1002
    User: foreignbill
    Language: Python
    Result: Accepted
    Time:96 ms
    Memory:6360 kb
****************************************************************/
 
#main
n = int(raw_input())
f = [0]*(n+1)
  
f[0] = 1
for i in range(1,n+1):
    for j in range(0,i):
        f[i] += f[j] * (i-j)
  
ans = f[n]
 
for i in range(1,n):
    ans += f[i]*2
print ans