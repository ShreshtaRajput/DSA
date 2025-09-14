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

// Attempting the DFS approach
class Solution {
private:
    void dfs(TreeNode* left, TreeNode* right, int level){
        if(left == NULL && right == NULL) return;

        if(level % 2 != 0){     //Level is odd
            int temp = left -> val;
            left -> val = right -> val;
            right -> val = temp;
        }

        //pair leftChild of left with rightChild of right
        dfs(left -> left, right -> right, level + 1);
        // pair rightChild of left with leftChild of right
        dfs(left -> right, right -> left, level + 1);
    }
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        dfs(root -> left, root -> right, 1);
        return root;
    }
};

// class Solution {
// public:
//     TreeNode* reverseOddLevels(TreeNode* root) {
//         if(root == NULL) return NULL;

//         queue<TreeNode*> q;
//         q.push(root);

//         int level = 0;

//         while(!q.empty()){
//             // We traverse each level
//             int n = q.size();
//             vector<TreeNode*> currLevel;    //Store the nodes at curr level

//             for(int i = 0; i < n; i++){
//                 TreeNode* front = q.front();
//                 q.pop();

//                 currLevel.push_back(front);

//                 if(front -> left) q.push(front -> left);
//                 if(front -> right) q.push(front -> right);
//             }

//             if(level % 2 != 0){     //Odd level
//                 // Simple reverse array logic
//                 int s = 0, e = currLevel.size() - 1;
//                 while(s < e){
//                     int temp = currLevel[s] -> val;
//                     currLevel[s] -> val = currLevel[e] -> val;
//                     currLevel[e] -> val = temp;

//                     s++;
//                     e--;
//                 }
//             }

//             level++;
//         }

//         return root;
//     }
// };