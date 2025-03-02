class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> ans;

        int i = 0; int j = 0;

        while(i <= nums1.size() - 1 && j <= nums2.size() - 1){
            if(nums1[i][0] == nums2[j][0]){
                int resNum = nums1[i][1] + nums2[j][1];
                vector<int> tempVector = {nums1[i][0], resNum};

                ans.push_back(tempVector);
                i++;
                j++;
            }else if(nums1[i][0] < nums2[j][0]){
                ans.push_back({nums1[i][0], nums1[i][1]});
                i++;
            }else{
                ans.push_back({nums2[j][0], nums2[j][1]});
                j++;
            }
        }

        while (i < nums1.size()) {
            ans.push_back(nums1[i]);
            i++;
        }

        while (j < nums2.size()) {
            ans.push_back(nums2[j]);
            j++;
        }
        return ans;
    }
};