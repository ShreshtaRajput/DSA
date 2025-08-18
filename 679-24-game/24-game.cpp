class Solution {
private:
    // This function will generate all the possible results of two numbers
    vector<double> solver(double a, double b){
        vector<double> temp;
        temp.push_back(a + b);
        temp.push_back(a * b);
        temp.push_back(a - b);
        temp.push_back(b - a);
        if(a != 0) temp.push_back(b / a);
        if(b != 0) temp.push_back(a / b);

        return temp;
    }

    bool helper(vector<double> &cards_double){
        // Base case - if only one element is left -> check if it is close to 24
        if(cards_double.size() == 1){
            return fabs(cards_double[0] - 24.0) < 1e-6;
        }

        // Try every pair of {i, j}
        for(int i = 0; i < cards_double.size(); i++){
            for(int j = i + 1; j < cards_double.size(); j++){
                // This vector includes all the elements that do not contain cards[i] and cards[j]
                vector<double> temp;
                for(int k = 0; k < cards_double.size(); k++){
                    if(k == i || k == j) continue;
                    temp.push_back(cards_double[k]);
                }

                // This vector will store all the results of (cards[i] op cards[j])
                vector<double> op = solver(cards_double[i], cards_double[j]);

                // for each result check if it will be valid by reccursive backtracking
                for(auto val: op){
                    temp.push_back(val);
                    // If it is valid
                    if(helper(temp)){
                        return true;
                    }
                    temp.pop_back();    //else backtrack
                }
            }
        }

        return false;
    }
public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> cards_double(cards.begin(), cards.end());
        return helper(cards_double);
    }
};