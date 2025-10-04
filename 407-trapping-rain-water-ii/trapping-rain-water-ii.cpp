class Solution {
vector<int> delX = {0, 1, 0, -1};
vector<int> delY = {-1, 0, 1, 0};
private:
    bool isValid(int row, int col, int n, int m){
        return (row < n && row >= 0 && col < m && col >= 0);
    }
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n = heightMap.size();
        int m = heightMap[0].size();

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        // Add the elements from the edges to the pq first, as they will not contribute to the volume
        // From there we can consider multi-source BFS
        // Adding the elements from the first and last row
        for(int j = 0; j < m; j++){
            pq.push({heightMap[0][j],{0, j}});
            vis[0][j] = 1;
            pq.push({heightMap[n-1][j], {n-1, j}});
            vis[n-1][j] = 1;
        }
        // Adding the elements from the first and last col
        for(int i = 1; i < n-1; i++){
            pq.push({heightMap[i][0], {i, 0}});
            vis[i][0] = 1;
            pq.push({heightMap[i][m-1], {i, m-1}});
            vis[i][m-1] = 1;
        }

        int res = 0;

        while(!pq.empty()){
            int h = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();

            for(int i = 0; i < 4; i++){
                int newX = x + delX[i];
                int newY = y + delY[i];

                if(!isValid(newX, newY, n, m) || vis[newX][newY]) continue; //Skip them
                vis[newX][newY] = 1;

                if(heightMap[newX][newY] < h){
                    res += h - heightMap[newX][newY];
                }
                pq.push({max(h, heightMap[newX][newY]), {newX, newY}});
            }
        }

        return res;
    }
};