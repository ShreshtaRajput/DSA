class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string res = "";

        for(auto word: words){
            int weight = 0;
            for(auto ch: word){
                int w = weights[ch - 'a'];
                weight += w;
            }

            int finalWeight = weight % 26;
            res += (26-finalWeight-1) + 'a';
        }

        return res;
    }
};