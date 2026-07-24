class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();
        vector<vector<int>> ans(m, vector<int>(n, -1));
        queue<pair<int,int>> q;

        for (int r=0 ; r<m ; r++) {
            for (int c=0 ; c<n ; c++) {
                if (isWater[r][c] == 1) {
                    ans[r][c] = 0;
                    q.push({r, c});
                }
            }
        }

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int i=0 ; i<4 ; i++) {
                int nr = r+dr[i];
                int nc = c+dc[i];

                if (nr>=0 && nr<m && nc>=0 && nc<n && ans[nr][nc]==-1) {
                    ans[nr][nc] = ans[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }

        return ans;
    }
};