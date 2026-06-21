class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int res = 0;
        sort(costs.begin(), costs.end());

        for(auto cost: costs){
            if(cost <= coins){
                res++;
                coins -= cost;
            }
        }

        return res;
    }
};