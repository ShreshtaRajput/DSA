class SegmentTree {
private:
    vector<int> count;
    vector<int> covered;
    vector<int> xs;
    int n;

    void modify(int qleft, int qright, int qval, int left, int right, int pos) {
        if (xs[right + 1] <= qleft || xs[left] >= qright) {
            return;
        }
        if (qleft <= xs[left] && xs[right + 1] <= qright) {
            count[pos] += qval;
        } else {
            int mid = (left + right) / 2;
            modify(qleft, qright, qval, left, mid, pos * 2 + 1);
            modify(qleft, qright, qval, mid + 1, right, pos * 2 + 2);
        }

        if (count[pos] > 0) {
            covered[pos] = xs[right + 1] - xs[left];
        } else {
            if (left == right) {
                covered[pos] = 0;
            } else {
                covered[pos] = covered[pos * 2 + 1] + covered[pos * 2 + 2];
            }
        }
    }

public:
    SegmentTree(vector<int>& xs_) : xs(xs_) {
        n = xs.size() - 1;
        count.resize(4 * n, 0);
        covered.resize(4 * n, 0);
    }

    void update(int qleft, int qright, int qval) {
        modify(qleft, qright, qval, 0, n - 1, 0);
    }

    int query() { return covered[0]; }
};

class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        vector<tuple<int, int, int, int>> events;
        set<int> xsSet;

        for (auto& sq : squares) {
            int x = sq[0], y = sq[1], l = sq[2];
            int xr = x + l;
            events.emplace_back(y, 1, x, xr);
            events.emplace_back(y + l, -1, x, xr);
            xsSet.insert(x);
            xsSet.insert(xr);
        }

        // sort events by y-coordinate
        sort(events.begin(), events.end());
        // discrete coordinates
        vector<int> xs(xsSet.begin(), xsSet.end());
        // initialize the segment tree
        SegmentTree segTree(xs);

        vector<double> psum;
        vector<int> widths;
        double total_area = 0.0;
        int prev = get<0>(events[0]);

        // scan: calculate total area and record intermediate states
        for (auto& [y, delta, xl, xr] : events) {
            int len = segTree.query();
            total_area += 1LL * len * (y - prev);
            segTree.update(xl, xr, delta);
            // record prefix sums and widths
            psum.push_back(total_area);
            widths.push_back(segTree.query());
            prev = y;
        }

        // calculate the target area (half rounded up)
        long long target = (long long)(total_area + 1) / 2;
        // find the first position greater than or equal to target using binary
        // search
        int i =
            lower_bound(psum.begin(), psum.end(), target) - psum.begin() - 1;
        // get the corresponding area, width, and height
        double area = psum[i];
        int width = widths[i], height = get<0>(events[i]);

        return height + (total_area - area * 2) / (width * 2.0);
    }
};

// class Solution {
// private:
//     double sumArea(vector<vector<double>>& rectangles) {
//         // Step 1: Collect all y-boundaries
//         vector<double> yCoords;
//         for (auto &r : rectangles) {
//             yCoords.push_back(r[1]); // bottom
//             yCoords.push_back(r[3]); // top
//         }

//         // Sort and remove duplicates
//         sort(yCoords.begin(), yCoords.end());
//         yCoords.erase(unique(yCoords.begin(), yCoords.end()), yCoords.end());

//         double totalArea = 0;

//         // Step 2: Process each horizontal strip
//         for (int i = 0; i + 1 < yCoords.size(); i++) {
//             double yBottom = yCoords[i];
//             double yTop = yCoords[i + 1];
//             double stripHeight = yTop - yBottom;

//             if (stripHeight == 0) continue;

//             // Step 3: Find x-intervals covering this strip
//             vector<pair<double,double>> xIntervals;
//             for (auto &r : rectangles) {
//                 if (r[1] <= yBottom && r[3] >= yTop) {
//                     xIntervals.push_back({r[0], r[2]});
//                 }
//             }

//             if (xIntervals.empty()) continue;

//             // Step 4: Merge x-intervals
//             sort(xIntervals.begin(), xIntervals.end());

//             double coveredWidth = 0;
//             double currentLeft = xIntervals[0].first;
//             double currentRight = xIntervals[0].second;

//             for (int j = 1; j < xIntervals.size(); j++) {
//                 double nextLeft = xIntervals[j].first;
//                 double nextRight = xIntervals[j].second;

//                 if (nextLeft > currentRight) {
//                     // Disjoint interval
//                     coveredWidth += currentRight - currentLeft;
//                     currentLeft = nextLeft;
//                     currentRight = nextRight;
//                 } else {
//                     // Overlapping interval
//                     currentRight = max(currentRight, nextRight);
//                 }
//             }

//             // Add last interval
//             coveredWidth += currentRight - currentLeft;

//             // Step 5: Add strip area
//             totalArea += coveredWidth * stripHeight;
//         }

//         return totalArea;
//     }


//     double areaBelow(double y, vector<vector<int>> &squares){
//         vector<vector<double>> rects;
//         for(auto &s: squares){
//             double x = s[0];
//             double y0 = s[1];
//             double l = s[2];

//             if(y <= y0){    //Square is above
//                 continue;
//             }else{
//                 rects.push_back({x, y0, x+l, min(y, y0 + l)});
//             }
//         }

//         return sumArea(rects);
//     }
// public:
//     double separateSquares(vector<vector<int>>& squares) {
//         double low = 1e18;
//         double high = -1e18;

//         vector<vector<double>> fullRects;
//         for(auto &sq: squares){
//             double x = sq[0];
//             double y = sq[1];
//             double l = sq[2];

//             low = min(low, y);
//             high = max(high, y+l);
//             fullRects.push_back({x, y, x+l, y+l});
//         }

//         double target = sumArea(fullRects)/2;
//         double esp = 1e-6;

//         while(high - low > esp){
//             double mid = low + (high - low)/2;

//             if(areaBelow(mid, squares) < target){
//                 low = mid;
//             }else{
//                 high = mid;
//             }
//         }

//         return low;
//     }
// };