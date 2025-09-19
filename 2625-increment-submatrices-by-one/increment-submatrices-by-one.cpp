class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        // Trying the prefix sum approach
        // Defining the difference array<
        vector<vector<int>> diff(n, vector<int>(n, 0));

        // Pre-processing the queries in the diff matrix
        for(int i = 0; i < queries.size(); i++){
            int r1 = queries[i][0]; int c1 = queries[i][1];
            int r2 = queries[i][2]; int c2 = queries[i][3];

            diff[r1][c1] += 1;
            if(c2 + 1 < n) diff[r1][c2 + 1] -= 1;
            if(r2 + 1 < n) diff[r2 + 1][c1] -= 1;
            if(r2 + 1 < n && c2 + 1 < n) diff[r2 + 1][c2 + 1] += 1;
        }

        //Compute the prefix sum for each row
        for(int i = 0; i < n; i++){
            for(int j = 1; j < n; j++){
                diff[i][j] += diff[i][j-1];
            }
        }

        // Compute the prefix sum for each col
        for(int i = 1; i < n; i++){
            for(int j = 0; j < n; j++){
                diff[i][j] += diff[i-1][j];
            }
        }

        return diff;
    }
};


// class Solution {
// private:
//     void convertMatrix(vector<vector<int>> &res, int initRow, int initCol, int finalRow, int finalCol){
//         for(int i = initRow; i <= finalRow; i++){
//             for(int j = initCol; j <= finalCol; j++){
//                 res[i][j] += 1;
//             }
//         }
//     }
// public:
//     vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
//         int m = queries.size();

//         vector<vector<int>> res(n, vector<int>(n, 0));

//         for(int i = 0; i < m; i++){
//             convertMatrix(res, queries[i][0], queries[i][1], queries[i][2], queries[i][3]);
//         }

//         return res;
//     }
// };