class Solution {
public:
    vector<int> getPrimes(int left, int right) {
        vector<bool> prime(right + 1, true);

        prime[0] = prime[1] = false;

        for (int i = 2;  i * i <= right; i++) {
            if (prime[i]) {
                for (int j = i * i; j <= right; j += i) {
                    prime[j] = 0;
                }
            }
        }

        vector<int> primes;
        for (int i = left; i <= right; i++) {
            if (prime[i])
                primes.push_back(i);
        }

        return primes;
    }

    vector<int> closestPrimes(int left, int right) {
        vector<int> primes = getPrimes(left,right);

        if (primes.size() < 2) return {-1, -1};

        int size = primes.size() - 1;

        int ele1 = -1;
        int ele2 = -1;

        int min = INT_MAX;

        // while(j > 0){
        //     while(i > 0){
        //         int diff = primes[i] - primes[j];
        //         if(diff < min){
        //             min = diff;
        //             ele1 = primes[i];
        //             ele2 = primes[j];
        //         }
        //         i--;
        //     }
        //     j--;
        // }

        for(int i = 1; i <= size; i++){
            int diff = primes[i] - primes[i - 1];
            if(diff < min){
                min = diff;
                ele1 = primes[i-1];
                ele2 = primes[i];
            }
        }

        vector<int> ans;
        ans.push_back(ele1);
        ans.push_back(ele2);

        return ans;
    }
};