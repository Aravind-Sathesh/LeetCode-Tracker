class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int n = arr.size();
        int requiredSum = 0;
        for (int num: arr) requiredSum+=num;
        if (requiredSum%3!=0) return false;
        requiredSum/=3;
        int currSum = 0;
        bool flag = 0;
        for (int i=0 ; i<n ; i++) {
            currSum+=arr[i];
            if (currSum == requiredSum && !flag) {
                flag=1;
                currSum=0;
            } else if (currSum == requiredSum && flag && i<n-1) return true;
        }
        return false;
    }
};