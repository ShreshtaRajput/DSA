class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for (int i = low; i <= high; i++) {
            if (i < 100 && i % 11 == 0) {
                count++;
            } else if (i >= 1000) {
                string str = to_string(i);
                int len = str.size();
                int n = len / 2;
                int right = 0, left = 0;
                for (int j = 0; j < n; j++) {
                    left += int(str[j] - '0');
                }
                for (int j = n; j < len; j++) {
                    right += int(str[j] - '0');
                }

                if (left == right) {
                    count++;
                }
            }
        }
        return count;
    }
};