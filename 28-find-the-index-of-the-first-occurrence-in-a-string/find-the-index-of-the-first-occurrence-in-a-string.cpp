class Solution {
public:
    int strStr(string haystack, string needle) {
        int index = -1;
        int needleSize = needle.size();
        int stackSize = haystack.size();

        for (int i = 0; i < stackSize; i++) {
            string windowStr = haystack.substr(i, needleSize);
            if (windowStr == needle) {
                index = i;
                break;
            }
        }

        return index;
    }
};