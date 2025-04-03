class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int colLen = matrix.size();
        int rowLen = matrix[0].size();

        vector<vector<int>> temp = matrix;

        for(int i = 0; i < colLen; i++){
            for(int j = 0; j < rowLen; j++){
                if(temp[i][j] == 0){
                    for(int k = 0; k < rowLen; k++){
                        matrix[i][k] = 0;
                    }

                    for(int m = 0; m < colLen; m++){
                        matrix[m][j] = 0;
                    }
                }
            }
        }
    }
};