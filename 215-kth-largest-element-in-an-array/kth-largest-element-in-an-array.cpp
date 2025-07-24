class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;

        for(int i = 0; i < nums.size(); i++){
            pq.push(nums[i]);
        }

        int n = 1;
        while(n < k){
            pq.pop();
            n++;
        }

        return pq.top();
    }
};