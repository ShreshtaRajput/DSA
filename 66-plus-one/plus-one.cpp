class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();
        
        for(int i = size - 1; i >= 0; --i){
            if(digits[i] < 9){
                digits[i] += 1;
                return digits;
            }
            digits[i] = 0;
        }

        size += 1;
        vector<int> newDigits(size);

        newDigits[0] = 1;
        for(int i = 1; i < size; i++){
            newDigits[i] = 0;
        }

        return newDigits;
    }
};