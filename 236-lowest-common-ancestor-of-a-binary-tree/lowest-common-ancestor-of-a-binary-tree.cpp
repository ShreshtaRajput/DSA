/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    bool check(TreeNode* root, TreeNode* p, vector<TreeNode*>& ans) {
        if (root == NULL) {
            return false;
        }

        ans.push_back(root);
        // If root is the target node
        if (root == p) {
            return true;
        }

        // checking for the node on the left and right sub-tree
        if (check(root->left, p, ans) || check(root->right, p, ans)) {
            return true;
        }

        // Backtracking
        ans.pop_back();
        return false;
    }

    vector<TreeNode*> pathToNode(TreeNode* root, TreeNode* p) {
        vector<TreeNode*> ans;

        if (check(root, p, ans)) {
            return ans;
        }

        return {};
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int n1 = p->val;
        int n2 = q->val;

        // Stores the path from root to target node
        vector<TreeNode*> p1 = pathToNode(root, p);
        vector<TreeNode*> p2 = pathToNode(root, q);

        TreeNode* lca = NULL;

        int i = 0;
        while(i < p1.size() && i < p2.size() && p1[i] == p2[i]){
            lca = p1[i];
            i++;
        }

        return lca;
    }
};

// if (root == NULL) {
//     return NULL;
// }

// int n1 = p->val;
// int n2 = q->val;

// if (root->val == n1 || root->val == n2) {
//     return root;
// }

// TreeNode* left = lowestCommonAncestor(root->left, p, q);
// TreeNode* right = lowestCommonAncestor(root->right, p, q);

// if (left != NULL && right != NULL) {
//     return root;
// }

// if (left != NULL && right == NULL) {
//     return left;
// } else {
//     return right;
// }