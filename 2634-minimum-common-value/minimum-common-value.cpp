class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        int pt1 = n-1;
        int pt2 = m-1;
        int res = -1;

        while(pt1 >= 0 && pt2 >= 0){
            if(nums1[pt1] == nums2[pt2]){
                res = nums1[pt1];
                pt1--;
                pt2--;
            }else if(nums1[pt1] > nums2[pt2]){
                pt1--;
            }else{
                pt2--;
            }
        }

        return res;
    }
};