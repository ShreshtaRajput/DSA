class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long res = 0;
        int n = workerTimes.size();

        // pq will have the data as {finish_time, w, k}
        priority_queue<vector<long long>, vector<vector<long long>>, greater<vector<long long>>> pq;

        // Initial push
        for(int i = 0; i < n; i++){
            pq.push({workerTimes[i], workerTimes[i], 1});
        }

        for(int i = 0; i < mountainHeight; i++){
            auto curr = pq.top();
            pq.pop();

            long long finish_time = curr[0];
            long long w = curr[1];
            long long k = curr[2];

            res = finish_time;

            long long next_finish = finish_time + (k+1) * w;
            pq.push({next_finish, w, k+1});
        }

        return res;
    }
};