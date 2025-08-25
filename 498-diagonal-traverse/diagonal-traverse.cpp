class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;

        int m = mat.size();
        int n = mat[0].size();

        // total number of diagonals are m + n - 1
        for (int d = 0; d < m + n - 1; d++) {
            int row = 0;
            int col = 0;
            vector<int> temp;
            if (d < n) {
                //if d is less than the number of columns, then it will be like (0,d)
                col = d;
            } else {
                // else we use this structure
                row = d - n + 1;
                col = n - 1;
            }
            // While we are in the range
            while (row < m && col >= 0) {
                // Push to temp vector
                temp.push_back(mat[row][col]);
                // This is for diagonal traversal in down-left direction
                row += 1;   //increment the row
                col -= 1;   //decrement the col
            }

            // If d is even, we will have to move up-right, so we reverse the temp vector
            if (d % 2 == 0) {
                reverse(temp.begin(), temp.end());
            }
            // Push the elements of temp in ans array
            for (auto it : temp) {
                ans.push_back(it);
            }
        }

        return ans;
    }
};