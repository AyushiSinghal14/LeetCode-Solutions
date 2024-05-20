class Solution {
public:
    int subsetXORSum(vector<int>& nums, int i = 0, int x = 0) {
        return i == nums.size() ? x : subsetXORSum(nums, i + 1, x ^ nums[i]) + subsetXORSum(nums, i + 1, x);
    }
};