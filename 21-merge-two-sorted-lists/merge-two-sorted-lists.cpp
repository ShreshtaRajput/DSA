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
    ListNode* solve(ListNode* first, ListNode* second) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = first;
        ListNode* prev = dummy;
        ListNode* curr1 = first;
        ListNode* curr2 = second;

        while (curr1 != NULL && curr2 != NULL) {
            if (curr1->val <= curr2->val) {
                prev = curr1;
                curr1 = curr1->next;
            } else {
                // Insert curr2 before curr1
                ListNode* next2 = curr2->next;
                prev->next = curr2;
                curr2->next = curr1;
                prev = curr2;
                curr2 = next2;
            }
        }

        // If anything left in list2, append at end
        if (curr2 != NULL) {
            prev->next = curr2;
        }

        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }

public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == NULL) {
            return list2;
        }

        if (list2 == NULL) {
            return list1;
        }

        if (list1->val <= list2->val) {
            return solve(list1, list2);
        } else {
            return solve(list2, list1);
        }
    }
};

// ListNode* curr1 = first;
        // ListNode* next1 = curr1 -> next;
        // ListNode* curr2 = second;
        // ListNode* next2 = curr2 -> next;

        // while(next1 != NULL && curr2 != NULL){
        //     if(curr1 -> val <= curr2 -> val && next1 -> val > curr2 -> val){
        //         curr1 -> next = curr2;
        //         next2 = curr2 -> next;
        //         curr2 -> next = next1;

        //         curr1 = next1;
        //         curr2 = next2;
        //     }else{
        //         curr1 = next1;
        //         next1 = next1 -> next;

        //         if(next1 == NULL){
        //             curr1 -> next = curr2;
        //             return first;
        //         }
        //     }
        // }
        // return first;