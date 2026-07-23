class Solution {
public:
    int nthUglyNumber(int n) {
        vector <int> dp (n);
        int x=0 , y=0 , z=0;
        dp[0] = 1;

        for (int i=1 ; i<n ; i++) {
            int nxt = min({dp[x]*2, dp[y]*3, dp[z]*5});
            dp[i] = nxt;

            if (nxt == dp[x]*2) x++;
            if (nxt == dp[y]*3) y++;
            if (nxt == dp[z]*5) z++;
        }
        
        return dp[n-1];
    }
};