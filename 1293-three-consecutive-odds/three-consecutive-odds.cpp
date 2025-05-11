class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        if (arr.size() >= 3) {
            for (int i = 0; i < arr.size() - 2; i++) {
                if (arr[i] % 2 != 0 && arr[i + 1] % 2 != 0 &&
                    arr[i + 2] % 2 != 0) {
                    return true;
                }
            }
        }
        return false;
    }
};

// int count = 0;

// for(int i = 0; i < arr.size(); i++){
//     if(arr[i]%2 == 0){
//         count = 0;
//     }else{
//         count++;
//     }

//     if(count >= 3){
//         return true;
//     }
// }
// return false;