class Solution {
private:
    bool check(int i){
        while(i > 0){
            if(i % 10 == 0) return false;
            i /= 10;
        }
        return true;
    }
public:
    vector<int> getNoZeroIntegers(int n) {
        for(int i = 1; i < n; i++){
            int j = n - i;
            if(check(i) && check(j)){
                return {i, j};
            }
        }

        return {};
    }
};