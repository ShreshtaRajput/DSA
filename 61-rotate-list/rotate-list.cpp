/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head -> next == NULL){
            return head;
        }

        ListNode* temp = head;
        int m = 0;
        // Counting the number of nodes
        while(temp != NULL){
            m++;
            temp = temp -> next;
        }

        int n = 0;
        while(n < (k%m)){
            ListNode* secLast = NULL;
            ListNode* last = head;

            // finding last and second last
            while(last -> next != NULL){
                secLast = last;
                last = last -> next;
            }

            last -> next = head;
            head = last;
            secLast -> next = NULL;
            n++;
        }

        return head;
    }
};