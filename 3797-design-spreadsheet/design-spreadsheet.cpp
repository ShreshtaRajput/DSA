class Spreadsheet {
    unordered_map<string, int> mp;

public:
    Spreadsheet(int rows) {}

    void setCell(string cell, int value) { 
        mp[cell] = value;   //Assign the given value
    }

    void resetCell(string cell) { 
        mp[cell] = 0;   //Reset to 0
    }

    int getValue(string formula) {
        string s = formula.substr(1); // Remove the '=' from formula
        int num1 = 0, num2 = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '+') {
                string s1 = s.substr(0, i);
                string s2 = s.substr(i + 1);

                if (s1[0] >= 'A' && s1[0] <= 'Z') {
                    num1 =
                        mp[s1]; // If denoting a cell -> get the value from map
                } else {
                    num1 = stoi(s1); // If number -> convert the string to int
                }

                if (s2[0] >= 'A' && s2[0] <= 'Z') {
                    num2 = mp[s2];
                } else {
                    num2 = stoi(s2);
                }
            }
        }

        return num1 + num2;   //Return the sum acc to formla
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */