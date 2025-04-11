class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<char, int> row[9];
        unordered_map<char, int> col[9];
        unordered_map<char, int> submatrix[9];

        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                char curr = board[i][j];

                if( curr == '.') continue;

                // Row check
                row[i][curr]++;
                if( row[i][curr] > 1){
                    return false;
                }

                // column check
                col[j][curr]++;
                if( col[j][curr] > 1){
                    return false;
                }

                // sub matrix check
                int k = (i / 3) * 3 + (j / 3);
                submatrix[k][curr]++;
                if( submatrix[k][curr] > 1){
                    return false;
                }
            }
        }
        return true;
    }
};