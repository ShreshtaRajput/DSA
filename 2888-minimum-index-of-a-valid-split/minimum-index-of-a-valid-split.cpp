class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int, int> fullArrMap;

        for(int i = 0; i < nums.size(); i++){
            fullArrMap[nums[i]]++;
        }

        int maxEle = -1, maxfrequency = 0;
        for(auto i : fullArrMap){
            if(i.second > maxfrequency){
                maxfrequency = i.second;
                maxEle = i.first;
            }
        }

        int leftCount = 0, rightCount = maxfrequency;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == maxEle){
                leftCount++;
                rightCount--;
            }

            if(leftCount * 2 > (i + 1) && rightCount * 2 > (nums.size() - i - 1)){
                return i;
            }
        }
        return -1;
    }
};