class Solution {
public:
    string clearStars(string s) {
        vector<stack<int>> count(26);

        for(int i = 0; i < s.size(); i++){
            if(s[i] != '*'){
                count[s[i] - 'a'].push(i);
            }else{
                for(int j = 0; j < 26; j++){
                    // First non-empty stack
                    if(!count[j].empty()){
                        s[count[j].top()] = '*';
                        count[j].pop();
                        break;
                    }
                }
            }
        }

        string ans;
        for(char ch : s){
            if(ch != '*'){
                ans.push_back(ch);
            }
        }
        return ans;
    }
};

// vector<char> stack;

// const int k = 100;

// for (char ch : s) {
//     // Jab tk star na aaye push in stack
//     if (ch != '*') {
//         stack.push_back(ch);
//     }

//     // Star aa gya
//     else {
//         if (!stack.empty()) {
//             int start = max(0, (int)stack.size() - k);
//             int minIndex = 0;
//             for (int i = start + 1; i < stack.size(); i++) {
//                 if (stack[i] <= stack[minIndex]) {
//                     minIndex = i;
//                 }
//             }

//             stack.erase(stack.begin() + minIndex);
//         }
//     }
// }

// return string(stack.begin(), stack.end());