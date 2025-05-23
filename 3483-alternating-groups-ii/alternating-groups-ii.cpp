class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        int res = 0;
        int alternatingElementsCount = 1;
        int lastColor = colors[0];

        for(int i = 1; i < n + k - 1; i++){
            int index = i % n;

            if(colors[index] == lastColor){
                alternatingElementsCount = 1;
                lastColor = colors[index];
                continue;
            }

            alternatingElementsCount += 1;

            if(alternatingElementsCount >= k){
                res++;
            }
            lastColor = colors[index];
        }
        return res;
    }
};