class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if(arr[start] == 0){
            return true;
        }

        int jump = arr[start];
        arr[start] = -1;    //Mark as visited

        bool val1 = false;
        if(start - jump >= 0 && arr[start - jump] != -1){
            val1 = canReach(arr, start - jump);
        }

        bool val2 = false;
        if(start + jump < arr.size() && arr[start + jump] != -1){
            val2 = canReach(arr, start + jump);
        }

        return val1 || val2;
    }
};