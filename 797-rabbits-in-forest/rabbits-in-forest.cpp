class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> mp;

        // Map mai store ho rha hai ki - kitne rabbits ne same answer
        // dia for the same color
        for (int i = 0; i < answers.size(); i++) {
            mp[answers[i]]++;
        }

        int total = 0;
        for (auto& i : mp) {
            // Making groups - (number of rabbits that said the same
            // number)/(total nnumber of rabbits in group)
            int groups = ceil((double(i.second)) / (i.first + 1));
            int group_size = i.first + 1;
            total += groups * group_size;
        }

        return total;
    }
};