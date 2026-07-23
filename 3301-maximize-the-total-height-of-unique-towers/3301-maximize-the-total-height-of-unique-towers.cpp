class Solution {
public:
    long long maximumTotalSum(vector<int>& maximumHeight) {
        int n = maximumHeight.size();
        sort(maximumHeight.begin(), maximumHeight.end(), greater<int>());

        int prev_h = INT_MAX;
        long long sum=0;
        for (int h: maximumHeight) {
            int height = min(h, prev_h-1);
            if (height<=0) return -1;
            prev_h = height;
            sum+=height;
        }

        return sum;
    }
};