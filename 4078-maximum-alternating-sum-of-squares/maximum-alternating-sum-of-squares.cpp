#define LL long long

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            nums[i] = nums[i] * nums[i];
        }
        sort(nums.begin(), nums.end());
        vector<LL> res;

        int n = nums.size();
        int i = 0;
        int j = n - 1;

        while(i <= j){
            if(i == j){
                res.push_back(nums[i]);
                break;
            }

            res.push_back(nums[j]);
            res.push_back(nums[i]);
            i++;
            j--;
        }

        LL sum = 0;

        for(int k = 0; k < n; k++){
            if(k % 2 == 0) sum += res[k];
            else sum -= res[k];
        }

        return sum;
    }
};