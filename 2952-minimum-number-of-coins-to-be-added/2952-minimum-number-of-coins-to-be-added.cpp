class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        int n = coins.size();
        sort(coins.begin(), coins.end());
        
        int maxReachable=0 , cnt=0 , i=0;
        while (maxReachable < target) {
            if (i<n && coins[i]<=maxReachable+1) {
                maxReachable += coins[i];
                i++;
            } else {
                cnt++;
                maxReachable += maxReachable+1;
            }
        }

        return cnt;
    }
};