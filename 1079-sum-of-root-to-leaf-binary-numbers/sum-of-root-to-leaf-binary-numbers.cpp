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
    void dfs(TreeNode* root, int &res, int curr){
        if(!root){
            return;
        }

        curr = curr * 2 + root -> val;

        // If we reach the leaf node, our current path is complete
        // We can add that number to result
        if(root -> left == NULL && root -> right == NULL){
            res += curr;
        }

        if(root -> left){
            dfs(root -> left, res, curr);
        }
        if(root -> right){
            dfs(root -> right, res, curr);
        }
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        int res = 0;
        int curr = 0;

        dfs(root, res, curr);

        return res;
    }
};