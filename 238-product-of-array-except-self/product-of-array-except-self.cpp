class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res;

        int n = nums.size();
        vector<int> prefixProd(n, 1);
        vector<int> suffixProd(n, 1);

        prefixProd[0] = nums[0];
        for(int i = 1; i < n; i++){
            prefixProd[i] = prefixProd[i - 1] * nums[i];
        }

        suffixProd[n-1] = nums[n-1];
        for(int i = n-2; i >= 0; i--){
            suffixProd[i] = suffixProd[i + 1] * nums[i];
        }

        for(int i = 0; i < n; i++){
            if(i == 0){
                res.push_back(suffixProd[i + 1]);
            }
            if(i == n-1){
                res.push_back(prefixProd[i-1]);
            }

            if(i != 0 && i != n-1){
                res.push_back(prefixProd[i-1] * suffixProd[i+1]);
            }
        }

        return res;
    }
};