class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(beginWord);

        while(!q.empty()){
            string word = q.front().first;
            int level = q.front().second;
            q.pop();

            // If the end word is found in the queue
            if(word == endWord){
                return level;
            }

            for(int i = 0; i < word.size(); i++){
                char original = word[i];
                for(char ch = 'a'; ch <= 'z'; ch++){
                    word[i] = ch;
                    // If the modified word is in the wordList
                    if(st.find(word) != st.end()){
                        st.erase(word);
                        q.push({word, level + 1});
                    }
                }
                // Else get the original word back
                word[i] = original;
            }
        }

        return 0;
    }
};