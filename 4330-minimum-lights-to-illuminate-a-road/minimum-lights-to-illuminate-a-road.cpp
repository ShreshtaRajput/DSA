class Solution {
public:
    int minLights(vector<int>& lights) {
        int n = lights.size();
        vector<bool> isWorking(n);
        vector<int> diff(n+1, 0);

        for(int i = 0; i < n; i++){
            if(lights[i] != 0){
                int mini = max(0, i-lights[i]);
                int maxi = min(n-1, i + lights[i]);

                diff[mini] += 1;
                diff[maxi + 1] -= 1;
            }
        }

        int curr = 0;
        for(int i = 0; i < n; i++){
            curr += diff[i];
            if(curr > 0){
                isWorking[i] = true;
            }
        }

        int res = 0;
        int i = 0;
        while(i < n){
            if(!isWorking[i]){
                res++;
                isWorking[i] = isWorking[i + 1] = isWorking[i+2] = true;
                i += 3;
            }else{
                i++;
            }
        }

        return res;
    }
};