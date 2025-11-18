#define LL long long

class Solution {
public:
    int numberOfSubstrings(string s) {
        // According to the problem, 1s >= 0s^2
        int n = s.size();
        int max0 = 0;

        // Counting the max number of 0s the string of n length can have for our condition to still remain valid
        while((LL)max0 * max0 <= n) max0++;

        int ans = 0;

        // Counting the no. of substrings for consecutive 1s
        int i = 0; 
        while(i < n){
            if(s[i] == '1'){
                int j = i;
                while(j < n && s[j] == '1') j++;
                int len = j - i;
                ans = ans + len * (len + 1)/2;
                i = j;
            }else{
                i++;
            }
        }

        for(int i = 1; i <= max0; i++){
            int l = 0;
            int ones = 0, zeros = 0;
            int lastBad = -1;

            for(int r = 0; r < n; r++){
                if(s[r] == '0') zeros++;
                else ones++;

                // shrink from left as much as we can
                while (l < r) {
                    if (s[l] == '0' && zeros > i) {
                        // we MUST remove this '0' because we have too many zeros
                        zeros--;
                        lastBad = l;
                        l++;
                    } else if (s[l] == '1' && ones - 1 >= i * i) {
                        // we CAN remove this '1' and still keep ones >= z^2
                        ones--;
                        l++;
                    } else {
                        // can't remove s[l] without breaking our constraints
                        break;
                    }
                }

                // Now if zeroes <= z
                if(zeros == i && ones >= i*i){     //The required condition
                    ans += (l - lastBad);    
                }
            }
        }

        return ans;
    }
};