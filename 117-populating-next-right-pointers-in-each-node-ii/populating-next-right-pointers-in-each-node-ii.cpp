/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL){
            return root;
        }

        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            Node* rightNode = NULL;

            for(int i = q.size(); i > 0; i--){
                Node* front = q.front();
                q.pop();

                front -> next = rightNode;
                rightNode = front;

                if(front -> right){
                    q.push(front -> right);
                }
                if(front -> left){
                    q.push(front -> left);
                }
            }
        }
        
        return root;
    }
};