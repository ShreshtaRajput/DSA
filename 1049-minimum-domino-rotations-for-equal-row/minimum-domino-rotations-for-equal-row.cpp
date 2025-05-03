class Solution {
private:
    int getMaxFreqNumber(vector<int>& nums) {
        unordered_map<int, int> mp;
        int maxFreq = 0, numWithMaxFreq = -1;

        for (int num : nums) {
            mp[num]++;
            if (mp[num] > maxFreq) {
                maxFreq = mp[num];
                numWithMaxFreq = num;
            }
        }

        return numWithMaxFreq;
    }

    int check(int x, vector<int>& tops, vector<int>& bottoms) {
        int topRotate = 0, bottomRotate = 0;

        for (int i = 0; i < tops.size(); i++) {
            // not possible in this condition
            if (tops[i] != x && bottoms[i] != x) {
                return -1;
            } else if (tops[i] != x) {
                topRotate++;
            } else if (bottoms[i] != x) {
                bottomRotate++;
            }
        }
        return min(topRotate, bottomRotate);
    }

public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();

        int maxFreqnum1 = getMaxFreqNumber(tops);
        int maxFreqnum2 = getMaxFreqNumber(bottoms);

        int res1 = check(maxFreqnum1, tops, bottoms);
        int res2 = check(maxFreqnum2, tops, bottoms);

        // Not possible for both arrays
        if (res1 == -1 && res2 == -1){
            return -1;
        }
        // Not possible for tops array
        else if (res1 == -1){
            return res2;
        }
        // Not possible for bottoms array
        else if (res2 == -1){
            return res1;
        }
        // Possible for both
        else{
            return min(res1, res2);
        }
    }
};