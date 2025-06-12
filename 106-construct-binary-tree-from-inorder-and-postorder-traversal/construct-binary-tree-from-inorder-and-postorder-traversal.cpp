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

    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int& index,
                    int inorderStart, int inorderEnd, int n,
                    map<int, int>& inorderToIndex) {
        // Base case
        if (index < 0 || inorderStart > inorderEnd) {
            return NULL;
        }

        // Get the root element from postorder
        int element = postorder[index--];
        TreeNode* root = new TreeNode(element);

        // Find the element in inorder
        int position = inorderToIndex[element];

        // Recursive calls
        root->right = solve(inorder, postorder, index, position + 1, inorderEnd,
                            n, inorderToIndex);
        root->left = solve(inorder, postorder, index, inorderStart,
                           position - 1, n, inorderToIndex);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        int postOrderIndex = n - 1;
        map<int, int> inorderToIndex;

        createMapping(inorderToIndex, inorder, n);

        TreeNode* ans = solve(inorder, postorder, postOrderIndex, 0, n - 1, n, inorderToIndex);

        return ans;
    }
};