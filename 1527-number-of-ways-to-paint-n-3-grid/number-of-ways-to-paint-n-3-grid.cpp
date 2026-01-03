class Solution {
public:
    int numOfWays(int n) {
        // There are two type of combination of colors possible for the required condition
        // row has 3 different colors - 6 combinations
        // left and right column have the same color and middle has different - 6 combinations

        // Let the types be A - all diff colors, and B - left and right same

        const int MOD = 1e9 + 7;

        long long A = 6;  // all different (ABC)
        long long B = 6;  // left & right same (ABA)

        for (int i = 2; i <= n; i++) {
            long long newA = (2 * A + 2 * B) % MOD;
            long long newB = (2 * A + 3 * B) % MOD;

            A = newA;
            B = newB;
        }

        return (A + B) % MOD;
    }
};