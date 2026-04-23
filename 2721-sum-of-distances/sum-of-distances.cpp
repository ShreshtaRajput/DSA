class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> res(n);
        unordered_map<int, vector<int>> mp;

        for(int i = 0; i < n; i++){
            mp[nums[i]].push_back(i);
        }

        for(auto p: mp){
            vector<int> indices = p.second;
            int k = indices.size();

            if(k < 2){
                continue;
            }

            // prefix sum of indices
            vector<long long> prefix(k, 0);
            prefix[0] = indices[0];
            for(int i = 1; i < k; i++){
                prefix[i] = prefix[i-1] + indices[i];
            }

            for(int i = 0; i < k; i++){
                long long left = 0, right = 0;

                // contribution from left side
                if(i > 0){
                    left = (long long)i * indices[i] - prefix[i-1];
                }

                // contribution from right side
                if(i < k-1){
                    right = (prefix[k-1] - prefix[i]) - (long long)(k-i-1) * indices[i];
                }

                res[indices[i]] = left + right;
            }

            // for(int i = 0; i < indices.size(); i++){
            //     long long ele = 0;
            //     for(int j = 0; j < indices.size(); j++){
            //         if(i != j){
            //             ele += abs(indices[i]-indices[j]);
            //         }
            //     }

            //     res[indices[i]] = ele;
            // }
        }

        return res;
    }
};