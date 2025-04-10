class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> mp;

        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
        }

        // getting the maximum frequency
        int maxFreq = 0;
        for(auto& i: mp){
            maxFreq = max(i.second, maxFreq);
        }

        int count = 0;
        for(auto& i: mp){
            if(i.second == maxFreq){
                count+=maxFreq;
            }
        }
        return count;
    }
};