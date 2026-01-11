class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;
        stack<int> st;

        for(int i = 0; i <= n; i++){
            int currHeight = 0;
            if(i != n){
                currHeight = heights[i];
            }

            while(!st.empty() && currHeight < heights[st.top()]){
                int height = heights[st.top()];
                st.pop();

                int rightLimit = i;
                int leftLimit = -1;
                if(!st.empty()){
                    leftLimit = st.top();
                }

                maxArea = max(maxArea, (height * (rightLimit - leftLimit - 1)));
            }

            st.push(i);
        }

        return maxArea;
    }
};

// int n = heights.size();
// int maxArea = INT_MIN;

// for(int i = 0; i < n; i++){
//     int height = heights[i];

//     // Find the left limit
//     int left = i;
//     while(left >= 0 && heights[left] >= height){
//         left--;
//     }

//     // Find the right limit
//     int right = i;
//     while(right < n && heights[right] >= height){
//         right++;
//     }

//     // Compute the area
//     int width = right - left - 1;

//     maxArea = max(maxArea, (height * width));
// }

// return maxArea;