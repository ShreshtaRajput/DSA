class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n == 1){
            return true;
        }

        if (n <= 0 || n % 3 != 0){
            return false;
        }
        
        return isPowerOfThree(n/3);
    }
};

/*
for (int i = 0; i <= 19; i++) {
    int ans = pow(3, i);

    if (ans == n) {
        return true;
    }
}
return false;
*/