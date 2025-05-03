class Solution {
private:
    void combination(int idx, int target, vector<int>& arr, vector<vector<int>>& ans, vector<int>& combo){
        // Base case
        if(target == 0){
            ans.push_back(combo);
            return;
        }
        for(int i = idx; i < arr.size(); i++){
            // To avoid duplicate combos
            if(i > idx && arr[i] == arr[i - 1]){
                continue;
            }

            // Out of range numbers
            if(arr[i] > target){
                break;
            }
            combo.push_back(arr[i]);
            // Making combinations for arr[i] to equate the target
            combination(i + 1, target - arr[i], arr, ans, combo);
            // Back track
            combo.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> combo;

        combination(0, target, candidates, ans, combo);

        return ans;
    }
};