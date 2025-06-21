class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char, int> mp;
        int ans = INT_MAX;

        for(char ch: word){
            mp[ch]++;
        }

        vector<int> freqList;
        for(auto& freq: mp){
            freqList.push_back(freq.second);
        }

        sort(freqList.begin(), freqList.end());

        for(int freq: freqList){
            int deletions = 0;
            for(int i = 0; i < freqList.size(); i++){
                if(freqList[i] < freq){
                    deletions += freqList[i];
                }else if(freqList[i] > freq + k){
                    deletions += (freqList[i] - (freq + k));
                }
            }

            ans = min(ans, deletions);
        }

        return ans;
    }
};