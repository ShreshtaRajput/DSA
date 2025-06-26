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
    TreeNode* minVal(TreeNode* root){
        TreeNode* curr = root;
        while(curr -> left != NULL){
            curr = curr -> left;
        }
        return curr;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL){
            return root;
        }

        if(root -> val == key){
            // 0 child
            if(root -> left == NULL && root -> right == NULL){
                delete root;
                return NULL;
            }

            // Single child - left
            if(root -> left != NULL && root -> right == NULL){
                TreeNode* temp = root -> left;
                delete root;
                return temp;
            }

            // Single child - right
            if(root -> right != NULL && root -> left == NULL){
                TreeNode* temp = root -> right;
                delete root;
                return temp;
            }

            // Two children
            if(root -> left != NULL && root -> right != NULL){
                int mini = minVal(root -> right) -> val;
                root -> val = mini;
                root -> right = deleteNode(root -> right, mini);
                return root;
            }
        }else if(root -> val > key){
            root -> left = deleteNode(root -> left, key);
        }else{
            root -> right = deleteNode(root -> right, key);
        }

        return root;
    }
};