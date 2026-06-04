class Solution {
private:
    int solve(int num){
        int cnt = 0;
        string str = to_string(num);

        if(str.size() < 3) return 0;

        for(int i = 1; i < str.size() - 1; i++){
            if(str[i] > str[i-1] && str[i] > str[i+1]){
                cnt++;
            }else if(str[i] < str[i-1] && str[i] < str[i+1]){
                cnt++;
            }
        }

        return cnt;
    }
public:
    int totalWaviness(int num1, int num2) {
        int res = 0;

        for(int i = num1; i <= num2; i++){
            res += solve(i);
        }

        return res;
    }
};