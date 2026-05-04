class Solution {
public:
    int sumOfPrimesInRange(int n) {
        int digit = n;
        int r = 0;

        // Reverse the number
        while(digit != 0){
            int lastDig = digit % 10;
            r = r * 10 + lastDig;
            digit /= 10;
        }

        // Sieve of Eratosthenes
        vector<bool> prime(max(r, n) + 1, true);
        prime[0] = prime[1] = false;

        for(int i = 2; i <= max(r, n); i++){
            if(prime[i]){
                for(int j = 2*i;j <= max(r, n); j+=i){
                    prime[j] = false;
                }
            }
        }

        // Calculate the result
        int res = 0;
        for(int i = min(n,r); i <= max(n,r); i++){
            if(prime[i]){
                res += i;
            }
        }

        return res;
    }
};