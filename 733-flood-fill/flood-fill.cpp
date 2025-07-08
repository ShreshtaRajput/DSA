class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& ans,
             vector<vector<int>>& image, vector<int> delRow,
             vector<int>& delCol, int color, int iniColor) {
        ans[row][col] = color;
        int n = image.size();
        int m = image[0].size();
        for (int i = 0; i < 4; i++) {
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];
            if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m &&
                image[nRow][nCol] == iniColor && ans[nRow][nCol] != color) {
                dfs(nRow, nCol, ans, image, delRow, delCol, color, iniColor);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        vector<vector<int>> ans = image;
        int iniColor = image[sr][sc];

        vector<int> delRow = {-1, 0, 1, 0};
        vector<int> delCol = {0, 1, 0, -1};

        dfs(sr, sc, ans, image, delRow, delCol, color, iniColor);

        return ans;
    }
};