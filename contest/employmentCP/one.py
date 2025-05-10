def isEqualXor( arr):
    one = 0
    preSum=[0]*len(arr)
    checks=[]
    for i in range(len(arr)):
        one ^= arr[i]
        preSum[i]=one
        if(one == 0 and arr[i]!=0):
            checks.append(i)


    if(len(checks)==1):
        if(checks[0]==len(arr)-1):
            return True
        else:
            put=checks[0]
            return True if(preSum[put-1]==preSum[len(arr)-1]) else False
    
    elif(len(checks)>1):
        return True if(arr[len(arr)-1]==0) else False
    
    else: return False






print(isEqualXor([1,3,3,1,2,5,5,2]))

print(isEqualXor([2,5,4,3,1,2]))


print(isEqualXor([1,3,2,5]))


print(isEqualXor([4,6,3,1]))
