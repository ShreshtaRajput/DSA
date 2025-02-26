class Solution {
public:
    bool isPalindrome(int x) {
        vector<int> arr;

        if(x < 0){
            return false;
        }

        while( x > 0){
            int num = x % 10;
            x = x/10;
            arr.push_back(num);
        }

        vector<int> revArr = arr;

        int i = 0; 
        int j = arr.size() - 1;
        while(i < j){
            swap(arr[i] ,arr[j]);
            i++;
            j--;
        } 

        // for(int i = 0; i < arr.size(); i++){
        //     if(arr[i] != revArr[i]){
        //         return false;
        //     }
        // }
        // return true;

        return (arr == revArr);
    }
};