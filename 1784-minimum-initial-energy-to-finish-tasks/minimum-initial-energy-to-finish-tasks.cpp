class Solution {
private:
    static bool compare(vector<int> &a, vector<int> &b){
        // Sort in descending order of (actual - min)
        return a[1] - a[0] > b[1] - b[0];
    }

    bool isValid(int start, vector<vector<int>> &tasks){
        int curr = start;

        for(auto &task: tasks){
            int actual = task[0];
            int mini = task[1];

            if(curr < mini){
                // Cannot start the task
                return false;
            }

            curr -= actual;
        }

        return true;
    }
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), compare);

        int low = 0;
        int high = 1e9;
        int ans = high;

        while(low <= high){
            int mid = low + (high - low)/2;

            if(isValid(mid, tasks)){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }

        return ans;
    }
};