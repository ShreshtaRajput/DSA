class Solution{
public:
    int maxDistance(string s, int k){
        int maxMD = 0;
        int north  = 0;
        int south = 0;
        int east = 0;
        int west = 0;

        for(int i = 0; i < s.length(); i++){
            if(s[i] == 'N') north++;
            else if(s[i] == 'S') south++;
            else if(s[i] == 'E') east++;
            else if(s[i] == 'W') west++;

            int currMD = abs(north - south) + abs(east - west);

            int steps = i + 1;
            int wasted = steps - currMD;

            int extra = 0;
            if(wasted != 0){
                extra = min(2 * k, wasted);
            }

            maxMD = max(currMD + extra, maxMD);
        }

        return maxMD;
    }
};


// class Solution {
// private:
//     int getManhattanDistance(map<char, int>& mp) {
//         int vertical = abs(mp['N'] - mp['S']);
//         int horizontal = abs(mp['E'] - mp['W']);
//         return vertical + horizontal;
//     }

// public:
//     int maxDistance(string s, int k) {
//         int ans = 0;
//         map<char, int> mp;
//         int md1 = 0, md2 = 0, md3 = 0, md4 = 0;

//         for (char ch : s) {
//             mp[ch]++;
//         }

//         int remainingMods = k;

//         // int verticalDistance = abs(mp['N'] - mp['S']);
//         // First only checking in the vertical direction
//         if(remainingMods > 0){
//             int change = min(remainingMods, min(mp['N'], mp['S']));
//             if(mp['N'] >= mp['S']){
//                 mp['N'] += change;
//                 mp['S'] -= change;

//                 md1 = getManhattanDistance(mp);
//             }else{
//                 mp['S'] += change;
//                 mp['N'] -= change;   

//                 md2 = getManhattanDistance(mp);
//             }

//             remainingMods -= change;
//         }

//         // int horizontalDistance = abs(mp['E'] - mp['W']);
//         // After the checking in the veritcal direction
//         if(remainingMods > 0){
//             int change = min(remainingMods, min(mp['E'], mp['W']));
//             if(mp['E'] >= mp['W']){
//                 mp['E'] += change;
//                 mp['W'] -= change;

//                 md3 = getManhattanDistance(mp);
//             }else{
//                 mp['W'] += change;
//                 mp['E'] -= change;

//                 md4 = getManhattanDistance(mp);
//             }

//             remainingMods -= change;
//         }

//         ans = max(md1, max(md2, max(md3,md4)));

//         // return ans;

//         int x = 0, y = 0;
//         int maxIntermediate = 0;
//         for (char ch : s) {
//             if (ch == 'N') y += 1;
//             else if (ch == 'S') y -= 1;
//             else if (ch == 'E') x += 1;
//             else if (ch == 'W') x -= 1;
//             maxIntermediate = max(maxIntermediate, abs(x) + abs(y));
//         }

//         // Return the better of your count-based result and path-based result
//         return max(ans, maxIntermediate);
//     }
// };