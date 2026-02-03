class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int turns = 0;

        int n = nums.size();
        int i = 1;

        if(n < 4) return false;

        while(i < n && nums[i-1] < nums[i]){
            i++;
        }

        int p = i-1;
        if(p == 0) return false;
        
        while(i < n && nums[i-1] > nums[i]){
            i++;
        }

        int q = i-1;
        if(q == p) return false;

        while(i < n && nums[i-1] < nums[i]){
            i++;
        }

        return q < n - 1 && i == n;
    }
};