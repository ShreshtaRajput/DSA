class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.rbegin(), prices.rend());
        sort(discounts.rbegin(), discounts.rend());

        int n = min(discounts.size(), prices.size());

        double res = 0;

        for(int i = 0; i < n; i++){
            res += ((double)prices[i] * (100 - discounts[i]))/100;
        }

        for(int i = n; i < prices.size(); i++){
            res += prices[i];
        }

        return res;
    }
};