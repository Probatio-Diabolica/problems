def pivotInteger(n: int) -> int:
    if(n==1): return 1
    suum=[]
    summ=0
    for i in range(1,n+1):
        summ+=i
        suum.append(summ)
    
    for i in range(1,n):
        if(suum[i]==(suum[n-1]-suum[i-1])): return i+1
    return -1

print(pivotInteger(8))
print(pivotInteger(1))