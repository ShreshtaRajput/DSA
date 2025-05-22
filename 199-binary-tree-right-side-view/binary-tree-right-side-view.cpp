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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;

        if(root == NULL){
            return ans;
        }

        queue<pair<TreeNode*, int>> q;
        map<int, int> rightNode;

        q.push(make_pair(root, 0));

        while(!q.empty()){
            pair<TreeNode*, int> temp = q.front();
            q.pop();
            TreeNode* node = temp.first;
            int vd = temp.second;

            rightNode[vd] = node -> val;

            if(node -> left){
                q.push(make_pair(node -> left, vd + 1));
            }

            if(node -> right){
                q.push(make_pair(node -> right, vd + 1));
            }
        }

        for(auto i : rightNode){
            ans.push_back(i.second);
        }

        return ans;
    }
};