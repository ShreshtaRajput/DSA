class NumArray {
public:
    vector<int> prefixSum;
    NumArray(vector<int>& nums) {
        this -> prefixSum = nums;
        for(int i = 1; i < prefixSum.size(); i++){
            prefixSum[i] += prefixSum[i-1];
        }
    }
    
    int sumRange(int left, int right) {
        if(left == 0) return prefixSum[right];
        else return prefixSum[right] - prefixSum[left-1];   //Not left inclusive
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */