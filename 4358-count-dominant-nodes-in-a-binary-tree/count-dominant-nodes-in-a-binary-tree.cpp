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
    int solve(TreeNode* root, int &res){
        if(root == NULL) return INT_MIN;
        if(root -> left == NULL && root -> right == NULL){
            // Leaf node
            res++;
            return root -> val;
        }

        int left = solve(root -> left, res);
        int right = solve(root -> right, res);

        if(root -> val >= left && root -> val >= right){
            // Current node is dominant
            res++;
        }

        return max(root -> val, max(left, right));
    }

public:
    int countDominantNodes(TreeNode* root) {
        int res = 0;
        solve(root, res);
        return res;
    }
};