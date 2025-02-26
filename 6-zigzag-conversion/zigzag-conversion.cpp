class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows >= s.length() || numRows == 1){
            return s;
        }

        int index = 0, d = 0;
        vector<vector<char>> rows(numRows);

        for(char ch : s){
            rows[index].push_back(ch);
            if(index == 0){
                d = 1;
            }else if(index == numRows - 1){
                d = -1;
            }
            index += d;
        }

        string res;
        for(const vector<char> row : rows){
            for(char ch: row){
                res += ch;
            }
        }
        return res;
    }
};