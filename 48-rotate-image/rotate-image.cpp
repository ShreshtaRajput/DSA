class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        // Transposing the matrix
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if( j > i){
                    swap(matrix[i][j],matrix[j][i]);
                }
            }
        }

        // Reversing the matrix
        int start = 0;
        int end = col - 1 - start;
        while (start < end) {
            for (int j = 0; j <= row - 1; j++) {
                swap(matrix[j][start], matrix[j][end]);
            }
            start++;
            end--;
        }
    }
};