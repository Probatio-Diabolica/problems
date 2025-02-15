def minimumSumSubarray( nums, l: int, r: int) -> int:
        N = len(nums)
        INF=10**20

        def go(k):
            best=INF
            for start in range(N):
                if start + k <=N:
                    total = sum(nums[start:start+k])
                    if(total>0):best=min(best,total)
            return best
        best=INF
        for k in range(l,r+1):
            r=go(k)
            if(r>0):best= min(best,r)
        if best >=INF:return -1
        return best


print(minimumSumSubarray([1,3,-2,4],l=1,r=2))