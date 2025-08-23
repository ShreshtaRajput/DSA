class Solution {
private:
    int applyOperation(int l, int r, char ch) {
        if (ch == '+') {
            return l + r;
        } else if (ch == '-') {
            return l - r;
        } else {
            return l * r;
        }
    }

public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> ans;

        // base case
        if (expression.size() == 1) {
            ans.push_back(stoi(expression));
            return ans;
        }

    // For expression having no operator and just a single number of two digits acc to contraints
        if (expression.length() == 2 && isdigit(expression[0])) {
            ans.push_back(stoi(expression));
            return ans;
        }

        for (int i = 0; i < expression.size(); i++) {
            char curr = expression[i];

            if (isdigit(curr))
                continue;

            vector<int> left = diffWaysToCompute(expression.substr(0, i));
            vector<int> right = diffWaysToCompute(expression.substr(i + 1));

            for (auto l : left) {
                for (auto r : right) {
                    int res = 0;

                    res = applyOperation(l, r, curr);
                    ans.push_back(res);
                }
            }
        }

        return ans;
    }
};