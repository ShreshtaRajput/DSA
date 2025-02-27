class Solution {
private:
    int getValueOfRomanSymbol(char c) {
        switch (c) {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return 0;
        }
    }

public:
    int romanToInt(string s) {
        int res = 0;
        int prevVal = 0;

        for (int i = s.length() - 1; i >= 0; i--) {
            int currValue = getValueOfRomanSymbol(s[i]);
            if (currValue >= prevVal) {
                res += currValue;
            } else {
                res -= currValue;
            }

            prevVal = currValue;
        }

        return res;
    }
};