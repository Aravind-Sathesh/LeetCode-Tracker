class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int n = nums.size();
        int even = 0, odd = 0, left, right, limit;

        for (int i=0 ; i<n ; i+=2) {
            left = (i > 0) ? nums[i - 1] : INT_MAX;
            right = (i+1 < n) ? nums[i+1] : INT_MAX;
            limit = min(left, right) - 1;

            if (nums[i] > limit) even += nums[i] - limit;
        }

        for (int i=1 ; i<n ; i+=2) {
            left = (i > 0) ? nums[i - 1] : INT_MAX;
            right = (i+1 < n) ? nums[i+1] : INT_MAX;
            limit = min(left, right) - 1;

            if (nums[i] > limit) odd += nums[i] - limit;
        }

        return min(even, odd);
    }
};