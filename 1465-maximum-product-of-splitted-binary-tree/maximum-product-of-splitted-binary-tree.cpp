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

#define MOD 1000000007
#define LL long long

class Solution {
private:
    int dfs(TreeNode* node){
        if(node == NULL){
            return 0;
        }

        node -> val += dfs(node -> left) + dfs(node -> right);

        return node -> val;
    }
public:
    int maxProduct(TreeNode* root) {
        LL res = INT_MIN;
        LL total = dfs(root);

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            LL curr = (total - node -> val) * (node -> val);   //We need to maximize this value
            res = max(res, curr);

            if(node -> left) q.push(node -> left);
            if(node -> right) q.push(node -> right);
        }

        return int(res % MOD);
    }
};