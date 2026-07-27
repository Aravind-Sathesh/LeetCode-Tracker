class Solution {
public:
    int largestInteger(int n, int s) {
        if (s==0) return 0;
        if (s>9*n) return -1;
        if (n==1) return s;

        int res=0;
        for (int i=0 ; i<n ; i++) {
            int d = (s>9 ? 9 : s);
            res = res*10 + d;
            s-=d;
        }
        return res;
    }
};