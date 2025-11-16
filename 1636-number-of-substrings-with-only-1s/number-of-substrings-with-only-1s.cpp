class Solution {
public:
    int numSub(string s) {
        int total = 0;
        int cnt = 0;
        int mod = 1e9 + 7;
        
        for(auto &ch: s){
            if(ch == '1'){
                cnt++;
            }else{
                total = (total + (long long)cnt * (cnt + 1)/2) % mod;
                cnt = 0;
            }
        }

        total = (total + (long long)cnt * (cnt + 1)/2) % mod;     //Adding the last pair of 1

        return total % mod;
    }
};