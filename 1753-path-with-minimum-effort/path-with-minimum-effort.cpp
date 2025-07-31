class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        // {diff, {row, col}} 
        priority_queue<pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>> pq;

        // Vector to store the difference in effort
        vector<vector<int>> diff(n, vector<int>(m, 1e9));

        vector<int> delRow = {-1, 0, 1, 0};
        vector<int> delCol = {0, 1, 0, -1};

        diff[0][0] = 0;
        pq.push({0, {0, 0}});

        while(!pq.empty()){
            pair<int, pair<int, int>> node = pq.top();
            int dif = node.first;
            int row = node.second.first;
            int col = node.second.second;

            pq.pop();

            // If the target node is reached => return the effort
            if(row == n - 1 && col == m - 1){
                return dif;
            }

            for(int i = 0; i < 4; i++){
                int newRow = row + delRow[i];
                int newCol = col + delCol[i];

                // checking the validity of new row and new col
                if(newRow < n && newRow >= 0 && newCol < m && newCol >= 0){
                    int newEffort = max(abs(heights[newRow][newCol] - heights[row][col]), dif);
                    // If the new effort is less than from that of previous paths
                    if(newEffort < diff[newRow][newCol]){
                        diff[newRow][newCol] = newEffort;
                        pq.push({newEffort, {newRow, newCol}});
                    }
                }
            }
        }

        return -1; //Unreachable
    }
};