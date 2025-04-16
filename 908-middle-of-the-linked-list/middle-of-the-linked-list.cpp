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
    int getLength(ListNode* head){
        ListNode* temp = head;
        int len = 0;

        while(temp != NULL){
            temp = temp -> next;
            len++;
        }

        return len;
    }
public:
    ListNode* middleNode(ListNode* head) {
        int len = getLength(head);
        int mid = len/2;
        ListNode* temp = head;
        int count = 0;

        while(count < mid){
            temp = temp -> next;
            count++;
        }

        return temp;
    }
};