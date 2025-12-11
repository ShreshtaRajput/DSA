class Solution {
private:
    bool check(int x, int y, unordered_map<int, int>& minX_on_Y,
               unordered_map<int, int>& maxX_on_Y,
               unordered_map<int, int>& minY_on_X,
               unordered_map<int, int>& maxY_on_X) {
        bool coveredVertical = (y > minY_on_X[x]) && (y < maxY_on_X[x]);
        bool coveredHorizontal = (x > minX_on_Y[y]) && (x < maxX_on_Y[y]);

        return coveredVertical && coveredHorizontal;
    }

public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int, int> minX_on_Y;
        unordered_map<int, int> maxX_on_Y;
        unordered_map<int, int> minY_on_X;
        unordered_map<int, int> maxY_on_X;

        for (const vector<int>& coords : buildings) {
            int x = coords[0];
            int y = coords[1];

            if (minY_on_X.find(x) == minY_on_X.end()) {
                minY_on_X[x] = y;
                maxY_on_X[x] = y;
            } else {
                minY_on_X[x] = min(minY_on_X[x], y);
                maxY_on_X[x] = max(maxY_on_X[x], y);
            }

            if (minX_on_Y.find(y) == minX_on_Y.end()) {
                minX_on_Y[y] = x;
                maxX_on_Y[y] = x;
            } else {
                minX_on_Y[y] = min(minX_on_Y[y], x);
                maxX_on_Y[y] = max(maxX_on_Y[y], x);
            }
        }

        int res = 0;

        for (const vector<int>& coords : buildings) {
            int x = coords[0];
            int y = coords[1];

            if (check(x, y, minX_on_Y, maxX_on_Y, minY_on_X, maxY_on_X)) {
                res++;
            }
        }

        return res;
    }
};