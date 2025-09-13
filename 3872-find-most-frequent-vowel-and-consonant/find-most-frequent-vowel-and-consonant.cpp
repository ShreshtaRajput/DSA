class Solution {
private:
    bool isVowel(char &ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
public:
    int maxFreqSum(string s) {
        unordered_map<char, int> vowels;
        unordered_map<char, int> conso;

        for(char ch: s){
            if(isVowel(ch)){
                vowels[ch]++;
            }else{
                conso[ch]++;
            }
        }

        int mostFreqVowel = 0, mostFreqConso = 0;
        for(auto p: vowels){
            mostFreqVowel = max(mostFreqVowel, p.second);
        }
        for(auto p: conso){
            mostFreqConso = max(mostFreqConso, p.second);
        }

        return mostFreqVowel + mostFreqConso;
    }
};