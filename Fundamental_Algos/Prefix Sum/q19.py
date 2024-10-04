def shortestSubarray(self, nums, k: int) -> int:
    currLen=len(nums)
    minWindow=len(nums)
    sum=0
    for i in nums:
        if(i>0): 
            sum+=i
            currLen+=1
        else:
            sum=0
            currLen=0
        
        if(sum>=k and currLen)