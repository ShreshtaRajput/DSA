class Solution {
private:
    bool isLess(string s1, string s2) {
        // Remove leading zeroes from both
        int i = 0;
        while (i < s1.size() && s1[i] == '0')
            i++;
        s1 = s1.substr(i);

        int j = 0;
        while (j < s2.size() && s2[j] == '0')
            j++;
        s2 = s2.substr(j);
        
        // If string is empty marks as 0
        if (s1.empty()){
            s1 = "0";
        }
        if (s2.empty()){
            s2 = "0";
        }

        // Number with shorter length is always smaller
        if (s1.length() != s2.length()){
            return s1.length() < s2.length();
        }

        return s1 <= s2;
    }

public:
    string largestGoodInteger(string num) {
        string ans = "";

        for (int i = 0; i < num.size() - 2; i++) {
            string temp = "";
            if (num[i] == num[i + 1] && num[i] == num[i + 2]) {
                temp += num.substr(i, 3);
                if (isLess(ans, temp)) {
                    ans = temp;
                }
            }
        }

        return ans;
    }
};