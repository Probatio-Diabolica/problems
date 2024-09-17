class Solution:
    def swap(self,nums,a,b):
        temp=nums[a]
        nums[a]=nums[b]
        nums[b]=temp

    def sortColors(self, nums:list[int]) -> None:
        mid=0
        head=0
        tail=len(nums)-1
        while(mid<=tail):
            if(nums[mid]==0):
                self.swap(nums,mid,head)
                mid=mid+1
                head=head+1
            elif(nums[mid]==1):
                mid=mid+1
            else:
                self.swap(nums,mid,tail)
                tail=tail-1

if __name__=="__main__":
    sol=Solution()
    ab=[0,1,2,1,0,2]
    sol.sortColors(ab)
    print(ab)






