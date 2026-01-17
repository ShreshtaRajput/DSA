#define LL long long

class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        int maxSide = 0;

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int overlapWidth = min(topRight[i][0], topRight[j][0]) - max(bottomLeft[i][0], bottomLeft[j][0]);
                int overlapHeight = min(topRight[i][1], topRight[j][1]) - max(bottomLeft[i][1], bottomLeft[j][1]);

                maxSide = max(maxSide, min(overlapWidth, overlapHeight));
            }
        }

        return (LL)maxSide * maxSide;
    }
};