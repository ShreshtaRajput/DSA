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
    void dfs(TreeNode* root, int &res, string temp){
        if(!root){
            return;
        }

        temp += (root -> val + '0');

        // If we reach the leaf node, our current path is complete
        // We can add that number to result
        if(root -> left == NULL && root -> right == NULL){
            res += stoi(temp, NULL, 2);
        }

        if(root -> left){
            dfs(root -> left, res, temp);
        }
        if(root -> right){
            dfs(root -> right, res, temp);
        }
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        int res = 0;
        string temp = "";

        dfs(root, res, temp);

        return res;
    }
};