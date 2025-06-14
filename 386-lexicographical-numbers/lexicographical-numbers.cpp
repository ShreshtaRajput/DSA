class Solution {
private:
    void solve(int start, int limit, vector<int> &res){
        // Base case
        if(start > limit){
            return;
        }

        res.push_back(start);

        for(int next = 0; next < 10; next++){
            // Getting the next digit in lex order
            int nextDigit = start * 10 + next;

            if(nextDigit <= limit){
                // If the next digit is in range, we find the next valid lex digit
                solve(nextDigit, limit, res);
            }else{
                // For invalid lex digit
                break;
            }
        }
    }
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;

        for(int i = 1; i < 10; i++){
            solve(i, n, res);
        }

        return res;
    }
};