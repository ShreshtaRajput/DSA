/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(head == NULL){
            return head;
        }

        Node* curr = head;

        while(curr != NULL){
            if(curr -> child){
                Node* nextNode = curr -> next;

                Node* childHead = flatten(curr -> child);

                curr -> next = childHead;
                childHead -> prev = curr;

                Node* childTail = childHead;
                while(childTail -> next != NULL){
                    childTail = childTail -> next;
                }

                if(nextNode){
                    childTail -> next = nextNode;
                    nextNode -> prev = childTail;
                }

                curr -> child = NULL;
            }
            curr = curr -> next;
        }
        return head;
    }
};