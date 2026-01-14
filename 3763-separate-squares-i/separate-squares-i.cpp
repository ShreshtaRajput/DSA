class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        // Calculating the total area
        double totalArea = 0;
        double low = INT_MIN;
        double high = INT_MAX;
        for(auto &square: squares){
            double y = square[1];
            double l = square[2];

            totalArea += (l*l);
            low = min(low, y);
            high = max(high, y+l);
        }

        double target = totalArea / 2;

        double eps = 1e-6;
        while(high - low > eps){
            double mid = low + (high - low)/2;

            double areaBelow = 0;
            for(auto &square: squares){
                double y = square[1];
                double l = square[2];

                if(mid <= y){   //The sqaure is completely above the mid line
                    continue;   //No contribution to area below
                }else if(mid >= y+l){   //The square is completely below the mid line
                    areaBelow += l*l;
                }else{      //Mid line cuts the square
                    areaBelow += (mid - y) * l;
                }
            }

            if(areaBelow < target){
                low = mid;
            }else{
                high = mid;
            }
        }

        return low;
    }
};