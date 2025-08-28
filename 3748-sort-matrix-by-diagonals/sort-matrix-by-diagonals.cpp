class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        
        // For lower triangle (including main diagonal)
        for(int i = 0; i < n; i++){
            vector<int> temp;
            int k = i, m = 0;   // start from top row, column i
            while(k < n && m < n){
                temp.push_back(grid[k][m]);
                k++; m++;
            }

            sort(temp.begin(), temp.end()); // non-increasing
            reverse(temp.begin(), temp.end());

            k = i, m = 0;
            int idx = 0;
            while(k < n && m < n){
                grid[k][m] = temp[idx++];
                k++; m++;
            }
        }

        // For upper triangle (excluding main diagonal)
        for(int i = 1; i < n; i++){   // start from row i, col 0
            vector<int> temp;
            int k = 0, m = i;
            while(k < n && m < n){
                temp.push_back(grid[k][m]);
                k++; m++;
            }

            sort(temp.begin(), temp.end()); // non-decreasing

            k = 0, m = i;
            int idx = 0;
            while(k < n && m < n){
                grid[k][m] = temp[idx++];
                k++; m++;
            }
        }

        return grid;
    }
};
