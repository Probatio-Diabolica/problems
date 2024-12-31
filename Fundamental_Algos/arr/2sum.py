def twoSum(nums:int, target: int):
    dict={}
    dict[nums[0]]=0
    for i in range(1,len(nums)):
        if   (target-nums[i]) in dict:
            return [ dict[target-nums[i]] , i ]
        dict[nums[i]] =i 
    return []    

print(twoSum([3,3],6))