class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> aux(n, vector<int>(m));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j] == 1){
                    if(i == 0 || j == 0){
                    aux[i][j] = matrix[i][j];
                    }else{
                        aux[i][j] = 1 + min(aux[i-1][j], min(aux[i-1][j-1], aux[i][j-1]));
                    }
                }
            }
        }

        int sum = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                sum += aux[i][j];
            }
        }

        return sum;
    }
};