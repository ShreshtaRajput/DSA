/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void solve(TreeNode* root, vector<vector<int>> &ans, int targetSum, vector<int> currPath){
        int tempSum = 0;
        // Base case
        if(root == NULL){
            return;
        }

        currPath.push_back(root -> val);

        for(int i = 0; i < currPath.size(); i++){
            tempSum += currPath[i];
        }

        if(tempSum == targetSum && root -> left == NULL && root -> right == NULL){
            ans.push_back(currPath);
        }

        solve(root -> left, ans, targetSum, currPath);
        solve(root -> right, ans, targetSum, currPath);

        currPath.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> currPath;

        solve(root, ans, targetSum, currPath);

        return ans;
    }
};