class Solution {
private:
    int compare(string &word, string &query){
        int cnt = 0;
        for(int i = 0; i < word.size(); i++){
            if(word[i] != query[i]){
                cnt++;
            }
        }
        return cnt;
    }
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> res;

        for(auto query: queries){
            for(auto word: dictionary){
                int comps = compare(word, query);
                if(comps <= 2){
                    res.push_back(query);
                    break;
                }
            }
        }

        return res;
    }
};