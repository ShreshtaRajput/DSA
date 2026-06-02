class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();

        int res = INT_MAX;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                // Land to water
                int landFinish = landStartTime[i] + landDuration[i];
                int waterStart = max(landFinish, waterStartTime[j]);

                res = min(res, waterStart + waterDuration[j]);

                // Water to land
                int waterFinish = waterStartTime[j] + waterDuration[j];
                int landStart = max(waterFinish, landStartTime[i]);

                res = min(res, landStart + landDuration[i]);
            }
        }

        return res;
    }
};