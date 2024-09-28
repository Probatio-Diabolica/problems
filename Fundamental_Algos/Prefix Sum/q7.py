def isCovered( ranges, left: int, right: int) -> bool:
    intervals=[0]*50
    for gap in ranges:
        l=gap[0]
        r=gap[1]
        while(l<=r):
            intervals[l]+=1
            l+=1
    
    while(left<=right):
        if(intervals[left]==0): return False 
        left+=1
    return True

print(isCovered([[1,2],[3,4],[5,6]],1,2))
print(isCovered([[1,10],[10,20]],21,21))
