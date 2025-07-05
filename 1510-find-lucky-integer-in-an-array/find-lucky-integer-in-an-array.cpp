class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int, int> mp;

        for(int i = 0; i < arr.size(); i++){
            mp[arr[i]]++;
        }

        int equal_freq = -1;

        for(auto p: mp){
            if(p.first == p.second){
                equal_freq = p.first;
            }
        }

        return equal_freq;
    }
};