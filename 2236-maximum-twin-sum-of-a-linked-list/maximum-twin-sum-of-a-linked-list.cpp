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

        int count = 1;
        ListNode* curr = head;

        while(curr -> next != NULL){
            curr = curr -> next;
            count++;
        }

        return count;
    }

    ListNode* reverseList(ListNode* head){
        if(head == NULL) return NULL;

        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr != NULL){
            ListNode* next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

public:
    int pairSum(ListNode* head) {
        int n = findLen(head);
        int ans = INT_MIN;

        ListNode* curr = head;
        for(int i = 0; i < n/2; i++){
            curr = curr -> next;
        }

        ListNode* revNode = reverseList(curr);
        curr = head;

        for(int i = 0; i < n/2; i++){
            int sum = (curr -> val) + (revNode -> val);
            curr = curr -> next;
            revNode = revNode -> next;

            ans = max(ans, sum);
        }

        return ans;
    }
};

// int findSum(ListNode* head, int i, int n){
//     if(head == NULL) return 0;

//     int sum = 0;

//     ListNode* curr = head;
//     int count = 0;

//     while(count < i && curr != NULL){
//         curr = curr -> next;
//         count += 1;
//     }
//     sum += curr -> val;

//     while(count < n-i-1 && curr != NULL){
//         curr = curr -> next;
//         count += 1;
//     }
//     sum += curr -> val;

//     return sum;
// }