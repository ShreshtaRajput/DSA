class NumMatrix {
private:
    // An easy question with too much indexing and edge case bullshit to deal with
    int row, col;
    vector<vector<int>> prefixMatrix;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        row = matrix.size();
        col = matrix[0].size();

        prefixMatrix.resize(row + 1);
        for (auto& r : prefixMatrix) {
            r.resize(col + 1, 0);
        }

        for (int i = 1; i <= row; i++) {
            for (int j = 1; j <= col; j++) {
                prefixMatrix[i][j] =
                    matrix[i - 1][j - 1] + prefixMatrix[i - 1][j] +
                    prefixMatrix[i][j - 1] - prefixMatrix[i - 1][j - 1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return prefixMatrix[row2 + 1][col2 + 1] - prefixMatrix[row2 + 1][col1] -
               prefixMatrix[row1][col2 + 1] + prefixMatrix[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */