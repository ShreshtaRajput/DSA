class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        // By using concept of difference array
        vector<int> differenceArr(nums.size() + 1, 0);

        for(auto& query: queries){
            int left = query[0];
            int right = query[1];
            differenceArr[left] += 1;
            differenceArr[right + 1] -= 1;
        }

        vector<int> cummulativeOperations;
        int cumSum = 0;
        for(auto operation: differenceArr){
            cumSum += operation;
            cummulativeOperations.push_back(cumSum);
        }

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > cummulativeOperations[i]){
                return false;
            }
        }

        return true;
    }
};

// BRUTE FORCE
/*for (int i = 0; i < queries.size(); i++) {
    for (int j = queries[i][0]; j <= queries[i][1]; j++) {
        if (nums[j] > 0)
            nums[j] = nums[j] - 1;
    }
}

for (int k = 0; k < nums.size(); k++) {
    if (nums[k] != 0) {
        return false;
    }
}

return true;*/