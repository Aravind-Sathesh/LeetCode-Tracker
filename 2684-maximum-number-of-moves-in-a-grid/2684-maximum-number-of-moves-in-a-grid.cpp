class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp (m, vector<int> (n, 0));

        for (int j=n-2 ; j>=0 ; j--) {
            for (int i=m-1 ; i>=0 ; i--) {
                int valid=0;
                if (i-1>=0 && grid[i][j] < grid[i-1][j+1]) {
                    dp[i][j] = max(dp[i-1][j+1], dp[i][j]);
                    valid=1;
                }
                if (i+1<m && grid[i][j] < grid[i+1][j+1]) {
                    dp[i][j] = max(dp[i+1][j+1], dp[i][j]);
                    valid=1;
                }
                if (grid[i][j] < grid[i][j+1]) {
                    dp[i][j] = max(dp[i][j+1], dp[i][j]);
                    valid=1;
                }
                if (valid) dp[i][j]++;
            }
        }

        int maxMoves=0;

        for (int i=0 ; i<m ; i++) maxMoves = max(maxMoves, dp[i][0]);

        return maxMoves;
    }
};