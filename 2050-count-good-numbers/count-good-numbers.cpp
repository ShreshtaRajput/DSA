class Solution {
private: 
    long long power(long long base, long long expo, long long mod){
        long long res = 1;
        base = base % mod;

        while(expo > 0){
            if( expo & 1){  //If odd
                res = (res * base) % mod;
            }

            expo = expo >> 1; //exp/2
            
            base = (base * base) % mod;
        }
        return res;
    }

public:
    int countGoodNumbers(long long n) {
        const int mod = 1000000007;
        
        // trying modular exponentiation
        long long evenPos = ( n + 1 )/2;
        long long oddPos = n/2;

        long long evenRes = power(5, evenPos, mod);

        long long oddRes = power(4, oddPos, mod);

        return (int)((evenRes * oddRes) % mod);
    }
};

// faster exponentiation (not working for large testcases)
    // finding 5^[n + 1/2]
    // long long evenRes = 1;
    // int b = (n + 1)/2;
    // for( int i = 0; i < b; i++){
    //     evenRes = (evenRes * 5) % mod;
    // }

    // finding 4^[n/2]
    // long long oddRes = 1;
    // b = n/2;
    // for( int i = 0; i < b; i++){
    //     oddRes = (oddRes * 4) % mod;
    // }

    // return (int)((evenRes * oddRes) % mod);