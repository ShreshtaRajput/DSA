class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int> copy(n);
        unordered_map<int, int> rankMap;

        if(n == 0) return arr;

        for(int i = 0; i < n; i++){
            copy[i] = arr[i];
        }

        sort(copy.begin(), copy.end());

        int rank = 1;
        rankMap[copy[0]] = rank;
        for(int i = 1; i < n; i++){
            if(copy[i] > copy[i-1]){
                rank++;
            }
            rankMap[copy[i]] = rank;
        }

        for(int i = 0; i < n; i++){
            arr[i] = rankMap[arr[i]];
        }

        return arr;
    }
};