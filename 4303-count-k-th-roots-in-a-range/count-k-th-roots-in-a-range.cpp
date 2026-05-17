class Solution {
private:
    long long power(long long base, int exp){
        long long res = 1;
        for(int i = 0; i < exp; i++){
            res *= base;
        }
        return res;
    }
    
    long long countUpTo(long long maxVal, int k){
        if(maxVal < 0) return 0;
        if(maxVal == 0) return 1;

        if(k == 1) return maxVal + 1;

        long long root = round(pow(maxVal, 1/k));

        while(power(root, k) > maxVal){
            root--;
        }

        while(power(root+1, k) <= maxVal){
            root++;
        }

        return root + 1;
    }
public:
    int countKthRoots(int l, int r, int k) {
        return countUpTo(r, k) - countUpTo(l-1, k);
    }
};