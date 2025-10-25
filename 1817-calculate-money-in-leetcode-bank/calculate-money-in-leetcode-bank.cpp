class Solution {
public:
    int totalMoney(int n) {
        int res = 0;
        int monday = 1;

        while(n > 0){
            if(n >= 7){
                for(int i = 0; i < 7; i++){
                    res += monday + i;
                }

                n -= 7;
                monday++;
            }else{
                for(int i = 0; i < n; i++){
                    res += monday + i;
                }
                break;
            }
        }

        return res;
    }
};