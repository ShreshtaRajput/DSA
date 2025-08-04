class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int start = 0;  //defining the beginning of sliding window
        int maxWindowSize = 0;

        // Map to keep track of the different elements in the fruits array
        unordered_map<int, int> mp;

        for(int end = start; end < fruits.size(); end++){
            mp[fruits[end]]++;

            while(mp.size() > 2){   //If there are more than two elements in the map
                mp[fruits[start]]--;      //Reduce the elements count
                if(mp[fruits[start]] == 0){     //It the element becomes 0, erase it
                    mp.erase(fruits[start]);
                }
                start++;    //shrink the sliding window
            }

            maxWindowSize = max(maxWindowSize, end - start + 1);
        }

        return maxWindowSize;
    }
};