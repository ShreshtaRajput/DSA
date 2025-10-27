class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();

        int prev = 0;
        int ans = 0;

        for(int i = 0; i < n; i++){
            int cnt = 0;
            // Count the number of devices in the row
            for(int j = 0; j < bank[i].size(); j++){
                if(bank[i][j] == '1'){
                    cnt++;
                }
            }

            if(cnt != 0){
                ans += (prev * cnt);        //Add to the answer
                prev = cnt;     //Make the current row as previous for the next iteration
            };
        }

        return ans;
    }
};