class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        vector<int> res;

        int n = security.size();

        vector<int> nonInc(n);
        vector<int> nonDec(n);

        // Filling up the nonInc array
        for(int i = 1; i < n; i++){
            if(security[i] <= security[i-1]){
                nonInc[i] = nonInc[i-1] + 1;
            }else{
                nonInc[i] = 0;
            }
        }

        // Filling up the nonDec array
        for(int i = n-2; i >= 0; i--){
            if(security[i] <= security[i+1]){
                nonDec[i] = nonDec[i+1] + 1;
            }else{
                nonDec[i] = 0;
            }
        }

        for(int i = 0; i < n; i++){
            if(nonInc[i] >= time && nonDec[i] >= time){
                res.push_back(i);
            }
        }

        return res;
    }
};