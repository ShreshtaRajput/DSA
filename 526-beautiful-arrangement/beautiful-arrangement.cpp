class Solution {
private:
    void helper(int& count, vector<int>& freq, int pos, int n) {
        if (pos > n) {
            count++;
            return;
        }

        for (int i = 1; i <= n; i++) {
            if (!freq[i]) {
                if (i % pos == 0 || pos % i == 0) {
                    freq[i] = 1;
                    helper(count, freq, pos + 1, n);
                    freq[i] = 0;
                }
            }
        }
    }

public:
    int countArrangement(int n) {
        int count = 0;

        vector<int> freq(n + 1, 0);
        int pos = 1;

        helper(count, freq, pos, n);

        return count;
    }
};

// class Solution {
// private:
//     void permutations(vector<vector<int>>& permArr, vector<int>& arr,
//                       vector<int>& temp, vector<int>& freq, int n) {
//         if (temp.size() >= n) {
//             permArr.push_back(temp);
//             return;
//         }

//         for (int i = 0; i < arr.size(); i++) {
//             if (!freq[i]) {
//                 temp.push_back(arr[i]);
//                 freq[i] = 1;
//                 permutations(permArr, arr, temp, freq, n);
//                 temp.pop_back();
//                 freq[i] = 0;
//             }
//         }
//     }

// public:
//     int countArrangement(int n) {
//         int count = 0;
//         vector<int> arr;
//         vector<vector<int>> permArr;
//         vector<int> temp;
//         vector<int> freq(n, 0);
//         for (int i = 1; i <= n; i++) {
//             arr.push_back(i);
//         }

//         permutations(permArr, arr, temp, freq, n);

//         for (int i = 0; i < permArr.size(); i++) {
//             bool flag = true;
//             for (int j = 0; j < permArr[i].size(); j++) {
//                 if (!(permArr[i][j] % (j + 1) == 0 ||
//                       (j + 1) % permArr[i][j] == 0)) {
//                     flag = false;
//                     break;
//                 }
//             }
//             if (flag) {
//                 count++;
//             }
//         }

//         return count;
//     }
// };