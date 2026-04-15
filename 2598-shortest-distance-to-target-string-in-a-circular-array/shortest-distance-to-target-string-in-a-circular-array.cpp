class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int res = INT_MAX;
        int n = words.size();

        for(int i = 0; i < n; i++){
            if(words[i] == target){
                int dis = abs(i - startIndex);
                res = min(res, min(dis, n-dis));
            }
        }

        if(res != INT_MAX) return res;
        else return -1;
    }
};