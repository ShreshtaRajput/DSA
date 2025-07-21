class Solution {
public:
    string makeFancyString(string s) {
        string fancy = "";
        char prev = s[0];
        int frequency = 1;
        fancy.push_back(s[0]);

        for(int i = 1; i < s.size(); i++){
            if(s[i] == prev){
                frequency++;
            }else{
                prev = s[i];
                frequency = 1;
            }

            if(frequency < 3){
                fancy.push_back(s[i]);
            }
        }

        return fancy;
    }
};