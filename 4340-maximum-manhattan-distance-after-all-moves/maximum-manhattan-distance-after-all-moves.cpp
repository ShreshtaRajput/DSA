class Solution {
public:
    int maxDistance(string moves) {
        int netX = 0;
        int netY = 0;
        int underscore = 0;

        for(char ch: moves){
            if(ch == 'R'){
                netX++;
            }else if(ch == 'L'){
                netX--;
            }else if(ch == 'U'){
                netY++;
            }else if(ch == 'D'){
                netY--;
            }else{
                underscore++;
            }
        }

        return abs(netX) + abs(netY) + underscore;
    }
};