class Solution {
private:
    int binSearch(int num, vector<int> &nums2){
        int s = 0;
        int e = nums2.size() - 1;
        int ans = -1;

        while(s <= e){
            int mid = s + (e - s) / 2;

            if(nums2[mid] >= num){
                // the pair is valid => we have to maximize the gap
                ans = mid;
                s = mid + 1;
            }else{
                // Invalid pair => Search for a valid pair
                e = mid - 1;
            }
        }

        return ans;
    }
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int res = 0;
        int n = nums1.size();

        for(int i = 0; i < n; i++){
            int idx = binSearch(nums1[i], nums2);
            if(idx != -1 && idx >= i){
                res = max(res, idx - i);
            }
        }

        return res;
    }
};