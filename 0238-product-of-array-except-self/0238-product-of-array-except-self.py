class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        ans = [0] * len(nums)
        prod = 1
        id = []
        for i in range(len(nums)):
            if nums[i] == 0:
                id.append(i)
                continue
            prod *= nums[i]
        if len(id) == 1:
            ans[id[0]] = prod
        elif len(id) == 0:
            for i in range(len(nums)):
                ans[i] = prod // nums[i]
        return ans