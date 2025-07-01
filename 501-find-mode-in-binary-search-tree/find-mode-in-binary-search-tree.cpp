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
    vector<int> getInorder(TreeNode* root, vector<int> &in){
        if(root == NULL){
            return in;
        }

        getInorder(root -> left, in);
        in.push_back(root -> val);
        getInorder(root -> right, in);

        return in;
    }
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        vector<int> in;
        getInorder(root, in);
        map<int, int> mp;

        for(int i = 0; i < in.size(); i++){
            mp[in[i]]++;
        }

        int maxFreq = INT_MIN;

        for(auto &p: mp){
            maxFreq = max(maxFreq, p.second);
        }

        for(auto &p: mp){
            if(p.second >= maxFreq){
                ans.push_back(p.first);
            }
        }

        return ans;
    }
};