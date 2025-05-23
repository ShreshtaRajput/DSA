/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
private:
    void solve(TreeNode* root, int value, int& sum) {
        // BASE CASE
        if (root == NULL) {
            return;
        }

        value = value * 10 + root->val;

        if (root->left == NULL && root->right == NULL) {
            sum += value;
            return;
        }

        solve(root->left, value, sum);
        solve(root->right, value, sum);
    }

public:
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        int curr = 0;

        solve(root, curr, sum);

        return sum;
    }
};