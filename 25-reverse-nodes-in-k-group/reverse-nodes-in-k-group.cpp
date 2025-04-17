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
        int count = 0;
        ListNode* temp = head;

        while(temp != NULL){
            count++;
            temp = temp -> next;
        }

        return count;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Base case
        if( head == NULL || head -> next == NULL || k == 1){
            return head;
        }

        // Reverse first K node
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        int count = 0;

        while(curr != NULL && count < k){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        // Baaki recursion dekh lega
        if(next != NULL){
            if(getLength(next) >= k){
                head -> next = reverseKGroup(next, k);
            }else{
                head -> next = next;
            }
        }

        return prev;
    }
};