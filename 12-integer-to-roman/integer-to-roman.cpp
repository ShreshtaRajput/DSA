class Solution {
public:
    string intToRoman(int num) {
        vector<string> M{"", "M", "MM", "MMM"};
        vector<string> C{"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        vector<string> X{"", "X",  "XX",  "XXX",  "XL", "L", "LX", "LXX", "LXXX", "XC"};
        vector<string> I{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

        return M[num/1000] + C[(num%1000)/100] + X[(num%100)/10] + I[num%10];

        // OPTIMUM APPROACH
        // int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        // const char* symbol[] = {"M",  "CM", "D",  "CD", "C",  "XC", "L",
        //                         "XL", "X",  "IX", "V",  "IV", "I"};

        // string res = "";

        // for(int i = 0; i < 13; i++){
        //     while( num >= values[i]){
        //         res += symbol[i];
        //         num -= values[i];
        //     }
        // }
        // return res;
    }
};