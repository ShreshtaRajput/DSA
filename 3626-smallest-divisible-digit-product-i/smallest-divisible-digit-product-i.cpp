class Solution {
private:
    bool check(int n, int t){
        int prod = 1;
        while(n > 0){
            int dig = n % 10;
            n /= 10;
            prod *= dig;
        }

        return !(prod % t);
    }
public:
    int smallestNumber(int n, int t) {
        while(!check(n, t)){
            n++;
        }

        return n;
    }
};