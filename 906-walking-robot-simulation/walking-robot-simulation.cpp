class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int,int>> obs;
        for (auto &o : obstacles) {
            obs.insert({o[0], o[1]});
        }

        // Directions: North, East, South, West
        vector<pair<int,int>> dirs = {
            {0, 1}, {1, 0}, {0, -1}, {-1, 0}
        };

        int d = 0; // start facing North
        int x = 0, y = 0;
        int maxDist = 0;

        for (int cmd : commands) {
            if (cmd == -1) {
                // turn right
                d = (d + 1) % 4;
            } 
            else if (cmd == -2) {
                // turn left
                d = (d + 3) % 4;
            } 
            else {
                // move step by step
                for (int i = 0; i < cmd; i++) {
                    int nx = x + dirs[d].first;
                    int ny = y + dirs[d].second;

                    // check obstacle
                    if (obs.count({nx, ny})) break;

                    // move
                    x = nx;
                    y = ny;

                    // update max distance
                    maxDist = max(maxDist, x*x + y*y);
                }
            }
        }

        return maxDist;
    }
};