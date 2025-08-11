class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> ans;

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> pvis(n, vector<int>(m, 0));     //Visited array for pacific
        vector<vector<int>> avis(n, vector<int>(m, 0));     //Visited array for atlantic

        vector<int> delX = {-1, 0, 1, 0};
        vector<int> delY = {0, 1, 0, -1};

        queue<pair<int, int>> pq;      //pacific queue
        queue<pair<int, int>> aq;      //atlantic queue

        // Pushing the edges touched by pacific and atlantic
        for(int i = 0; i < n; i++){
            pq.push({i, 0});
            pvis[i][0] = 1;

            aq.push({i, m - 1});
            avis[i][m-1] = 1;
        }

        for(int j = 0; j < m; j++){
            pq.push({0, j});
            pvis[0][j] = 1;

            aq.push({n - 1, j});
            avis[n - 1][j] = 1;
        }

        // BFS for pacific
        while (!pq.empty()) {
            pair<int, int> front = pq.front();
            pq.pop();

            int row = front.first;
            int col = front.second;

            for (int i = 0; i < 4; i++) {
                int newRow = row + delX[i];
                int newCol = col + delY[i];

                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
                    !pvis[newRow][newCol] &&
                    heights[newRow][newCol] >= heights[row][col]) {
                    pvis[newRow][newCol] = 1;
                    pq.push({newRow, newCol});
                }
            }
        }

        // BFS for atlantic
        while (!aq.empty()) {
            pair<int, int> front = aq.front();
            aq.pop();

            int row = front.first;
            int col = front.second;

            for (int i = 0; i < 4; i++) {
                int newRow = row + delX[i];
                int newCol = col + delY[i];

                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
                    !avis[newRow][newCol] &&
                    heights[newRow][newCol] >= heights[row][col]) {
                    avis[newRow][newCol] = 1;
                    aq.push({newRow, newCol});
                }
            }
        }

        // Intersection of both cells in both pacific and atlantic
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(pvis[i][j] && avis[i][j]){
                    ans.push_back({i,j});
                }
            }
        }

        return ans;
    }
};