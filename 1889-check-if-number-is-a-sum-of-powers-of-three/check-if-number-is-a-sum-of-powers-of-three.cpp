class Solution {
public:
    bool checkPowersOfThree(int n) {
        if (n == 0) {
            return true;
        }

        int x = 0;

        while (n > 0) {
            x = n % 3;
            n /= 3;
            if (x == 2) {
                return false;
            }
        }

        return true;
    }
};