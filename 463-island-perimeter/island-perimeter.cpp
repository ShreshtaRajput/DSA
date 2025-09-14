class Solution {
vector<int> drow = {-1, 0, 1, 0};
vector<int> dcol = {0, 1, 0, -1};
private:
    int check(vector<vector<int>> &grid, int row, int col){
        int m = grid.size();
        int n = grid[0].size();
        int sqPeri = 0;
        for(int i = 0; i < 4; i++){
            int newRow = row + drow[i];
            int newCol = col + dcol[i];
            // If not in bounded region -> add the side to perimeter
            if(newRow < 0 || newRow >= m || newCol < 0 || newCol >= n){
                sqPeri += 1;
            }else if(grid[newRow][newCol] == 0){
                // Adjacent cell is 0
                sqPeri += 1;
            }
        }

        return sqPeri;
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int perimeter = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    perimeter += check(grid, i, j);
                }
            }
        }

        return perimeter;
    }
};