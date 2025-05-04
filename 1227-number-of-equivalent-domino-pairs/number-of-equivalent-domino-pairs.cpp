class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<pair<int,int>, int> mp;
        int count = 0;

        for(auto& i: dominoes){
            // For the given condition [(a == c and b == d) || (a == d and b ==c)], implies that
            // the taken pairs are equal when both arranged in ascending or descending order

            // Making the same order
            if(i[0] > i[1]) swap(i[0], i[1]);

            // Adding to the count and the map
            count += mp[make_pair(i[0], i[1])]++;
        }

        return count;
    }
};

// int count = 0;
// for (int i = 0; i < dominoes.size(); i++) {
//     for (int j = i + 1; j < dominoes.size(); j++) {
//         if ((dominoes[i][0] == dominoes[j][1] &&
//              dominoes[i][1] == dominoes[j][0]) ||
//             (dominoes[i][1] == dominoes[j][1] &&
//              dominoes[i][0] == dominoes[j][0])) {
//             count++;
//         }
//     }
// }
// return count;