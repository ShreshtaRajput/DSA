class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res;

        if(n == 1) return {0};

        for(int i = 1; i <= n/2; i++){
            res.push_back(i);
            res.push_back(-i);
        }

        if(n % 2 == 1){
            // If odd
            res.push_back(0);
        }

        return res;
    }
};