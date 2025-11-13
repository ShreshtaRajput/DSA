class Solution {
public:
    int maxOperations(string s) {
        int countOne = 0;
        int res = 0;

        int i = 0;
        while(i < s.length()){
            if(s[i] == '1'){    //Count the number of 1s
                countOne++;
                i++;
            }else{
                while(s[i] == '0'){   //Skip the 0 block in the array
                    i++;
                }
                res += countOne;    //Add the number of 1s in the block to the ans
            }
        }

        return res;
    }
};