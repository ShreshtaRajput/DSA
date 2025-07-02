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
    void bfsFromLeft(TreeNode* root, queue<int> &q){
        queue<TreeNode*> temp;
        temp.push(root);

        while(!temp.empty()){
            TreeNode* front = temp.front();
            temp.pop();

            if(front == NULL){
                q.push(INT_MIN);
                continue;
            }

            q.push(front -> val);
            temp.push(front -> left);
            temp.push(front -> right);
        }
    }

    void bfsFromRight(TreeNode* root, queue<int> &q){
        queue<TreeNode*> temp;
        temp.push(root);

        while(!temp.empty()){
            TreeNode* front = temp.front();
            temp.pop();

            if(front == NULL){
                q.push(INT_MIN);
                continue;
            }

            q.push(front -> val);
            temp.push(front -> right);
            temp.push(front -> left);
        }
    }

public:
    bool isSymmetric(TreeNode* root) {
        queue<int> q1;
        bfsFromLeft(root -> left, q1);
        queue<int> q2;
        bfsFromRight(root -> right, q2);

        if(q1 == q2){
            return true;
        }else{
            return false;
        }
    }
};