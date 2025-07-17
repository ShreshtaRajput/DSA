class Solution {
private:
    void topoSort(vector<vector<int>>& prerequisites, vector<int>& topoArray,
                  int numCourses) {
        int n = prerequisites.size();
        vector<int> indegree(numCourses, 0);

        for (int i = 0; i < n; i++) {
            indegree[prerequisites[i][0]]++;
        }

        vector<vector<int>> adjList(numCourses);

        for(auto edge: prerequisites){
            int course = edge[0];
            int prereq = edge[1];

            adjList[prereq].push_back(course);
        }

        queue<int> q;
        for (int i = 0; i < adjList.size(); i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topoArray.push_back(node);

            for(auto adjNode: adjList[node]){
                indegree[adjNode]--;
                if(indegree[adjNode] == 0){
                    q.push(adjNode);
                }
            }
        }
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(prerequisites.size() == 0){
            return true;
        }

        vector<int> topoArray;

        topoSort(prerequisites, topoArray, numCourses);

        if (topoArray.size() == numCourses) {
            return true;
        }

        return false;
    }
};