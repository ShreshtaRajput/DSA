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
    void getInorder(TreeNode* root, vector<int>& ans) {
        if (root == NULL) {
            return;
        }

        getInorder(root->left, ans);
        ans.push_back(root->val);
        getInorder(root->right, ans);
    }

    // Inorder again to updates nodes in sorted array
    void inorderAgain(TreeNode*& root, vector<int>& in, int& index) {
        if (root == NULL) {
            return;
        }

        inorderAgain(root->left, in, index);
        root->val = in[index];
        index++;
        inorderAgain(root->right, in, index);
    }

    void inorder(TreeNode*& root, TreeNode*& first, TreeNode*& middle, TreeNode*& prev) {
        if (root == NULL) {
            return;
        }

        inorder(root->left, first, middle, prev);
        if (prev != NULL && root->val < prev->val) {
            if (first == NULL) {
                first = prev;
                middle = root;
            } else {
                middle = root;
            }
        }
        prev = root;

        inorder(root->right, first, middle, prev);
    }

public:
    void recoverTree(TreeNode* root) {
        // vector<int> in;
        // getInorder(root, in);
        // sort(in.begin(), in.end());
        // int index = 0;
        // inorderAgain(root, in, index);

        TreeNode* first = NULL;
        TreeNode* middle = NULL;
        TreeNode* prev = NULL;
        inorder(root, first, middle, prev);
        if(first && middle){
            swap(first -> val, middle -> val);
        }
    }
};