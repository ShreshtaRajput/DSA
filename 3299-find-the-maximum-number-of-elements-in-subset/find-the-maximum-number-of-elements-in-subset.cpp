class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int res = 0;
        unordered_map<int, int> mp;

        // Build the map
        for(auto num: nums){
            mp[num]++;
        }

        // Handle the case for 1
        if(mp.count(1)){
            if(mp[1] % 2 == 0){
                res = mp[1] - 1;
            }else{
                res = mp[1];
            }
        }

        for(auto p: mp){
            int num = p.first;

            if(num == 1) continue;

            long long curr = num;
            int len = 0;

            while(curr <= 1e9 && mp.count(curr) && mp[curr] >= 2){
                len += 2;
                curr *= curr;
            }
            if(curr <= 1e9 && mp.count(curr) && mp[curr] == 1){
                len++;
            }else{
                len--;
            }

            res = max(res, len);
        }

        return res;
    }
};

// class Solution {
// public:
//     int maximumLength(vector<int>& nums) {
//         int res = 0;
//         unordered_map<int, int> mp;

//         for (int num : nums) {
//             mp[num]++;
//         }

//         // Handle the base case for 1
//         if (mp.count(1)) {
//             res = (mp[1] % 2 == 0) ? mp[1] - 1 : mp[1];
//         }

//         for (auto& [num, freq] : mp) {
//             if (num == 1) continue;

//             long long curr = num;
//             int len = 0;

//             // 1. Check bounds FIRST to prevent int truncation
//             // 2. Use .count() so missing keys are NEVER inserted
//             while (curr <= 1e9 && mp.count(curr) && mp[curr] >= 2) {
//                 len += 2;
//                 curr *= curr;
//             }

//             if (curr <= 1e9 && mp.count(curr) && mp[curr] == 1) {
//                 len++;
//             } else {
//                 len--;
//             }

//             res = max(res, len);
//         }

//         return res;
//     }
// };