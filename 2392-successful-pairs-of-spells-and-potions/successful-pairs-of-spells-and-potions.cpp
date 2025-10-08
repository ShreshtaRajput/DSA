class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions,
                                long long success) {
        vector<int> res;

        sort(potions.begin(), potions.end());

        

        for(int i = 0; i < spells.size(); i++){
            int count = 0;
            int start = 0;
            int end = potions.size() - 1;

            while(start < end){
                int mid = start + (end - start)/2;

                if(1LL * potions[mid] * spells[i] >= success){
                    end = mid;
                }else{
                    start = mid + 1;
                }
            }

            if(1LL * potions[start] * spells[i] >= success){
                count = potions.size() - start;
            }

            res.push_back(count);
        }

        return res;
    }
};