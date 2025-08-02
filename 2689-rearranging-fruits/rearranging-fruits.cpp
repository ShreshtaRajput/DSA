class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> map;
        int mini = INT_MAX;

        // Making a map in which the count of the cost is stored as basket1[cost] - basket2[cost]
        // If there is any element that is extra in basket1, then there will be a positive value in map
        // If there is any element that is extra in basket2, then there will be a negative value in map

        // We are also storing the minimum element from both arrays, which will be used in swapping
        for(auto fruit: basket1){
            map[fruit]++;
            mini = min(mini, fruit);
        }

        for(auto fruit: basket2){
            map[fruit]--;
            mini = min(mini, fruit);
        }

        // This array will consist of elements that need to be swapped
        // We  will store only half of the frequency of those elements
        // Since when we will swap them, there only needs to be half the swaps to maintain the balance
        vector<int> toSwap;

        for(auto &p: map){
            int count = p.second;
            int cost = p.first;

            // If there are any odd number of elements making the impossible case
            if(count % 2 != 0){
                return -1;
            }

            if(count == 0) continue;
            // storing the elements with half their frequency
            for(int i = 1; i <= abs(count)/2; i++){
                toSwap.push_back(cost);
            }
        }
        // Sorting to get the minimum elements ahead to minimize the cost
        sort(toSwap.begin(), toSwap.end());
        long long totalCost = 0;

        // Only need to perform half the number of swaps (rest are symmetric).
        for(int i = 0; i < toSwap.size()/2; i++){
            // Now the total cost is calculated using the mini element we calculated eariler
            // Using it as helper
            // For eg: toSwap = {1,2,5,7,8,9} we will use '1' as the helper here
            // we will swap (1, 1*2) => minCost = 1
            // Then swap (2, 1*2) => minCost = 2
            // Then swap (5, 1*2) => minCost = 2
            // Totalcost = 1 + 2 + 2 = 5
            totalCost += min(toSwap[i], mini * 2);
        }

        return totalCost;
    }
};