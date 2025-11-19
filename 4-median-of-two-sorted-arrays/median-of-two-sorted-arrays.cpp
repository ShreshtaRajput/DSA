// REVISE THIS BINARY SEARCH
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(); int n = nums2.size();

        if(m > n) return findMedianSortedArrays(nums2, nums1);

        int left = 0; int right = m;
        int totalLeft = (m + n + 1)/2;

        while(left <= right){
            int i = (left + right)/2;
            int j = totalLeft - i;

            int Aleft;
            if(i == 0) Aleft = INT_MIN;
            else Aleft = nums1[i-1];

            int Aright;
            if(i == m) Aright = INT_MAX;
            else Aright = nums1[i];

            int Bleft;
            if(j == 0) Bleft = INT_MIN;
            else Bleft = nums2[j-1];

            int Bright;
            if(j == n) Bright = INT_MAX;
            else Bright = nums2[j];

            if(Aleft <= Bright && Bleft <= Aright){
                if((m+n)%2 == 0){
                    return (max(Aleft, Bleft) + min(Aright, Bright)) / 2.0;
                }else{
                    return max(Aleft, Bleft);
                }
            }else if (Aleft > Bright) {
                right = i - 1;
            } 
            else {
                left = i + 1;
            }
        }

        return 0.0;
    }
};

// class Solution {
// private:
//     void mergeArr(vector<int> &mArr, vector<int> &n1, vector<int> &n2){
//         int m = n1.size();
//         int n = n2.size();

//         mArr.resize(m + n);

//         int p1 = 0, p2 = 0;
//         int k = 0;
//         while(p1 < m && p2 < n){
//             if(n1[p1] < n2[p2]){
//                 mArr[k++] = n1[p1++];
//             }else{
//                 mArr[k++] = n2[p2++];
//             }
//         }

//         while(p1 < m){
//             mArr[k++] = n1[p1++];
//         }

//         while(p2 < n){
//             mArr[k++] = n2[p2++];
//         }
//     }
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//         int m = nums1.size();
//         int n = nums2.size();

//         double median = 0;

//         vector<int> mergedArr(n + m);

//         // Merge the arrays
//         mergeArr(mergedArr, nums1, nums2);

//         int len = mergedArr.size();
//         if(len % 2 == 0){
//             // Even length => two medians
//             int idx1 = len/2 - 1;
//             int idx2 = len/2;

//             median = (double)(mergedArr[idx1] + mergedArr[idx2])/2;
//         }else{
//             median = mergedArr[len/2];
//         }

//         return median;
//     }
// };