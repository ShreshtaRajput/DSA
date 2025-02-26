class Solution {
public:
    bool isPalindrome(int x) {
        // vector<int> arr;

        // if(x < 0){
        //     return false;
        // }

        // while( x > 0){
        //     int num = x % 10;
        //     x = x/10;
        //     arr.push_back(num);
        // }

        // vector<int> revArr = arr;

        // int i = 0; 
        // int j = arr.size() - 1;
        // while(i < j){
        //     swap(arr[i] ,arr[j]);
        //     i++;
        //     j--;
        // } 

        // return (arr == revArr);

        // OPTIMUM APPROACH

        if(x < 0){
            return false;
        }

        long long reversed = 0;
        long long temp = x;

        while(temp != 0){
            int digit = temp % 10;
            reversed = reversed * 10 + digit;
            temp = temp/10;
        }

        return (reversed == x);
    }
};