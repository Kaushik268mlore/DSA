class Solution {
    public int[] productExceptSelf(int[] nums) {
    int[] ans = new int[nums.length];
    int prod = 1;
    List<Integer> id = new ArrayList<>();
    for (int i = 0; i < nums.length; i++) {
        if (nums[i] == 0) {
            id.add(i);
            continue;
        }
        prod *= nums[i];
    }
    if (id.size() == 1)
        ans[id.get(0)] = prod;
    else if (id.size() == 0) {
        for (int i = 0; i < nums.length; i++) {
            ans[i] = prod / nums[i];
        }
    }
    return ans;
}
}