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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, int> mp;

        for(auto ele: descriptions){
            int childNode = ele[1];

            mp[childNode]++;
        }

        TreeNode* root = NULL;

        // Finding the root node
        for(auto ele: descriptions){
            int node = ele[0];

            if(mp.find(node) == mp.end()){
                root = new TreeNode(node);
                break;
            }
        }

        // Map to track the parent-child in the tree
        unordered_map<int, TreeNode*> nodes;
        for(auto ele: descriptions){
            int parent = ele[0];
            int child = ele[1];
            int dir = ele[2];
            
            // If parent does not exist
            if(nodes.find(parent) == nodes.end()){
                nodes[parent] = new TreeNode(parent);
            }

            // If child does not exist
            if(nodes.find(child) == nodes.end()){
                nodes[child] = new TreeNode(child);
            }

            if(dir == 1){
                nodes[parent] -> left = nodes[child];
            }else{
                nodes[parent] -> right = nodes[child];
            }
        }

        // Find the root node
        for(auto ele: nodes){
            int val = ele.first;
            TreeNode* node = ele.second;

            if(node -> val == root -> val){
                return node;
            }
        }

        return NULL;
    }
};