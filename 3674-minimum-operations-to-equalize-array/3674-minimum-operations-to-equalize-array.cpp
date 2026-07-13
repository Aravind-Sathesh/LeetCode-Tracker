class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums[0];
        for (int num:nums) if (num!=n) return 1;
        return 0;
    }
};