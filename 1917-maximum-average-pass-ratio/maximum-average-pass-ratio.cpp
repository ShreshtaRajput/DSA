class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();

        priority_queue<pair<double, int>> pq;

        for(int i = 0; i < n; i++){
            double currRatio = (double)classes[i][0]/classes[i][1];
            double newRatio = (double)(classes[i][0] + 1)/(classes[i][1] + 1);

            double diff = newRatio - currRatio;

            pq.push({diff, i});
        }

        while(extraStudents){
            pair<double, int> front = pq.top();
            pq.pop();

            double diff = front.first;
            int index = front.second;

            classes[index][0]++;
            classes[index][1]++;

            double currRatio = (double)classes[index][0]/classes[index][1];
            double newRatio = (double)(classes[index][0]+1)/(classes[index][1]+1);
            double delta = newRatio - currRatio;

            pq.push({delta, index});

            extraStudents--;
        }

        double res = 0;
        for(int i = 0; i < n; i++){
            res += (double)classes[i][0]/classes[i][1];
        }

        return res/n;
    }
};

// class Solution {
// public:
//     double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
//         int n = classes.size();

//         vector<double> pr(n);

//         for(int i = 0; i < n; i++){
//             double ratio = (double)classes[i][0]/classes[i][1];
//             pr[i] = ratio;
//         }

//         while(extraStudents){
//             vector<double> newpr(n);
//             for(int i = 0; i < n; i++){
//                 double newRatio = (double)(classes[i][0] + 1)/(classes[i][1] + 1);
//                 newpr[i] = newRatio;
//             }

//             int bestClassIndex = 0;
//             double maxDiff = 0;
//             for(int i = 0; i < n; i++){
//                 double diff = newpr[i] - pr[i];
//                 if(diff > maxDiff){
//                     maxDiff = diff;
//                     bestClassIndex = i;
//                 }
//             }

//             pr[bestClassIndex] = newpr[bestClassIndex];
//             classes[bestClassIndex][0]++;
//             classes[bestClassIndex][1]++;

//             extraStudents--;
//         }

//         double res = 0;
//         for(int i = 0; i < classes.size(); i++){
//             res += pr[i];
//         }

//         return res/n;
//     }
// };
