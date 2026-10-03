class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0;

        int left = 0;
        int openBracket = 0;
        // Left -> right
        for(int right = left; right < s.size(); right++){
            if(s[right] == '('){
                openBracket++;
            }
            if(s[right] == ')'){
                openBracket--;
                if(openBracket < 0) {
                    openBracket = 0;
                    left = right + 1;
                }
                if(openBracket == 0){
                    res = max(res, right-left+1);
                }
            }
        }

        // Right -> left
        int right = s.size() - 1;
        int closedBracket = 0;
        for(int left = right; left >= 0; left--){
            if(s[left] == ')'){
                closedBracket++;
            }
            if(s[left] == '('){
                closedBracket--;
                if(closedBracket < 0){
                    closedBracket = 0;
                    right = left - 1;
                }
                if(closedBracket == 0){
                    res = max(res, right-left+1);
                }
            }
        }

        return res;
    }
};