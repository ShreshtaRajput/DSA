class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int minPrice = prices[0];

        for(int i = 0; i < prices.size(); i++){
            if( minPrice > prices[i] ){
                minPrice = prices[i];
            }else{
                profit = max(profit, prices[i] - minPrice);
            }
        }

        return profit;
    }
};