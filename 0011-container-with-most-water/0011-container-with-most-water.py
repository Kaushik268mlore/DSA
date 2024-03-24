class Solution:
    def maxArea(self, nums: List[int]) -> int:
        l,r=0,len(nums)-1
        res=0
        while(l<r):
            res=max(res,min(nums[l],nums[r])*(r-l))
            if nums[l]<=nums[r]:
                l+=1
            elif nums[r]<nums[l]:
                r-=1
        return res
        