class Solution {
public:
    int trap(vector<int>& height) {
        int totalWater = 0;
        int n = height.size();

        // For every index, we find the max in the left and the max at the right of the index
        vector<int> leftMax(n), rightMax(n);

        leftMax[0] = height[0];
        for(int i = 1; i < n; i++){
            leftMax[i] = max(leftMax[i-1], height[i]);
        }

        rightMax[n-1] = height[n-1];
        for(int i = n-2; i >= 0; i--){
            rightMax[i] = max(rightMax[i+1], height[i]);
        }

        for(int i = 0; i < n; i++){
            totalWater += min(leftMax[i], rightMax[i]) - height[i];
        }

        return totalWater;
    }
};