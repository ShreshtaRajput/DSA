class Solution {
private:
    bool isPossible(vector<int>& ranks, int cars, long long middle){
        long long totalCount = 0;
        for(int i = 0; i < ranks.size(); i++){
            totalCount += sqrt(middle/ranks[i]);
        }

        return totalCount >= cars;
    }
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long left = 0;

        int maxRank = *max_element(ranks.begin(), ranks.end());
        long long right = static_cast<long long>(maxRank) * cars * cars;

        while(left < right){
            long long middle = left + (right - left)/2;

            if(isPossible(ranks, cars, middle)){
                right = middle;
            }else{
                left = middle + 1;
            }
        }

        return left;
    }
};