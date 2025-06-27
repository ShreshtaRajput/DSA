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
    bool findTarget(TreeNode* root, int k) {
        vector<int> inorder;
        getInorder(root, inorder);

        int i = 0;
        int j = inorder.size() - 1;
        while(i < j){
            int value = inorder[i] + inorder[j];
            if(value == k){
                return true;
            }else if(value > k){
                j--;
            }else{
                i++;
            }
        }

        return false;
    }
};