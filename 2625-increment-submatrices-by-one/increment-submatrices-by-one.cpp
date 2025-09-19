class Solution {
private:
    void convertMatrix(vector<vector<int>> &res, int initRow, int initCol, int finalRow, int finalCol){
        for(int i = initRow; i <= finalRow; i++){
            for(int j = initCol; j <= finalCol; j++){
                res[i][j] += 1;
            }
        }
    }
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        int m = queries.size();

        vector<vector<int>> res(n, vector<int>(n, 0));

        for(int i = 0; i < m; i++){
            convertMatrix(res, queries[i][0], queries[i][1], queries[i][2], queries[i][3]);
        }

        return res;
    }
};