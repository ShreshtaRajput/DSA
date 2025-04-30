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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) {
            return head;
        }

        // dummy node pointing at head
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;
        ListNode* curr = head;

        while (curr != NULL) {
            if(curr -> next != NULL && curr -> val == curr -> next -> val){
                // Skip node that are equal
                while(curr -> next != NULL && curr -> val == curr -> next -> val){
                    curr = curr -> next;
                }

                // Link prev to the curr -> next (which is not equal)
                prev -> next = curr -> next;
            }else{
                prev = curr;
            }
            curr = curr -> next;
        }

        return dummy -> next;
    }
};

// bool isDuplicate = false;

// while (curr->val == curr->next->val) {
//     isDuplicate = true;
//     ListNode* temp = curr->next;
//     curr->next = curr->next->next;
//     delete temp;
// }
// //  curr is duplicate -> delete curr
// if (isDuplicate) {
//     ListNode* temp = curr;
//     curr = curr->next;

//     // If the node being deleted is at the beginning
//     if (prev != NULL) {
//         prev->next = curr;
//     } else {
//         head = curr;
//     }

//     delete temp;
// } else {
//     prev = curr;
//     curr = curr->next;
// }