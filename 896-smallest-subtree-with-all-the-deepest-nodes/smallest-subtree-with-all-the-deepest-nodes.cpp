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
    int findMaxDepth(TreeNode* node){
        if(node == NULL){
            return 0;
        }

        int  ldepth = findMaxDepth(node -> left);
        int rdepth = findMaxDepth(node -> right);

        return max(ldepth, rdepth) + 1;
    }

    TreeNode* dfs(TreeNode* node, int currDepth, int maxDepth){
        if(node == NULL) return NULL;

        if(currDepth == maxDepth - 1){
            if(node -> right == NULL){
                return node -> left;
            }else if(node -> left == NULL){
                return node -> right;
            }else{
                return node;
            }
        };

        if(currDepth == maxDepth) return node;

        TreeNode* left = dfs(node->left, currDepth + 1, maxDepth);
        TreeNode* right = dfs(node->right, currDepth + 1, maxDepth);

        if (left && right) return node;
        return left ? left : right;
    }

public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int maxDepth = findMaxDepth(root);

        return dfs(root, 1, maxDepth);
    }
};