class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 1){     //base case
            return true;
        }

        if(n <= 0 || n % 2 != 0){   //If less than 0 or not divisible by 2
            return false;
        }

        return isPowerOfTwo(n/2);
        // for(int i = 0; i <= 30; i++){
        //     int ans = pow(2,i);

        //     if(ans == n){
        //         return true;
        //     }
        // }
        // return false;
    }
};