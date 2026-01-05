class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long res = 0;
        int minAbsVal = INT_MAX;
        int negativeCount = 0;

        for(auto &row: matrix){
            for(int val: row){
                res += abs(val);
                if(val < 0){
                    negativeCount++;
                }

                minAbsVal = min(minAbsVal, abs(val));
            }
        }

        if(negativeCount % 2 != 0){
            res -= 2 * minAbsVal;
        }

        return res;
    }
};