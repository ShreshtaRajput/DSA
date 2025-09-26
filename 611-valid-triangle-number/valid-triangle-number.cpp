class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();

        sort(nums.begin(), nums.end());

        for(int i = 0; i < n-2; i++){
            for(int j = i+1; j < n-1; j++){
                int sum = nums[i] + nums[j];

                int s = j + 1; int e = n;
                while(s < e){
                    int mid = s + (e-s)/2;

                    if(nums[mid] < sum){
                        s = mid + 1;
                    }else{
                        e = mid;
                    }
                }

                cnt += s - (j+1);
            }
        }

        return cnt;
    }
};

// for(int i = 0; i < n; i++){
//     for(int j = i + 1; j < n; j++){
//         for(int k = j + 1; k < n; k++){
//             if(nums[i] + nums[j] > nums[k] && nums[i] + nums[k] > nums[j] &&
//                 nums[j] + nums[k] > nums[i]){
//                 cnt++;
//             }
//         }
//     }
// }