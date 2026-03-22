class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;      //Stores potential "3"s

        int num2 = INT_MIN;     //Stores potential "2"s

        for(int i = n-1; i >= 0; i--){
            // If a number less than num2 is found => pattern found
            if(nums[i] < num2){
                return true;
            }

            while(!st.empty() && st.top() < nums[i]){
                num2 = st.top();
                st.pop();
            }

            st.push(nums[i]);
        }

        return false;
    }
};

// class Solution {
// public:
//     bool find132pattern(vector<int>& nums) {
//         stack<int> st;
//         int n = nums.size();

//         st.push(nums[0]);

//         int num1 = st.top();
//         int num2 = 0;
//         int idx = -1;

//         for(int i = 1; i < n; i++){
//             if(nums[i] > st.top()){
//                 num2 = max(nums[i], num2);
//                 num1 = st.top();
//                 idx = i;
//             }
//             st.push(nums[i]);
//         }

//         for(int i = idx; i < n; i++){
//             if(nums[i] > num1 && nums[i] < num2){
//                 return true;
//             }
//         }

//         return false;
//     }
// };