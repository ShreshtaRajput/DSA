class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> arr(26, 0);
        int maxFreq = 0;

        int ans = 0;

        int left = 0;
        for(int right = 0; right < s.size(); right++){
            int index = s[right] - 'A';
            arr[index]++;
            if(arr[index] > maxFreq){
                maxFreq = arr[index];
            }
            while((right - left + 1) - maxFreq > k){
                arr[s[left] - 'A']--;
                left++;
            }

            ans = right - left + 1;
        }

        return ans;
    }
};