class Solution {
private:
    void helper(string s, vector<string> &ans, string temp, int index){
        // Base case
        if(index == s.size()){
            ans.push_back(temp);
            return;
        }
        // If the  character is a digit -> insert it as it is
        if(isdigit(s[index])){
            temp.push_back(s[index]);
            helper(s, ans, temp, index + 1);
        }else{
            // Include the cases for lower cases
            temp.push_back(tolower(s[index]));
            helper(s, ans, temp, index + 1);

            temp.pop_back();

            // Include the cases for upper cases
            temp.push_back(toupper(s[index]));
            helper(s, ans, temp, index + 1);
        }
    }
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        string temp = "";

        helper(s, ans, temp, 0);

        return ans;
    }
};