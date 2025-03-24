class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        int n = meetings.size();
        int count = 0;
        int latestEnd = 0;

        for (int i = 0; i < n; i++) {
            int start = meetings[i][0], end = meetings[i][1];

            if (start > latestEnd + 1) {
                count += start - (latestEnd + 1);
            }

            latestEnd = max(latestEnd, end);
        }

        count += days - latestEnd;

        return count;
    }
};