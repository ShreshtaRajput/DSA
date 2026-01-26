class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        vector<vector<int>> res;
        int minDiff = INT_MAX;

        for(int i = 0; i < arr.size() - 1; i++){
            int a = arr[i];
            int b = arr[i+1];

            if(abs(b-a) < minDiff){
                minDiff = abs(b-a);
                res.clear();
                res.push_back({a,b});
            }else if(abs(b-a) == minDiff){
                res.push_back({a,b});
            }
        }

        return res;
    }
};