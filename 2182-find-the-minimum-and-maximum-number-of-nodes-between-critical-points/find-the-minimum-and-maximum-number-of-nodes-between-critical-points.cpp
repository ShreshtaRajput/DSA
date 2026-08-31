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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(!head -> next || !head -> next -> next){
            return {-1, -1};
        }

        vector<int> cps;

        int count = 2;
        ListNode* prev = head;
        ListNode* curr = head -> next;
        while(curr -> next != NULL){
            // If it is a critical point
            if((curr -> val > curr -> next -> val && curr -> val > prev -> val) ||
            (curr -> val < curr -> next -> val && curr -> val < prev -> val)){
                cps.push_back(count);
            }

            count++;
            prev = curr;
            curr = curr -> next;
        }

        int n = cps.size();
        if(cps.size() < 2){
            return {-1, -1};
        }
        int maxDist = abs(cps[0] - cps[n-1]);
        int minDist = INT_MAX;
        for(int i = 0; i < n-1; i++){
            minDist = min(minDist, abs(cps[i] - cps[i+1]));
        }

        return {minDist, maxDist};
    }
};