class Solution {
private:
    int onesToRight(int r, int c, int rows, int cols, vector<vector<char>> &matrix){
        if(r >= rows || c >= cols || matrix[r][c] == '0'){
            return 0;
        }

        return 1 + onesToRight(r, c+1, rows, cols, matrix);
    }

    int maxAreaFrom(int r, int c, int rows, int cols, vector<vector<char>> &matrix){
        if(r >= rows || c >= cols || matrix[r][c] == '0'){
            return 0;
        }

        int minWidth = cols;
        int maxArea = 0;

        for(int i = r; i < rows && matrix[i][c] == '1'; i++){
            int width = onesToRight(i, c, rows, cols, matrix);
            minWidth = min(minWidth, width);

            int height = i - r + 1;
            maxArea = max(maxArea, (height * minWidth));
        }

        return maxArea;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int maxArea = 0;

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                maxArea = max(maxArea, maxAreaFrom(i, j, rows, cols, matrix));
            }
        }

        return maxArea;
    }
};