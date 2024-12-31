def jump(nums: list[int]) -> int:
    res=0
    l=r=0

    while r < len(nums)-1:
        rp=0
        for i in range(l,r+1):
            rp=max(rp,i+nums[i])
        l=r+1
        r=rp
        res+=1
        
    return res



if __name__ =="__main__":
    n2=[0]
    nums2=[5,4,0,0,0,1]
    num3=[1,6,0,0,0,0,7,9]
    nums56=[2,3,1,1,4]
    nums=[1,1,1,1]
    print(jump(nums))
    print(jump(n2))
    print(jump(nums2))
    print(jump(num3))
    print(jump(nums56))
    print(jump([2,8,7,6,5,4000,3,2,1]))
    print(jump([1,2,3,4,5,6,7,8]))