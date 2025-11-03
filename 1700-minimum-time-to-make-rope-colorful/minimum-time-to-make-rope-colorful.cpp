class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int count = 0;

        for(int i = 0; i < colors.size() - 1; i++){
            if(colors[i] == colors[i+1]){
                count += min(neededTime[i], neededTime[i+1]);
                neededTime[i+1] = max(neededTime[i], neededTime[i+1]);
            }
        }

        return count;
    }
};

// for(int i = 0; i < colors.size() - 1; i++){
//     if(colors[i] == colors[i+1]){
//         if(neededTime[i] > neededTime[i+1]){
//             colors.erase(i+1);
//             count += neededTime[i+1];
//             neededTime.erase(neededTime.begin() + i+1);
//         }else{
//             colors.erase(i);
//             count += neededTime[i];
//             neededTime.erase(neededTime.begin() + i);
//         }
//     }
// }