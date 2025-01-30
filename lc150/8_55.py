



def canJumpG( nums:list[int]):
    #greedy
    if(nums[0]==0 and len(nums)>2 ): return False
    if(len(nums)==1 ): return True
    maxJump=nums[0]+1
    for i in range(0,len(nums)-1):
        if(nums[i]==0):
            if(maxJump==0): return False
        else:
            if(maxJump<nums[i]):maxJump=nums[i]+1
        maxJump-=1
    
    return True
    
def canJump( nums:list[int]):
    # DP table for solutions starting at index 0.
    dp = [[len(nums)+1 for i in range(len(nums))]]

    # Base case.
    dp[0][0] = 0

    # Solve only for starting 0.
    for i in [0]:
        # All possible destinations.
        for j in range(i+1, len(nums)):
            #All possible intermediates between i and j.
            for k in range(i, j):
                if k + nums[k] >= j:
                    dp[i][j] = min(dp[i][j], 1+dp[i][k])

            
    return False if (dp[0][len(nums)-1] == 0) else True


if __name__ =="__main__":
    nums=[2,0,0,0]
    print(canJump(nums))    