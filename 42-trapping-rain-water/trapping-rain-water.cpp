class Solution {
public:
    int trap(vector<int>& height) {
        // Two Pointer approach
        int left = 0;
        int right = height.size()-1;

        int leftMax = 0;
        int rightMax = 0;
        int totalWater = 0;

        while(left < right){
            if(height[left] <= height[right]){
                if(height[left] >= leftMax){
                    leftMax = height[left];
                }else{
                    totalWater += leftMax - height[left];
                }
                left++;
            }else{
                if(height[right] >= rightMax){
                    rightMax = height[right];
                }else{
                    totalWater += rightMax - height[right];
                }
                right--;
            }
        }

        return totalWater;
    }
};

// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int totalWater = 0;
//         int n = height.size();

//         // For every index, we find the max in the left and the max at the right of the index
//         vector<int> leftMax(n), rightMax(n);

//         leftMax[0] = height[0];
//         for(int i = 1; i < n; i++){
//             leftMax[i] = max(leftMax[i-1], height[i]);
//         }

//         rightMax[n-1] = height[n-1];
//         for(int i = n-2; i >= 0; i--){
//             rightMax[i] = max(rightMax[i+1], height[i]);
//         }

//         for(int i = 0; i < n; i++){
//             totalWater += min(leftMax[i], rightMax[i]) - height[i];
//         }

//         return totalWater;
//     }
// };