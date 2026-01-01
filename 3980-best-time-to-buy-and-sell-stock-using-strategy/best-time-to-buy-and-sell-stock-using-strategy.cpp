class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        vector<long long> profitSum(n+1);
        vector<long long> priceSum(n+1);

        for(int i = 0; i < n; i++){
            profitSum[i+1] = (prices[i] * strategy[i]) + profitSum[i];
            priceSum[i+1] = prices[i] + priceSum[i];
        }

        long long res = profitSum[n];

        for(int i = k-1; i < n; i++){
            // Profit from BEFORE the window (unchanged)
            long long left = profitSum[i-k+1];
            // Profit from AFTER the window (unchanged)
            long long right = profitSum[n] - profitSum[i+1];
            // Profit INSIDE the modified window
            long long window = priceSum[i+1] - priceSum[i-k/2+1];

            res = max(res, left + right + window);
        }

        return res;
    }
};