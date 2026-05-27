class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n = word.size();
        unordered_map<char, vector<int>> mp;

        int res = 0;

        for(int i = 0; i < n; i++){
            mp[word[i]].push_back(i);
        }
        
        vector<char> keys;
        for(auto p : mp) keys.push_back(p.first);

        for(int k = 0; k < keys.size(); k++){
            char ch = keys[k];
            if(mp.find(ch) == mp.end()) continue; // Skip if already erased

            vector<int> idx = mp[ch];

            // Check for the upper/lower case of the character
            if(isupper(ch)){
                if(mp.find(tolower(ch)) != mp.end()){
                    vector<int> index = mp[tolower(ch)];
                    bool is_valid = true;

                    for(int i = 0; i < idx.size(); i++){
                        for(int j = 0; j < index.size(); j++){
                            if(idx[i] < index[j]){    //Condition broken
                                is_valid = false;
                                break;
                            }
                        }
                        if(!is_valid) break;
                    }

                    if(is_valid) {
                        res++;
                    }
                    mp.erase(tolower(ch));
                    mp.erase(ch);
                }
            }else if(islower(ch)){
                if(mp.find(toupper(ch)) != mp.end()){
                    vector<int> index = mp[toupper(ch)];
                    bool is_valid = true;

                    for(int i = 0; i < idx.size(); i++){
                        for(int j = 0; j < index.size(); j++){
                            if(idx[i] > index[j]){  //Condition break
                                is_valid = false;
                                break;
                            }
                        }
                        if(!is_valid) break;
                    }

                    if(is_valid) {
                        res++;
                    }
                    mp.erase(toupper(ch));
                    mp.erase(tolower(ch));
                }
            }
        }

        return res;
    }
};