class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        // We will have to move diagonally as much as possible to cover more distance in lesser time
        int n = points.size();
        int time = 0;

        for(int i = 1; i < n; i++){
            int currx = points[i-1][0];
            int curry = points[i-1][1];

            int nextx = points[i][0];
            int nexty = points[i][1];

            int xDis = abs(currx - nextx);
            int yDis = abs(curry - nexty);

            // Trying moving diagonally first
            while(xDis > 0 && yDis > 0){
                time += 1;
                xDis--;
                yDis--;
            }
            // After moving diagonally we can move vertically  or horizontally
            while(xDis > 0 || yDis > 0){
                if(xDis == 0){
                    time += 1;
                    yDis--;
                }else{
                    time += 1;
                    xDis--;
                }
            }
        }

        return time;
    }
};