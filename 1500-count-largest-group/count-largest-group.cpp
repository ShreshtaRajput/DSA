class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int, int> mp;
        for(int i = 1; i <= n; ++i){
            int sum = 0;
            int temp = i;
            while(temp != 0){
                sum += temp % 10;
                temp /= 10;
            }
            mp[sum]++;
        }

        int maxGroup = 0;
        for(auto& i:mp){
            maxGroup = max(maxGroup, i.second);
        }

        int count = 0;
        for(auto& i: mp){
            if(i.second == maxGroup){
                count++;
            }
        }
        return count;
    }
};