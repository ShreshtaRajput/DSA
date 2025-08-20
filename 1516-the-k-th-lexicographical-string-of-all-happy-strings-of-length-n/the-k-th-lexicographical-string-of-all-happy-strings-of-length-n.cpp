class Solution {
private:
    void helper(int n, vector<string> &arr, string temp){
        // base case
        if(temp.size() == n){
            arr.push_back(temp);
            return;
        }

        for(char currChar = 'a'; currChar <= 'c'; currChar++){
            // If same character aa rha hai => then skip it
            if(temp.size() > 0 && currChar == temp.back()){
                continue;
            }

            // Okay, so do not store every string to avoid MLE, just update it in the recursive call
            // temp += currChar;   //else add the character to temp
            helper(n, arr, temp + currChar);
        }
    }
public:
    string getHappyString(int n, int k) {
        vector<string> arr;
        string temp;

        helper(n, arr, temp);

        if(arr.size() < k){
            return "";
        }else{
            return arr[k - 1];
        }
    }
};