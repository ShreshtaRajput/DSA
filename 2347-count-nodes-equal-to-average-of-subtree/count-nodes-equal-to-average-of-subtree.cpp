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
    pair<int, int> solve(TreeNode* root, int &ans){
        if(!root) return {0,0};
        
        // If leaf node -> it is guaranteed a required node
        if(!root -> left && !root -> right){
            ans++;  
            return {root -> val, 1};
        }

        pair<int, int> leftTree = solve(root -> left, ans);
        pair<int, int> rightTree = solve(root -> right, ans);

        int sum = leftTree.first + rightTree.first + root -> val;
        int n = leftTree.second + rightTree.second + 1;
        if(sum/n == root -> val){
            ans++;
        }

        return {sum, n};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        pair<int, int> currTree = solve(root, ans);
        return ans;
    }
};