class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;

        for(auto num: nums){
            if(num == 1) cnt++;
        }

        if(cnt > 0) return n - cnt;

        int g = nums[0];
        for(int i = 1; i < nums.size(); i++){
            g = gcd(g, nums[i]);
        }
        if(g > 1) return -1;    //Impossible case => if overall gcd > 1

        // Find shortest subarray with gcd = 1
        int minLen = INT_MAX;
        for(int i = 0; i < n; i++){
            int currG = nums[i];
            for(int j = i+1; j < n; j++){
                currG = gcd(currG, nums[j]);
                if(currG == 1){
                    minLen = min(minLen, j-i+1);
                    break;
                }
            }
        }

        return (minLen - 1) + (n - 1);
    }
};