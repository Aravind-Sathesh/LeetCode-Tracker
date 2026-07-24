class Solution {
public:
    bool canDistribute(int k, int n, vector<int>& quantities) {
        long storesNeeded = 0;
        for (int qty: quantities) storesNeeded += (qty+k-1) / k;
        return storesNeeded <= n;
    }
    
    int minimizedMaximum(int n, vector<int>& quantities) {
        int left = 1;
        int right = *max_element(quantities.begin(), quantities.end());
        if (n==quantities.size()) return right;

        int res = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (canDistribute(mid, n, quantities)) {
                res = mid;
                right = mid-1; 
            } else left = mid+1;
        }

        return res;
    }
};