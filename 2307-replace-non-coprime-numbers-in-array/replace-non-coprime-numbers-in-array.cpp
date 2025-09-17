class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<int> st;

        st.push(nums[0]);
        int i = 1;

        while (i < nums.size()) {
            int curr = nums[i];
            // Checking the current element with the top of the stack
            // If they meet the requirements
            while(!st.empty() && gcd(st.top(), curr) > 1){
                int top = st.top();
                st.pop();
                curr = lcm(top, curr);  //The merging step
            }
            // current is always pushed
            // If they meet the requirements -> the current is proccessed accordingly
            // Else it is pushed directly
            st.push(curr);
            i++;
        }

        vector<int> res(st.size());

        // Pushing the elements in res in reverse order from the stack
        for(int i = st.size() - 1; i >= 0; i--){
            res[i] = st.top();
            st.pop();
        }

        return res;
    }
};

// int top = st.top();
// int val = gcd(top, nums[i]);

// if (val > 1) {
//     int lc = lcm(top, nums[i]);
//     if (!st.empty()) {
//         if (lc != st.top()) {
//             st.push(lcm(top, nums[i]));
//             res.push_back(lcm(top, nums[i]));
//         }
//     }
// } else {
//     res.push_back(nums[i]);
// }