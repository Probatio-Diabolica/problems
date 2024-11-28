def findMaxLength( nums) -> int:
    zeros,ones=0,0
    result=0
    diff_map={}
    for index,el in enumerate(nums): 
        if (el==0) : zeros+=1
        else: ones+=1
        if(ones-zeros) not in diff_map:
            diff_map[ones-zeros] =index
        
        if(ones ==zeros):
            result = ones + zeros
        else:
            idx = diff_map[ones-zeros]
            result=max(result , index-idx)
    return result

print(findMaxLength([0,1,0,1,1,1,0]))