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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;

        if(root == NULL){
            return {};
        }

        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        int lastLevel = -1;
        int lastVal = INT_MIN;

        while(!q.empty()){
            pair<TreeNode*, int> front = q.front();
            q.pop();

            // Moving to the next level
            if(front.second > lastLevel){
                if(lastLevel != -1){
                    ans.push_back(lastVal);
                }
                lastLevel = front.second;
                lastVal = front.first -> val;
            }else{
                // we are at the same level;
                lastVal = max(lastVal, front.first -> val);
                // While processing the last value of the last level, the queue gets empty
                // but the last max value of the last value is stored in the lastVal variable
                // We push it after the exiting the loop
            }

            if(front.first -> left){
                q.push({front.first -> left, front.second + 1});
            }
            if(front.first -> right){
                q.push({front.first -> right, front.second + 1});
            }
        }

        ans.push_back(lastVal);

        return ans;
    }
};