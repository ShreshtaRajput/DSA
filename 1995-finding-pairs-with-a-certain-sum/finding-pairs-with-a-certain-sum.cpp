class FindSumPairs {
private:
    vector<int> nums1;
    vector<int> nums2;
    unordered_map<int, int> mp;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this -> nums1 = nums1;
        this -> nums2 = nums2;
        for(auto it: nums2){
            mp[it]++;
        }
    }
    
    void add(int index, int val) {
        mp[nums2[index]]--;
        nums2[index] += val;
        mp[nums2[index]]++;
    }
    
    int count(int tot) {
        int totCount = 0;
        // for(int i = 0; i < nums1.size(); i++){
        //     for(int j = 0; j < nums2.size(); j++){
        //         if(nums1[i] + nums2[j] == tot){
        //             totCount++;
        //         }
        //     }
        // }

        for(auto it: nums1){
            int target = tot - it;
            totCount += mp[target];
        }

        return totCount;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */