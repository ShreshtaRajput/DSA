class Solution {
private:
    bool compare(string &str1, string &str2){
        if(str1.size() != str2.size() + 1) return false;

        int first = 0;
        int second = 0;

        while(first < str1.size()){
            if(second < str2.size() && str1[first] == str2[second]){
                first++;
                second++;
            }else{
                first++;
            }
        }

        if(first == str1.size() && second == str2.size()) return true;
        return false;
    }

public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        vector<int> dp(n, 1);
        int maxi = 1;

        // Sorting length wise
        sort(words.begin(), words.end(), [](const string &a, const string &b) {
            return a.size() < b.size();
        });

        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(compare(words[i], words[j]) && dp[j] + 1 > dp[i]){
                    dp[i] = dp[j] + 1;
                }
            }
            if(dp[i] > maxi){
                maxi = dp[i];
            }
        }

        return maxi;
    }
};