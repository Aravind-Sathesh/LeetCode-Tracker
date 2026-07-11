class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int n = grid.size();

        if (n == 1)
            return 2 * grid[0][0] + 1;

        int areaSum = 0;
        int nonZeroCells = 0;

        for (vector<int> row : grid) {
            int rowMax = 0;
            for (int box : row) {
                rowMax = max(rowMax, box);
                if (box!=0) nonZeroCells++;
            }
            areaSum += rowMax;
        }

        for (int i=0 ; i<n ; i++) {
            int colMax=0;
            for (int j=0 ; j<n ; j++) colMax = max(colMax, grid[j][i]);
            areaSum+=colMax;
        }
        
        return areaSum + nonZeroCells;
    }
};