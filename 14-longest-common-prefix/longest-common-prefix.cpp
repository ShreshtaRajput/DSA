class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0){
            return "";
        }

        string str = "";

        sort(strs.begin(), strs.end());

        // Just compare the first and last element after sorting
        string first = strs[0];
        string last = strs.back();

        int i = 0;

        while(i < first.size() && i < last.size()){
            if(first[i] == last[i]){
                str += first[i];
                i++;
            }else{
                break;
            }
        }

        return str;
    }
};