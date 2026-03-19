class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> prefixX(n, vector<int>(m, 0));
        vector<vector<int>> prefixY(n, vector<int>(m, 0));

        int count = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int isX = 0;
                int isY = 0;

                if(grid[i][j] == 'X') isX = 1;
                if(grid[i][j] == 'Y') isY = 1;

                prefixX[i][j] = isX;
                prefixY[i][j] = isY;

                if(i > 0){
                    prefixX[i][j] += prefixX[i-1][j];
                    prefixY[i][j] += prefixY[i-1][j];
                }
                if(j > 0){
                    prefixX[i][j] += prefixX[i][j-1];
                    prefixY[i][j] += prefixY[i][j-1];
                }
                if(i > 0 && j > 0){
                    prefixX[i][j] -= prefixX[i-1][j-1];
                    prefixY[i][j] -= prefixY[i-1][j-1];
                }
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(prefixX[i][j] == prefixY[i][j] && prefixX[i][j] > 0){
                    count++;
                }
            }
        }

        return count;
    }
};