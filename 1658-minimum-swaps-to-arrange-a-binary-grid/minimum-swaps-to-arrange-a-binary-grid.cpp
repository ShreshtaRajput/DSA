class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<int> trailingZeroes(n, 0);
        for(int i = 0; i < n; i++){
            int trailZeroCount = 0;
            for(int j = n-1; j >= 0; j--){
                if(grid[i][j] == 0){
                    trailZeroCount++;
                }else{
                    break;
                }
            }

            trailingZeroes[i] = trailZeroCount; 
        }

        int res = 0;

        // greedily arrange rows
        for(int i = 0; i < n; i++){
            int required = n-1-i;
            int j = i;

            // These rows are not valid for the current swap
            while(j < n && trailingZeroes[j] < required){
                j++;
            }
            // If we reach the end and no suitable row is found
            if(j == n) return -1;
            // Simulating the swaps
            while(j > i){
                swap(trailingZeroes[j], trailingZeroes[j-1]);
                res++;
                j--;
            }
        }

        return res;
    }
};