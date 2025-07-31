class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> distance(n, vector<int>(m, 1e9));

        vector<int> delRow = {-1, -1, -1, 0, 1, 1, 1, 0};
        vector<int> delCol = {-1, 0, 1, 1, 1, 0, -1, -1};

        distance[0][0] = 1;

        // Queue to store the {distance,{row, col}}
        queue<pair<int,pair<int, int>>> q;
        // Adding initial distance = 0 at {0,0}
        q.push({1, {0, 0}});

        // Check for the edge cases
        // The origin block is 1
        if(grid[0][0] == 1){
            return -1;
        }

        while(!q.empty()){
            pair<int,pair<int, int>> node = q.front();
            int dis = node.first;
            int row = node.second.first;
            int col = node.second.second;

            q.pop();

            for(int i = 0; i < 8; i++){
                int newRow = row + delRow[i];
                int newCol = col + delCol[i];
                // Validate the newRow and newCol ans check for the given conditions
                if(newRow < n && newRow >= 0 && newCol < n && newCol >= 0 &&
                grid[newRow][newCol] == 0 && distance[newRow][newCol] > dis + 1){
                    distance[newRow][newCol] = dis + 1;
                    q.push({distance[newRow][newCol], {newRow, newCol}});
                }
            }
        }

        // If the last cell is unreachable, return -1
        if(distance[n-1][m-1] == 1e9){
            return -1;
        }

        return distance[n-1][m-1];
    }
};