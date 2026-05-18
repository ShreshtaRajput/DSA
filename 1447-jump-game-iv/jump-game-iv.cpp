class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();

        unordered_map<int, vector<int>> idxToVal;
        vector<bool> visited(n, false);
        queue<int> q;

        q.push(0);
        visited[0] = true;
        for(int i = 0; i < n; i++){
            idxToVal[arr[i]].push_back(i);
        }
        int steps = 0;

        // int minSteps = INT_MAX;
        // dfs(0, 0, arr, visited, idxToVal, minSteps);

        // return minSteps;

        while(!q.empty()){
            int level = q.size();

            for(int i = 0; i < level; i++){
                int curr = q.front();
                q.pop();

                if(curr == n-1) return steps;

                // Jump forward
                if(curr + 1 < n && !visited[curr + 1]){
                    visited[curr + 1] = true;
                    q.push(curr + 1);
                }

                // Jump backward
                if(curr - 1 >= 0 && !visited[curr - 1]){
                    visited[curr - 1] = true;
                    q.push(curr - 1);
                }

                // Teleport
                for(int j = idxToVal[arr[curr]].size() - 1; j >= 0; j--){
                    int nextIdx = idxToVal[arr[curr]][j];
                    if(!visited[nextIdx] && nextIdx != curr){
                        visited[nextIdx] = true;
                        q.push(nextIdx);
                    }
                }

                idxToVal[arr[curr]].clear();    //Clear the map for current val, to skip the re-looking of same element agaain and again
            }

            steps++;
        }

        return -1;
    }
};

// private:
//     void dfs(int curr, int step, vector<int> &arr, vector<bool> &visited, unordered_map<int, vector<int>> &idxToVal, int &minSteps){
//         if(curr == arr.size() - 1){
//             minSteps = min(step, minSteps);
//             return;
//         }

//         // Jump forward
//         if(curr + 1 < arr.size() && !visited[curr + 1]){
//             visited[curr + 1] = true;
//             dfs(curr + 1, step + 1, arr, visited, idxToVal, minSteps);
//             visited[curr + 1] = false;  //Backtrack
//         }

//         // Jump backward
//         if(curr - 1 >= 0 && !visited[curr - 1]){
//             visited[curr - 1] = true;
//             dfs(curr - 1, step + 1, arr, visited, idxToVal, minSteps);
//             visited[curr - 1] = false;  //Backtrack
//         }

//         // Teleport
//         for(int i = idxToVal[arr[curr]].size() - 1; i >= 0; i--){
//             int nextIdx = idxToVal[arr[curr]][i];
//             if(nextIdx != curr && !visited[nextIdx]){
//                 visited[nextIdx] = true;
//                 dfs(nextIdx, step + 1, arr, visited, idxToVal, minSteps);
//                 visited[nextIdx] = false;
//             }
//         }
//     }