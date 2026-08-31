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

        // vector<int> cps;

        int count = 2;
        int firstcp = -1;
        int prevcp = -1;
        int minDist = INT_MAX;
        int maxDist = INT_MIN;

        ListNode* prev = head;
        ListNode* curr = head -> next;
        while(curr -> next != NULL){
            // If it is a critical point
            if((curr -> val > curr -> next -> val && curr -> val > prev -> val) ||
            (curr -> val < curr -> next -> val && curr -> val < prev -> val)){
                if(firstcp == -1){
                    firstcp = count;
                }else{
                    minDist = min(minDist, count - prevcp);
                    maxDist = count - firstcp;
                }

                prevcp = count;
            }

            count++;
            prev = curr;
            curr = curr -> next;
        }

        if(firstcp == -1 || firstcp == prevcp){
            return {-1,-1};
        }

        // int n = cps.size();
        // if(cps.size() < 2){
        //     return {-1, -1};
        // }
        // int maxDist = abs(cps[0] - cps[n-1]);
        // int minDist = INT_MAX;
        // for(int i = 0; i < n-1; i++){
        //     minDist = min(minDist, abs(cps[i] - cps[i+1]));
        // }

        return {minDist, maxDist};
    }
};