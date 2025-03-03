class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> smallerEle;
        vector<int> biggerEle;
        vector<int> equalEle;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < pivot){
                smallerEle.push_back(nums[i]);
            }else if(nums[i] == pivot){
                equalEle.push_back(nums[i]);
            }else{
                biggerEle.push_back(nums[i]);
            }
        }

        smallerEle.insert(smallerEle.end(), equalEle.begin(), equalEle.end());
        smallerEle.insert(smallerEle.end(), biggerEle.begin(), biggerEle.end());

        return smallerEle;
    }
};