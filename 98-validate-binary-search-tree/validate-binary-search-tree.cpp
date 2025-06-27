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
    // Inorder traversal is always sorted for BST
private:
    vector<int> getInorder(TreeNode* root, vector<int> &ans){
        if(root == NULL){
            return ans;
        }

        getInorder(root -> left, ans);
        ans.push_back(root -> val);
        getInorder(root -> right, ans);

        return ans;
    }
public:
    bool isValidBST(TreeNode* root) {
        vector<int> inorder;
        getInorder(root, inorder);

        for(int i = 0; i < inorder.size() - 1; i++){
            if(inorder[i] >= inorder[i + 1]){
                return false;
            }
        }

        return true;
    }
};