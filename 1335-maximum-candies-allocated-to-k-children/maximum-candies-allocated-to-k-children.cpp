class Solution {
private:
    bool isPossible(vector<int>& candies, long long k, long long numOfCandies){
        long long maxChild = 0;
        for(int i = 0; i < candies.size(); i++){
            maxChild += candies[i] / numOfCandies;
        }

        return maxChild >= k;
    }

public:
    int maximumCandies(vector<int>& candies, long long k) {
        int maxi = 0;

        for(int i = 0; i < candies.size(); i++){
            maxi = max(maxi, candies[i]);
        }

        int left = 0;
        int right = maxi;

        while(left < right){
            int middle = (left + right + 1)/ 2;

            if(isPossible(candies, k, middle)){
                left = middle;
            }else{
                right = middle - 1;
            }
        }

        return left;
    }
};