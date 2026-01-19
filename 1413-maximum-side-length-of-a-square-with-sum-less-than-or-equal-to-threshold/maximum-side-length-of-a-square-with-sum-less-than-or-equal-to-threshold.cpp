class Solution {
// private:
//     int getSum(int r, int c, int k, vector<vector<int>> &ps){
//         return ps[r+k-1][c+k-1] - ps[r-1][c+k-1] - ps[r+k-1][c-1] + ps[r-1][c-1];
//     }
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> ps(n + 1, vector<int>(m + 1, 0));

        // Build prefix sum
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                ps[i][j] = mat[i - 1][j - 1] + ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1];
            }
        }

        int res = 0;

        // Binary search optimization
        int low = 0;
        int high = min(n, m);

        while(low <= high){
            int mid = low + (high - low)/2;
            bool valid = false;

            for(int i = mid; i <= n; i++){
                for(int j = mid; j <= m; j++){
                    int sum = ps[i][j] - ps[i-mid][j] - ps[i][j-mid] + ps[i-mid][j-mid];

                    if(sum <= threshold){
                        valid = true;
                        break;
                    }
                }
                if(valid) break;
            }

            if(valid){
                res = mid;
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        
        // Check for a kxk matrix
        // for(int k = 1; k <= min(n, m); k++){
        //     int sum = 0;
        //     for(int i = 1; i <= n - k + 1; i++){
        //         for(int j = 1; j <= m - k + 1; j++){
        //             sum = getSum(i, j, k, ps);

        //             if(sum <= threshold){
        //                 res = k;
        //             }
        //         }
        //     }
        // }

        return res;
    }
};