class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long res = 0;

        // loop from 0 to min(limit, n) -> limit se zyada nhi ya 'n' se zyada nhi
        for(int a = 0; a <= min(limit, n); a++){
            int remainingCandies = n - a;
            // max candies for remaining children can get = limit
            // at most candies = 2 * limit (isse zyada ya isse kam)
            if(remainingCandies <= 2 * limit){
                int min_b = max(0, remainingCandies - limit);
                int max_b = min(limit, remainingCandies);

                res += max_b - min_b + 1;
            }
        }

        return res;
    }
};