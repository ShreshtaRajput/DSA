class Solution {
private:
    int dfs(int node, int parentNode, vector<vector<int>> &adjList, vector<int> &values, int k, int &compoCount){
        int sum = 0;

        for(auto neighbor: adjList[node]){
            if(neighbor != parentNode){
                // Process the neighbors of the node
                sum += dfs(neighbor, node, adjList, values, k, compoCount);
                sum %= k;   //determine if the sum is divisible by k
            }
        }

        // Add the current node value
        sum += values[node];
        sum %= k;
        // Determine if still  divisible by k
        if(sum == 0) compoCount++;

        // Return the sum
        return sum;
    }
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adjList(n);

        for(auto &edge: edges){
            int node1 = edge[0];
            int node2 = edge[1];

            adjList[node1].push_back(node2);
            adjList[node2].push_back(node1);
        }

        int compoCount = 0;

        dfs(0, -1, adjList, values, k, compoCount);

        return compoCount;
    }
};