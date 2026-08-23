class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        vector<vector<int>> res;

        set<int> st(nums.begin(), nums.end());

        while(lower <= upper){
            // If present in the array
            if(st.find(lower) != st.end()){
                lower++;
            }else{
                int start = lower;

                while(lower <= upper && st.find(lower) == st.end()){
                    lower++;
                }

                res.push_back({start, lower-1});
            }
        }

        return res;
    }
};