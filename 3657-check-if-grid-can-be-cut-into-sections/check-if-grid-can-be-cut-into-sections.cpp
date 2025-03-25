class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        return isValidCut(rectangles, 0, 0, 2) || isValidCut(rectangles, 1, 1, 3);
    }

private:
    bool isValidCut(vector<vector<int>>& rectangles, int sortIndex, int start, int end) {
        sort(rectangles.begin(), rectangles.end(), [&](const vector<int>& a, const vector<int>& b) {
            return a[sortIndex] < b[sortIndex];
        });

        vector<vector<int>> ans;
        int intervals = 0;

        for(int i = 0; i < rectangles.size(); i++){
            if(ans.empty() || rectangles[i][start] >= ans.back()[end]){
                ans.push_back(rectangles[i]);

                if(ans.size() > 1){
                    intervals++;
                }
            }
            else{
                ans.back()[end] = max(ans.back()[end], rectangles[i][end]);
            }
        }

        return intervals > 1;
    }
};