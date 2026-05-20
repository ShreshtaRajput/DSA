class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> res(n);
        unordered_set<int> stA, stB;

        for(int i = 0; i < n; i++){
            stA.insert(A[i]);
            stB.insert(B[i]);

            int common = 0;

            for(int ele: stA){
                if(stB.count(ele)){
                    common++;
                }
            }

            res[i] = common;
        }

        return res;
    }
};