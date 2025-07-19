class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> ans;

        int i = 0;
        while (i < folder.size()) {
            string curr = folder[i];
            ans.push_back(curr);
            i++;

            // Skip all the subfolders of curr
            while (i < folder.size() &&
                   folder[i].substr(0, curr.size()) == curr &&
                   folder[i].size() > curr.size() &&
                   folder[i][curr.size()] == '/') {
                i++;
            }
        }

        return ans;
    }
};

// for(int i = 0; i < folder.size() - 1; i++){
//     string substr = folder[i];
//     int len = substr.size();

//     ans.push_back(substr);

//     string next = folder[i+1];

//     if(next.size() >= len && next.substr(0, len) != substr){
//         ans.push_back(next);
//     }else{
//         continue;
//     }
// }