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
    void createMapping(map<int, int>& inorderToIndex, vector<int> inorder,
                       int n) {
        for (int i = 0; i < n; i++) {
            inorderToIndex[inorder[i]] = i;
        }
    }

    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int& index,
                    int inorderStart, int inorderEnd, int n,
                    map<int, int> &inorderToIndex) {
        if (index >= n || inorderStart > inorderEnd) {
            return NULL;
        }

        int element = preorder[index++];
        TreeNode* root = new TreeNode(element);

        int position = inorderToIndex[element];

        root->left = solve(preorder, inorder, index, inorderStart, position - 1,
                           n, inorderToIndex);
        root->right = solve(preorder, inorder, index, position + 1, inorderEnd,
                            n, inorderToIndex);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index = 0;
        map<int, int> inorderToIndex;
        int n = inorder.size();

        createMapping(inorderToIndex, inorder, n);

        TreeNode* ans =
            solve(preorder, inorder, index, 0, n - 1, n, inorderToIndex);

        return ans;
    }
};