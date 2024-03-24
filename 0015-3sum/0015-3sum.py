class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        res=[]
        nums.sort()
        for i in range (len(nums)):
            j,k=i+1,len(nums)-1
            if nums[i]>0:
                break
            if i>0 and nums[i]==nums[i-1]:
                continue
            while(j<k):
                if nums[i]+nums[j]+nums[k]==0:
                    res.append([nums[i],nums[j],nums[k]])
                    j+=1
                    k-=1
                    while(nums[j]==nums[j-1] and j<k):
                            j+=1
                elif nums[i]+nums[j]+nums[k]<0:
                    j+=1
                else:
                    k-=1
        return res
                