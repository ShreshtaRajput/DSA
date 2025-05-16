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
    int height(TreeNode* root){
        if(root == NULL){
            return 0;
        }

        int lheight = height(root -> left);
        int rheight = height(root -> right);

        return max(lheight, rheight) + 1;
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL){
            return 0;
        }

        int op1 = diameterOfBinaryTree(root -> left);
        int op2 = diameterOfBinaryTree(root -> right);
        int op3 = height(root -> left) + height(root -> right);

        return max(op1, max(op2, op3));
    }
};

// pair<int, int> diameter(TreeNode* root) {
//     // Base case
//     if (root == NULL) {
//         pair<int, int> p = make_pair(0, 0);
//         return p;
//     }

//     pair<int, int> left = diameter(root->left);
//     pair<int, int> right = diameter(root->right);

//     int op1 = left.first;
//     int op2 = right.first;
//     int op3 = left.second + right.second;

//     pair<int, int> ans;
//     ans.first = max(op1, max(op2, op3));
//     ans.second = max(left.second, right.second) + 1;

//     return ans;
// }
// int diameterOfBinaryTree(TreeNode* root) {
//     pair<int, int> dia = diameter(root);

//     return dia.first;
// }