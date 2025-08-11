class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers;
        vector<int> ans;
        int MOD = 1e9 + 7;

        int temp_n = n;
        int current_power = 1;

        while (temp_n > 0) {
            // If the number is odd, its last binary digit is 1.
            if (temp_n % 2 == 1) {
                powers.push_back(current_power);
            }
            // "Shift" to the next bit by dividing by 2.
            temp_n /= 2;
            // Move to the next power of 2.
            current_power *= 2;
        }

        for (int i = 0; i < queries.size(); i++) {
            int num1 = queries[i][0];
            int num2 = queries[i][1];

            long long temp = 1;
            for (int j = num1; j <= num2; j++) {
                temp = (temp * powers[j]) % MOD;
            }
            ans.push_back(temp);
        }

        return ans;
    }
};