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
    int solve(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int leftSum = solve(root->left);
        int rightSum = solve(root->right);

        int sum = root->val + leftSum + rightSum;

        return sum;
    }

    void addToTree(TreeNode* root, vector<int>& treeSum) {
        if (root == NULL) {
            return;
        }

        int sum = solve(root);
        treeSum.push_back(sum);

        if (root->left) {
            addToTree(root->left, treeSum);
        }
        if (root->right) {
            addToTree(root->right, treeSum);
        }
    }

public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> ans;
        vector<int> treeSum;

        addToTree(root, treeSum);

        map<int, int> mp;

        for (int i = 0; i < treeSum.size(); i++) {
            mp[treeSum[i]]++;
        }

        int maxFreq = INT_MIN;

        for (auto& p : mp) {
            maxFreq = max(maxFreq, p.second);
        }

        for (auto& p : mp) {
            if (p.second == maxFreq) {
                ans.push_back(p.first);
            }
        }

        return ans;
    }
};

// void solve(TreeNode* root, vector<int> &treeSum){
//     int sum = 0;

//     if(root == NULL){
//         return;
//     }

//     sum += root -> val;

//     if(root -> left == NULL && root -> right == NULL){
//         treeSum.push_back(sum);
//         return;
//     }

//     if(root -> left){
//         solve(root -> left, treeSum);
//     }
//     if(root -> right){
//         solve(root -> right, treeSum);
//     }
// }