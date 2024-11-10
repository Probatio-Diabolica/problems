def subarraySum(nums: list, k: int) -> int:
    prefixSums={0:1}
    curr_sum=0
    res=0
    for el in nums:
        curr_sum+=el
        diff=curr_sum-k
        res+=prefixSums.get(diff,0)
        prefixSums[curr_sum]=1+prefixSums.get(curr_sum,0)
        
    return res
print(subarraySum([0,0,1],0))
# https://leetcode.com/problems/subarray-sum-equals-k/?envType=problem-list-v2&envId=prefix-sum solve this