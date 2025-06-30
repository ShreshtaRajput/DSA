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
    int findBottomLeftValue(TreeNode* root) {
        int ans = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        int last_level = -1;

        while(!q.empty()){
            pair<TreeNode*, int> front = q.front();
            q.pop();

            if(front.second > last_level){
                last_level = front.second;
                ans = front.first -> val;
            }

            TreeNode* node = front.first;
            int level = front.second;
            if(front.first -> left){
                q.push({node -> left, level + 1});
            }
            if(front.first -> right){
                q.push({node -> right, level + 1});
            }
        }

        return ans;
    }
};