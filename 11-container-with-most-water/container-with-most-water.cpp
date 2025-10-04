class Solution {
public:
    int maxArea(vector<int>& height) {
        int right = height.size() - 1;
        int left = 0;

        int currArea = (right - left) * min(height[right], height[left]);

        while(left < right){
            int newArea = (right - left) * min(height[right], height[left]);

            currArea = max(currArea, newArea);

            if(height[left] < height[right]){
                left++;
            }else{
                right--;
            }
        }

        return currArea;
    }
};