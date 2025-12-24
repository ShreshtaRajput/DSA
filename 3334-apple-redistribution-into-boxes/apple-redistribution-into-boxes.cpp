class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int n = apple.size();
        int m = capacity.size();
        sort(capacity.begin(), capacity.end());
        reverse(capacity.begin(), capacity.end());

        int total = 0;
        for(int i = 0; i < n; i++){
            total += apple[i];
        }

        int res = 0;
        for(int i = 0; i < m; i++){
            if(total > 0){
                res += 1;
                total -= capacity[i];
            }
        }

        return res;
    }
};