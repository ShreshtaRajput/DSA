class Solution {
public:
    void sortColors(vector<int>& nums) {
        // for(int i = 0; i < nums.size(); i++){
        //     for(int j = 0; j < nums.size() - 1 - i; j++){
        //         if(nums[j] > nums[j + 1]) {
        //             swap(nums[j], nums[j+1]);
        //         }
        //     }
        // }

        int count0 = 0;
        int count1 = 0;
        int count2 = 0;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                count0++;
            }
            else if(nums[i] == 1){
                count1++;
            }
            else{
                count2++;
            }
        }

        int i = 0;

        while(count0--){
            nums[i] = 0;
            i++;
        }
        while(count1--){
            nums[i] = 1;
            i++;
        }
        while(count2--){
            nums[i] = 2;
            i++;
        }
    }
};