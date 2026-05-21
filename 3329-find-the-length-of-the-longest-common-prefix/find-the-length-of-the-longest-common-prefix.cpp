class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> arr1Prefix;

        for(int i = 0; i < arr1.size(); i++){
            while(!arr1Prefix.count(arr1[i]) && arr1[i] > 0){
                arr1Prefix.insert(arr1[i]);
                arr1[i] /= 10;
            }
        }

        int res = 0;

        for(int i = 0; i < arr2.size(); i++){
            while(!arr1Prefix.count(arr2[i]) && arr2[i] > 0){
                arr2[i] /= 10;
            }
            if(arr2[i] > 0){
                int digits = 0;
                int temp = arr2[i];

                while(temp > 0){
                    digits++;
                    temp /= 10;
                }

                res = max(res, digits);
            }
        }

        return res;
    }
};