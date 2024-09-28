# def leftRightDifference(nums: list[int]) -> list:
#     lsumm=0
#     rsumm=0
#     lSum=[0]*(len(nums))
#     rSum=[0]*(len(nums))
#     for i in range(len(nums)):
#         lSum[i]=lsumm
#         rSum[(len(nums)-1)-i]=rsumm
#         lsumm+=nums[i]
#         rsumm+=nums[len(nums)-1-i]
#     sol=[]
#     for i in range(len(nums)):
#         sol.append( abs(lSum[i]-rSum[i]))
#     return sol    

#!! wtf this supposed to be better yet it sucks than the previous answer
def leftRightDifference(nums: list[int]) -> list:
    answer=[0]*len(nums)
    for i in range(len(nums)):
        answer[i]=(abs(sum(nums[:i])-sum(nums[i+1:])))
    return answer

# !! even after modifying , it sucks
# note: found the reason, it uses slicing, hence the answer becomes more than O(n)
print(leftRightDifference([10,4,8,3]))