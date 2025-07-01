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
    TreeNode* solve(int s, int e, int postStart, vector<int> &preorder, vector<int> &postorder){
        // base case
        if(s > e){
            return NULL;
        }

        // If there is only one node
        if(s == e){
            TreeNode* node = new TreeNode(preorder[s]);
            return node;
        }

        // First element in preorder is root node
        TreeNode* root = new TreeNode(preorder[s]);
        // The second element is the root node of left subtree
        int leftRoot = preorder[s + 1];

        // Counting the number of nodes in left subtree
        int nodesInLeft = 1;
        // jb tk postorder mai <leftRoot> element nhi aa jaata tb tk elements add krte rho
        while(postorder[postStart + nodesInLeft - 1] != leftRoot){
            nodesInLeft++;
        }
        
        // Recursive call for left subtree
        root -> left = solve(s + 1, s + nodesInLeft, postStart, preorder, postorder);
        // Recursive call for right subtree
        root -> right = solve(s + nodesInLeft + 1, e, postStart + nodesInLeft, preorder, postorder);

        return root;
    }
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        return solve(0, n - 1, 0, preorder, postorder);
    }
};