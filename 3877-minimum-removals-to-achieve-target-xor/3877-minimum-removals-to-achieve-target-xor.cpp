class Solution {
public:
    int minRemovals(vector<int>& nums, int target) {
        const int MAX_XOR = 1 << 14;
        int n = nums.size();
        vector <vector <int>> dp (n+1, vector<int> (MAX_XOR, INT_MAX));
        dp[0][0] = 0;
        for (int i=0 ; i<n ; i++) { // index
            for (int j=0 ; j<MAX_XOR ; j++) { // current XOR
               
                if (dp[i][j] == INT_MAX) continue;
               
                dp[i+1][j^nums[i]] = min(dp[i+1][j^nums[i]], dp[i][j]); // keep the element at i
                dp[i+1][j] = min(dp[i+1][j], dp[i][j]+1); // not keep the element at i
            }
        }

        if (dp[n][target] == INT_MAX) return -1;
        return dp[n][target];
    }
};