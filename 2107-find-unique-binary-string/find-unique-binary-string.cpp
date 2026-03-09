class Solution {
private:
    string generate(string curr, int n, set<string> &st){
        if(curr.size() == n){
            if(st.find(curr) != st.end()){
                return "";
            }

            return curr;
        }

        string addZero = generate(curr + "0", n, st);
        if(addZero != ""){
            return addZero;
        }
        return generate(curr + "1", n, st);
    }
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        set<string> st;

        for(auto it: nums){
            st.insert(it);
        }

        return generate("", n, st);
    }
};