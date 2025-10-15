class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int prevCount = 0;
        int currCount = 1;
        int ans = 0;

        for(int i = 1; i < nums.size(); i++){
            if(nums[i - 1] < nums[i]){
                currCount++;
            }else{
                ans = max({ans, currCount/2, min(prevCount, currCount)});
                prevCount = currCount;
                currCount = 1;  //Reset the currCount
            }
        }

        // This final check is needed, if the increasing subseqeunce did not break till the end of arr
        // Due to this, the else statement will not be executed and ans is not updated
        ans = max({ans, currCount/2, min(prevCount, currCount)});

        // Using currCount/2 => if we have an array where it is fully arranged in ascending order
        // So we divide it into two halves for answer

        return ans;    
    }
};

// class Solution {
// private:
//     bool isValid(vector<int> &nums, int len, int index){
//         for(int i = index; i < index + len - 1; i++){
//             if(nums[i] >= nums[i + 1]){
//                 return false;
//             }
//         }

//         return true;
//     }
// public:
//     int maxIncreasingSubarrays(vector<int>& nums) {
//         int left = 0;
//         int ans = 0;
//         for(int right = left; right < nums.size() - 1; right++){
//             if(nums[right] > nums[right+1]){     //Encountering a smaller element
//                 int len = right - left + 1;
//                 // Now we need to check the array further for this length
//                 if(right + 1 + len <= nums.size() && isValid(nums, len, right + 1)){
//                     ans = max(ans, len);
//                 }

//                 left+=1;
//             }
//         }

//         return ans;
//     }
// };