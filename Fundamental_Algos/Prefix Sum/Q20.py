def subarraysDivByK(nums: list[int], k: int) -> int:
    count,sum=0,0
    map={0:1}
    for i in nums:
        sum+=i
        if (sum%k) in map:
            count+=map[sum%k]
            map[sum%k]+=1
        else:
            map[sum%k]=1
    return count

a=[5]
print(subarraysDivByK(a,9))

