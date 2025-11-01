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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        if(head == NULL) return NULL;

        unordered_set<int> st;  //Using set because of testcases like example 2

        for(int i = 0; i < nums.size(); i++){
            st.insert(nums[i]);
        }

        // Jb tk head wala element list mai hai tb tk remove krenge
        while(head != NULL && st.find(head -> val) != st.end()){
            ListNode* temp = head;
            head = head -> next;
            temp -> next = NULL;
        }

        // After the head elements are processed , we move onto the other nodes of the LL
        ListNode* curr = head;
        while(curr -> next != NULL){
            if(st.find(curr -> next -> val) != st.end()){
                ListNode* temp = curr -> next;
                curr -> next = curr -> next -> next;
                temp -> next = NULL;
            }else{
                curr = curr -> next;
            }
        }

        return head;
    }
};

        // for(int i = 0; i < nums.size(); i++){
        //     while(head != NULL){
        //         // If the value is found at the head itself
        //         if(head -> val == nums[i]){
        //             ListNode* temp = head;
        //             head = head -> next;
        //             delete temp;
        //         }else if(){

        //         }else{
        //             head = head -> next;
        //         }
        //     }
        // }