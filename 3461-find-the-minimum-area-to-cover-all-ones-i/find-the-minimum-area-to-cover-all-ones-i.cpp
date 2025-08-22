class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int maxRow = 0;
        int maxCol = 0;
        int minRow = n;
        int minCol = m;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    // Get the maximum row and column having 1
                    // These are the lower boundaries
                    maxRow = max(i, maxRow);
                    maxCol = max(j, maxCol);

                    // We also need the upper boundaries as to from where the area will start
                    minRow = min(i, minRow);
                    minCol = min(j, minCol);
                }
            }
        }

        return (maxRow - minRow + 1)*(maxCol - minCol + 1);
    }
};