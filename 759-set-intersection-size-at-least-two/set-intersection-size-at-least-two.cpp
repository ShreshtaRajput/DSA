class Solution {
private:
    static bool compare(const vector<int> &v1, const vector<int> &v2){
        // Comparing based on the second element in the interval
        return v1[1] < v2[1];
    }
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);

        int prev1 = intervals[0][1] - 1;
        int prev2 = intervals[0][1];
        int count = 2;

        for(int i = 1; i < intervals.size(); i++){
            int start = intervals[i][0];
            int end = intervals[i][1];

            if(prev2 < start){
                // the highest elements from the previous intervals cannot be a part of the next interval
                prev1 = end - 1;
                prev2 = end;
                count += 2;     //This adds 2 elements to the final length
            }else if(prev1 < start){
                // There is still a chance that prev2 is still in the range of next interval
                if(prev2 == end){
                    prev1 = end - 1;    //give the prev1, the second largest value in of the next interval
                }else{
                    prev1 = end;    //else give it the highest value
                    // after this step there is a chance that prev1 becomes greater than prev2, so swap them
                    if(prev1 > prev2) swap(prev1, prev2);
                }

                count += 1;     //This adds 1 element to the final length
            }
        }

        return count;
    }
};