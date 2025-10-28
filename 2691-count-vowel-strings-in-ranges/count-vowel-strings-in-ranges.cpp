class Solution {
private:
    bool isValid(string word){
        int n = word.size();

        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

        if(vowels.find(word[0]) != vowels.end() && vowels.find(word[n - 1]) != vowels.end()){
            return true;
        }
        return false;
    }
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();

        vector<int> prefix(n);

        if(isValid(words[0])){
            prefix[0] = 1;
        }

        for(int i = 1; i < words.size(); i++){
            if(isValid(words[i])){
                prefix[i] += prefix[i-1] + 1;
            }else{
                prefix[i] = prefix[i-1];
            }
        }

        vector<int> res;
        for(int i = 0; i < queries.size(); i++){
            if(queries[i][0] == 0) res.push_back(prefix[queries[i][1]]);
            else res.push_back(prefix[queries[i][1]] - prefix[queries[i][0] - 1]);
        }

        return res;
    }
};

// class Solution {
// private:
// bool isValid(string word){
//     int n = word.size();

//     unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

//     if(vowels.find(word[0]) != vowels.end() && vowels.find(word[n - 1]) != vowels.end()){
//         return true;
//     }
//     return false;
// }
// public:
//     vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
//         vector<int> res;

//         for(int i = 0; i < queries.size(); i++){
//             int count = 0;
//             for(int j = queries[i][0]; j <= queries[i][1]; j++){
//                 if(isValid(words[j])){
//                     count++;
//                 }
//             }
//             res.push_back(count);
//         }

//         return res;
//     }
// };