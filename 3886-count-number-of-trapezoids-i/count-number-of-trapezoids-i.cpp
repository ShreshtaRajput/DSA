#define MOD 1000000007
#define LL long long

class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        LL res = 0;

        unordered_map<int, int> mp;
        // Group according to the y coords
        for(auto &p: points){
            mp[p[1]]++;
        }

        int sum = 0;
        for(auto &p: mp){
            LL edge = (LL)p.second * (p.second - 1)/2;
            res += edge * sum;
            sum += edge;
        }

        return res % MOD;
    }
};

// class Solution {
// private:
//     bool isValid(const vector<int>& p1, const vector<int>& p2, const vector<int>& p3, const vector<int>& p4){
//         unordered_map<int, int> mp;
//         mp[p1[1]]++;
//         mp[p2[1]]++;
//         mp[p3[1]]++;
//         mp[p4[1]]++;

//         if(mp.size() != 2) return false;

//         for(auto &p: mp){
//             if(p.second != 2) return false;
//         }

//         return true;
//     }
// public:
//     int countTrapezoids(vector<vector<int>>& points) {
//         int res = 0;
//         int n = points.size();

//         for(int i = 0; i < n; i++){
//             for(int j = i + 1; j < n; j++){
//                 for(int k = j + 1; k < n; k++){
//                     for(int l = k + 1; l < n; l++){
//                         if(isValid(points[i], points[j], points[k], points[l])){
//                             res = (res + 1) % MOD;
//                         }
//                     }
//                 }
//             }
//         }

//         return res % MOD;
//     }
// };