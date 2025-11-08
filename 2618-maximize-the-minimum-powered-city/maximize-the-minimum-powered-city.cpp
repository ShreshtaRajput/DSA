class Solution {
private:    
    bool check(long long mid, vector<long long> &diff, int r, int k, int n){
        vector<long long> tempDiff = diff;

        long long cummSum = 0;

        for(int i = 0; i < n; i++){
            cummSum += tempDiff[i];

            if(cummSum < mid){
                long long need = mid - cummSum;
                if(need > k) return false;

                k -= need;
                cummSum += need;

                if(i + 2*r + 1 < n)tempDiff[i+2*r+1] -= need;
            }
        }

        return true;
    }
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();

        // Creating the difference array
        vector<long long> diff(n+1, 0);
        for(int i = 0; i < n; i++){
            int l = max(0, i-r);
            int ri  = min(n-1, i+r);

            diff[l] += stations[i];
            if(ri+1 < n) diff[ri + 1] -= stations[i];
        }

        long long left = stations[0];
        for (int i = 1; i < stations.size(); ++i) {
            if (stations[i] < left) {
                left = stations[i];
            }
        }

        long long right = 0;
        for (int i = 0; i < stations.size(); ++i) {
            right += stations[i];
        }
        right += k;

        long long res = 0;

        while(left <= right){
            long long mid = left + (right - left)/2;

            if(check(mid, diff, r, k, n)){
                res = mid;
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }

        return res;
    }
};