class Solution {
private:
    string rle(const string &str){
        string res = "";
        int i = 0;

        while(i < str.size()){
            unordered_map<char, int> mp;
            int count = 1;

            // Map mai equal entries but not consecutive, ek saath nhi aani chaiye
            while(i + 1 < str.size() && str[i] == str[i+1]){
                count++;
                i++;
            }

            mp[str[i]] = count;

            for(auto& i: mp){
                string temp = to_string(i.second) + i.first;
                res += temp;
            }

            i++;
        }

        // string countStr = "";
        // string something = "";
        // for(auto& i: mp){
        //     countStr = to_string(i.second);
        //     string temp = countStr + i.first;
        //     something += temp;
        // }
        return res;
    }
public:
    string countAndSay(int n) {
        // Base case
        if(n == 1){
            return "1";
        }

        return rle(countAndSay(n-1));
    }
};