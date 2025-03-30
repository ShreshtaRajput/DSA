class Solution {
public:
    vector<int> partitionLabels(string s) {
        // Storing the last occurence of each character
        vector<int> lastOccurence(26,0);
        for(int i = 0; i < s.size(); ++i){
            lastOccurence[s[i] - 'a'] = i;
        }

        // Making partitions
        int st = 0;
        int e = 0;
        vector<int> ans;
        for(int i = 0; i < s.size(); ++i){
            e = max(e, lastOccurence[s[i] - 'a']);

            if(i == e){
                int size = i - st + 1;
                ans.push_back(size);
                st = i + 1;
            }
        }

        return ans;
    }
};