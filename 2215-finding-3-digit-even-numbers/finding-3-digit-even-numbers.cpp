class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> res;
        int added[1000] = {false};
        int n = digits.size();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                for(int k = 0; k < n; k++){
                    // Leading cannot be zero
                    if(digits[i] == 0){
                        continue;
                    }
                    // Same index wale chhod do
                    if(i == j || j == k || k == i){
                        continue;
                    }

                    int num = digits[i]*100 + digits[j]*10 + digits[k];
                    if(num % 2 == 0 && added[num] != true){
                        res.push_back(num);
                        added[num] = true;
                    }
                }
            }
        }

        sort(res.begin(), res.end());
        return res;
    }
};