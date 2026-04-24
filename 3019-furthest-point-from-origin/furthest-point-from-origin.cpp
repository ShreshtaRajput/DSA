class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int n  = moves.size();
        int lCount = 0, rCount = 0, dCount = 0;

        for(char ch: moves){
            if(ch == 'L') lCount++;
            else if(ch == 'R') rCount++;
            else dCount++;
        }

        if(lCount > rCount){
            return abs((lCount + dCount) - rCount);
        }else{
            return abs((rCount + dCount) - lCount);
        }


        // int n = moves.size();
        // char prevChar = (moves[0] == 'R') ? 'R' : 'L';

        // for(int i = 0; i < n; i++){
        //     if(moves[i] == '_'){
        //         moves[i] = prevChar;
        //     }else{
        //         prevChar = moves[i];
        //     }
        // }

        // cout << moves << endl;

        // int lCount = 0;
        // int rCount = 0;

        // for(int i = 0; i < n; i++){
        //     if(moves[i] == 'L') lCount++;
        //     else rCount++;
        // }

        // return abs(lCount - rCount);
    }
};