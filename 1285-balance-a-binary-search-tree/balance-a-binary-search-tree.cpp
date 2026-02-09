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
    void inorderTraversal(TreeNode* node, vector<int> &arr){
        if(node == NULL) return;
        inorderTraversal(node -> left, arr);
        arr.push_back(node -> val);
        inorderTraversal(node -> right, arr);
    }

    TreeNode* createTree(vector<int> &arr, int start, int end){
        if(start > end) return NULL;

        int mid = (start + end)/2;

        // Left subtree will be from start to mid-1
        TreeNode* left = createTree(arr, start, mid - 1);
        // Right subtree  will be from mid+1 to end
        TreeNode* right = createTree(arr, mid + 1, end);

        // Middle one is the root node
        return new TreeNode(arr[mid], left, right);
    }

public:
    TreeNode* balanceBST(TreeNode* root) {
        // Make a sorted array by using inorder traversal
        vector<int> arr;
        inorderTraversal(root , arr);

        int n = arr.size();
        // Create a new tree from the sorted array
        return createTree(arr, 0, n-1);
    }
};