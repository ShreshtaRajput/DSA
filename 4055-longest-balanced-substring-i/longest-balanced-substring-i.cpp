class Solution {
public:
    int longestBalanced(string s) {
        int maxLen = INT_MIN;
        int n = s.size();

        for(int i = 0; i < n; i++){
            vector<int> freq(26);
            int distinct = 0;
            int maxFreq = 0;

            for(int j = i; j < n; j++){
                int index = s[j] - 'a';
                
                if(freq[index] == 0){   //New element has appeared
                    distinct++;
                }

                freq[index]++;
                maxFreq = max(maxFreq, freq[index]);

                int len = j-i+1;
                if(len == distinct * maxFreq){
                    maxLen = max(maxLen, len);
                }
            }
        }

        return maxLen;
    }
};

// class Solution {
// public:
//     int longestBalanced(string s) {
//         int maxLen = INT_MIN;
        
//         for(int i = 0; i < s.size(); i++){
//             unordered_map<char, int> mp;
//             for(int j = i; j < s.size(); j++){
//                 mp[s[j]]++;

//                 int freq = mp[s[j]];
//                 bool flag = true;

//                 for(auto p: mp){
//                     if(freq != p.second){
//                         // Frequency not equal
//                         flag = false;
//                     }
//                 }

//                 if(flag){
//                     maxLen = max(maxLen, j-i+1);
//                 }
//             }
//         }

//         return maxLen;
//     }
// };