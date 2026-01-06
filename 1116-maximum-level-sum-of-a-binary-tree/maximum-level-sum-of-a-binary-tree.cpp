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
public:
    int maxLevelSum(TreeNode* root) {
        int maxSum = INT_MIN;
        int res = 0;

        int level = 0;
        queue<TreeNode*> q;

        q.push(root);
        while(!q.empty()){
            int sum = 0;
            level += 1;

            for(int ele = q.size(); ele > 0; ele--){
                TreeNode* node = q.front();
                q.pop();

                sum += node -> val;

                if(node -> left != NULL){
                    q.push(node -> left);
                }

                if(node -> right != NULL){
                    q.push(node -> right);
                }
            }

            if(maxSum < sum){
                maxSum = sum;
                res = level;
            }
        }

        return res;
    }
};