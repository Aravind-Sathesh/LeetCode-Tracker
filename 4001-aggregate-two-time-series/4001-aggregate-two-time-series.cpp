class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        int n1 = series1.size();
        int n2 = series2.size();
        
        int pt1 = 0;
        int pt2 = 0;

        vector<vector<int>> res;
        
        while (pt1<n1 && pt2<n2) {
            int t1 = series1[pt1][0];
            int t2 = series2[pt2][0];
            res.push_back({min (t1, t2), series1[pt1][1]+series2[pt2][1]});
            if (t1 <= t2)  pt1++;
            if (t1 >= t2)  pt2++;
        }

        while (pt1<n1) {
            res.push_back({series1[pt1][0], series1[pt1][1]});
            pt1++;
        }

        while (pt2<n2) {
            res.push_back({series2[pt2][0], series2[pt2][1]});
            pt2++;
        }

        return res;
    }
};