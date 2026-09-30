class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.size();
        vector<int> res;
        
        int bal = 0;
        for(int i = 0; i < n; i++){
            if(seq[i] == '('){
                bal++;
                res.push_back(bal % 2);
            }else{
                res.push_back(bal % 2);
                bal--;
            }
        }

        return res;
    }
};