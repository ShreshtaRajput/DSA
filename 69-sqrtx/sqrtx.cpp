class Solution {
public:
    int mySqrt(int x) {
        int s = 1;
        int e = x;

        while(s <= e){
            long long mid = s + (e-s)/2;
            long long square = mid * mid;

            if(square == x){
                return mid;
            }else if(square < x){
                s = mid + 1;
            }else{
                e = mid - 1;
            }
        }

        return e;
    }
};