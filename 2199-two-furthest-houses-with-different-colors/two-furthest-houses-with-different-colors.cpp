class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int res = 0;
        int n = colors.size();

        // Use two pointers
        // When we get equal -> shift one pointer
        // When we get different -> calc the distance and shift onr pointer
        // repeat it twice for front pointer and back pointer
        int s = 0, e = n-1;

        // Shift only e pointer
        while(s <= e){
            if(colors[s] != colors[e]){
                res = max(res, abs(s - e));
            }

            e--;
        }

        s = 0; e = n-1;
        while(s <= e){
            if(colors[s] != colors[e]){
                res = max(res, abs(s-e));
            }

            s++;
        }


        return res;
    }
};