class Solution {
public:
    int findClosest(int x, int y, int z) {
        int xyDiff = abs(x - z);
        int yzDiff = abs(y - z);

        if(xyDiff < yzDiff){
            return 1;
        }else if(xyDiff > yzDiff){
            return 2;
        }else{
            return 0;
        }
    }
};