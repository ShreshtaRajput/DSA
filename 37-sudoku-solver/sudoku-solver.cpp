class Solution {
private:
    bool isValid(int row, int col, vector<vector<char>>& board, char val){
        for(int i = 0; i < board.size(); i++){
            // row check
            if(board[row][i] == val){
                return false;
            }

            // col check
            if(board[i][col] == val){
                return false;
            }

            // sub-matrix check
            if(board[3*(row/3) + i/3][3*(col/3) + i%3] == val){
                return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        for(int row = 0; row < 9; row++){
            for(int col = 0; col < 9; col++){
                if(board[row][col] == '.'){
                    for(char i = '1'; i <= '9'; i++){
                        if(isValid(row, col, board, i)){
                            board[row][col] = i;

                            if(solve(board)){
                                return true;
                            }

                            // Backtrack
                            board[row][col] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};