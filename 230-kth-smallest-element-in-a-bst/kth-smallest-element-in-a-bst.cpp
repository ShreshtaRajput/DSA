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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> inorder;
        getInorder(root, inorder);

        for(int i = 0; i < inorder.size(); i++){
            return inorder[k - 1];
        }

        return -1;
    }
};