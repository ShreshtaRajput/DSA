class Solution {
private:
    int computeTime(vector<int> &piles, int mid){
        int ans = 0;
        for(int i = 0; i < piles.size(); i++){
            ans += ceil((double)piles[i]/mid);
        }

        return ans;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = 0;
        for(int i = 0; i < piles.size(); i++){
            high = max(high, piles[i]);
        }

        while(low < high){
            int mid = low + (high - low) / 2;
            int totalTime = computeTime(piles, mid);
            if(totalTime <= h){
                high = mid;
            }else{
                low = mid + 1;
            }
        }

        return low;
    }
};