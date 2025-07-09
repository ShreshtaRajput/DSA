class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        // First create a vector that has all the durations of the free time available
        vector<int> freeTime;
        int n = startTime.size();

        // Insert the first free time, which may start from 0
        freeTime.push_back(startTime[0] - 0);

        for(int i = 1; i < n; i++){
            freeTime.push_back(startTime[i] - endTime[i - 1]);
        }

// Add the free time which may occur after all the events are done but we still have time(eventTime)
        freeTime.push_back(eventTime - endTime.back());

        int maxFree = 0;
        int winSize = k + 1;
        int left = 0;
        int sum = 0;

        for(int right = 0; right < freeTime.size(); right++){
            sum += freeTime[right];

            // If window size exceeded -> left ko aage badhao
            if(right - left + 1 > winSize){
                sum -= freeTime[left];
                left++;
            }
            // If window size is matched -> check if we have the maximum time
            if(right - left + 1 == winSize){
                maxFree = max(maxFree, sum);
            }
        }

        return maxFree;
    }
};