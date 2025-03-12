class Solution {
private:
    int firstZero(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;
        int index = nums.size();

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (nums[mid] >= 0) {
                end = mid - 1;
                index = mid;
            } else if (nums[mid] < 0) {
                start = mid + 1;
            }
        }

        return index;
    }

    int lastZero(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;
        int index = nums.size();

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (nums[mid] <= 0) {
                start = mid + 1;
            } else if (nums[mid] > 0) {
                end = mid - 1;
                index = mid;
            }
        }

        return index;
    }

public:
    int maximumCount(vector<int>& nums) {
        int posCount = nums.size() - lastZero(nums);
        int negCount = firstZero(nums);

        // for (int i = 0; i < nums.size(); i++) {
        //     if (nums[i] < 0) {
        //         negCount++;
        //     } else if (nums[i] > 0) {
        //         posCount++;
        //     }
        // }

        int ans = max(posCount, negCount);
        return ans;
    }
};