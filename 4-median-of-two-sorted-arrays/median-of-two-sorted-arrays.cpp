class Solution {
private:
    void mergeArr(vector<int> &mArr, vector<int> &n1, vector<int> &n2){
        int m = n1.size();
        int n = n2.size();

        mArr.resize(m + n);

        int p1 = 0, p2 = 0;
        int k = 0;
        while(p1 < m && p2 < n){
            if(n1[p1] < n2[p2]){
                mArr[k++] = n1[p1++];
            }else{
                mArr[k++] = n2[p2++];
            }
        }

        while(p1 < m){
            mArr[k++] = n1[p1++];
        }

        while(p2 < n){
            mArr[k++] = n2[p2++];
        }
    }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        double median = 0;

        vector<int> mergedArr(n + m);

        // Merge the arrays
        mergeArr(mergedArr, nums1, nums2);

        int len = mergedArr.size();
        if(len % 2 == 0){
            // Even length => two medians
            int idx1 = len/2 - 1;
            int idx2 = len/2;

            median = (double)(mergedArr[idx1] + mergedArr[idx2])/2;
        }else{
            median = mergedArr[len/2];
        }

        return median;
    }
};