class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int x = 0, y = 0, cur = 0;
        for (int d : differences) {
            cur += d;
            x = min(x, cur);
            y = max(y, cur);
            if (y - x > upper - lower) {
                return 0;
            }
        }
        return (upper - lower) - (y - x) + 1;
    }
};

// class Solution {
// public:
//     int numberOfArrays(vector<int>& differences, int lower, int upper) {
//         int count = 0;
//         int n = differences.size();

//         for(int i = lower; i <= upper; i++){
//             long current = i;
//             bool isValid = true;

//             for(int j = 0; j < n; j++){
//                 current += differences[j];

//                 if(current < lower || current > upper){
//                     isValid = false;
//                     break;
//                 }
//             }

//             if(isValid){
//                 count++;
//             }
//         }
//         return count;
//     }
// };