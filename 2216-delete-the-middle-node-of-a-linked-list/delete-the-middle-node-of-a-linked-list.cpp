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
private:
    int findLen(ListNode* head){
        if(head == NULL) return 0;

        int len = 1;
        ListNode* curr = head;

        while(curr -> next != NULL){
            curr = curr -> next;
            len++;
        }

        return len;
    }
public:
    ListNode* deleteMiddle(ListNode* head) {
        int n = findLen(head);

        if(head == NULL || n == 1) return NULL;

        ListNode* curr = head;

        for(int i = 0; i < n/2-1; i++){
            curr  = curr -> next;
        }
        ListNode* middle = curr -> next;
        ListNode* next = middle -> next;

        curr -> next = middle -> next;
        middle -> next = NULL;

        return head;
    }
};