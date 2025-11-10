class Solution {
public:
    int minOperations(vector<int>& nums) {
        vector<int> s;
        int res = 0;
        for (int a : nums) {
            while (!s.empty() && s.back() > a) {
                s.pop_back();
            }
            if (a == 0) continue;
            if (s.empty() || s.back() < a) {
                res++;
                s.push_back(a);
            }
        }
        return res;
    }
};

// class Solution {
// public:
//     int minOperations(vector<int>& nums) {
//         map<int, vector<int>> mp;

//         for(int i = 0; i < nums.size(); i++){
//             if(nums[i] > 0){
//                 mp[nums[i]].push_back(i);
//             }
//         }

//         int res = 0;

//         for(auto p: mp){
//             int val = p.first;
//             vector<int> indices = p.second;

//             res++;
//             int prev_ind = indices[0];

//             for(int i = 1; i < indices.size(); i++){
//                 int curr_index = indices[i];

//                 bool is_disconnected = false;
//                 for (int k = prev_ind + 1; k < curr_index; ++k) {
//                     if (nums[k] < val) {
//                         is_disconnected = true;
//                         break;
//                     }
//                 }

//                 if (is_disconnected) {
//                     res++;
//                 }

//                 prev_ind = curr_index;
//             }
//         }

//         return res;
//     }
// };