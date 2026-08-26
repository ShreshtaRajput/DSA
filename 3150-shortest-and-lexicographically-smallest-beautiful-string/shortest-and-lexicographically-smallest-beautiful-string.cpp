class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        string res = "";

        int l = 0;
        int numK = 0;
        for(int r = 0; r < s.size(); r++){
            if(s[r] == '1') numK++;

            while(numK >= k){
                string temp = s.substr(l, r-l+1);

                if(numK == k){
                    // Update the answer
                    if(res == "" || temp.size() < res.size() || (temp.size() == res.size() && temp < res)){
                        res = temp;
                    }
                }

                //Shift left pointer
                if(s[l] == '1') numK--;
                l++;
            }
        }

        return res;
    }
};