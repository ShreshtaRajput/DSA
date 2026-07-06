class Solution {
private:
    static bool comp(vector<int> &a, vector<int> &b){
        if(a[0] == b[0]){
            return a[1] > b[1];
        }else{
            return a[0] < b[0];
        }
    }
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n= intervals.size();

        sort(intervals.begin(), intervals.end(), comp);
        int removeIntervals = 0;

        int i = 0;
        while(i < n-1){
            auto first = intervals[i];
            auto second = intervals[i+1];

            if(first[1] >= second[1]){
                removeIntervals++;
                intervals[i+1] = first;
            }
            i++;
        }

        return n - removeIntervals;
    }
};