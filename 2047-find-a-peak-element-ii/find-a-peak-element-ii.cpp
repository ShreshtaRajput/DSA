class Solution {
private:
    bool valid(vector<vector<int>> &mat, int i, int j){
        int n = mat.size();
        int m = mat[0].size();

        int curr = mat[i][j];

        // Up
        if (i > 0 && mat[i - 1][j] >= curr) return false;

        // Down
        if (i < n - 1 && mat[i + 1][j] >= curr) return false;

        // Left
        if (j > 0 && mat[i][j - 1] >= curr) return false;

        // Right
        if (j < m - 1 && mat[i][j + 1] >= curr) return false;

        return true;
    }
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        vector<int> res;

        int n = mat.size();
        int m = mat[0].size();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(valid(mat, i, j)){
                    return {i, j};
                }
            }
        }

        return {-1, -1};
    }
};