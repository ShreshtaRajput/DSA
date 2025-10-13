class Solution {
private:
    bool isAnagram(vector<string> &words, int prevIndex, int index){
        string str1 = words[prevIndex];
        string str2 = words[index];

        if(str1.size() != str2.size()){
            return false;
        }

        sort(str1.begin(), str1.end());
        sort(str2.begin(), str2.end());

        return str1 == str2;
    }
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> res = {words[0]};

        for(int i = 1; i < words.size(); i++){
            if(isAnagram(words, i-1, i)){
                continue;
            }

            res.push_back(words[i]);
        }

        return res;
    }
};