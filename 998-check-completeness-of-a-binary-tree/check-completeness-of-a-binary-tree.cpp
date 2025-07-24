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
    int countNodes(TreeNode* root){
        if(root == NULL){
            return 0;
        }

        int ans = 1 + countNodes(root -> left) + countNodes(root -> right);

        return ans;
    }

    bool isCBT(TreeNode* root, int index, int totalNodes){
        if(root == NULL){
            return true;
        }

        if(index >= totalNodes){
            return false;
        }

        bool leftChild = isCBT(root -> left, 2*index + 1, totalNodes);
        bool rightChild = isCBT(root -> right, 2*index + 2, totalNodes);

        return leftChild && rightChild;
    }

public:
    bool isCompleteTree(TreeNode* root) {
        if(root == NULL){
            return NULL;
        }

        int index = 0;
        int totalNodes = countNodes(root);
        return isCBT(root, index, totalNodes);
    }
};