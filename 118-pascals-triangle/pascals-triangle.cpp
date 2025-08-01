class Solution {
private:
    // Calculate the combination
    long long nCr(int n, int r) {
        if (r > n){
            return 0;
        }
        if (r > n - r){
            r = n - r;
        }
        long long res = 1;
        for (int i = 0; i < r; i++) {
            res *= (n - i);
            res /= (i + 1);
        }
        return res;
    }

public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;

        for (int i = 0; i < numRows; i++) {
            vector<int> row;
            for (int j = 0; j <= i; j++) {
                // Append the combination for each element of each row
                // basic Pascal's triangle formula
                row.push_back(nCr(i, j));
            }

            res.push_back(row);
        }

        return res;
    }
};

// Helper function to calculate factorial for nCr
// long long fact(int n){
//     if(n < 0){
//         return -1;
//     }
//     if(n == 0 || n == 1){
//         return 1;
//     }
//     return n * fact(n - 1);
// }