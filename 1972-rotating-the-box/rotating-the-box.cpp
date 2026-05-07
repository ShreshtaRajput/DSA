class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int n = boxGrid.size();
        int m = boxGrid[0].size();

        vector<vector<char>> res(m, vector<char>(n));

        for(int i = n-1; i >= 0; i--){
            int lastPos = m-1;
            for(int j = m-1; j >= 0; j--){
                // If obstacle
                if(boxGrid[i][j] == '*'){
                    lastPos = j-1;
                }

                // Simulate gravity for stones
                else if(boxGrid[i][j] == '#'){
                    boxGrid[i][j] = '.';    //Convert to empty space
                    boxGrid[i][lastPos] = '#';  //Stone falls to last empty position
                    lastPos--;      //Update last position
                }
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                res[i][j] = boxGrid[n-1-j][i];
            }
        }

        return res;
    }
};