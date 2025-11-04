class Compare{
public:
    bool operator()(pair<int, int> &a, pair<int, int> &b){
        if(a.first == b.first){
            // If same frequency, the greater one will me more valued
            return a.second < b.second;
        }

        return a.first < b.first;
    }
};

class Solution {
private:
    int calculateXsum(vector<int>& subArr, int k, int x, int n){
        unordered_map<int, int> mp;
        for(auto num: subArr){
            mp[num]++;
        }

        // Using max-heap :)
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;

        for(auto &p: mp){
            pq.push({p.second, p.first});
        }

        int xsum = 0;
        int count = 0;
        while(count < x && !pq.empty()){
            xsum += pq.top().second*pq.top().first;
            pq.pop();
            count++;
        }

        return xsum;
    }
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();

        vector<int> res(n-k+1);

        for(int i = 0; i <= n-k; i++){
            // Making an array of size 'k' for each iteration
            vector<int> subArr(nums.begin()+i, nums.begin()+i+k);
            int xsum = calculateXsum(subArr, k, x, n);  //Calculate the xsum
            res[i] = xsum;
        }

        return res;
    }
};