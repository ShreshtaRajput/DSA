class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> tempVector;

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                tempVector.push_back(grid[i][j]);
            }
        }

        sort(tempVector.begin(), tempVector.end());

        int medianElement = tempVector[tempVector.size() / 2];

        int i = 0;
        int count = 0;
        while( i < tempVector.size() ){
            // int noOfOperations = tempVector[i]/x;
            // if(tempVector[i] % x != 0){
            //     return -1;
            // }

            // if(tempVector[i] < medianElement){
            //     int newEle = tempVector[i] + x;
            // }

            int diff = abs(tempVector[i] - medianElement);

            if(diff % x != 0){
                return -1;
            }

            count += diff / x;
            i++;
        }

        return count;
    }
};