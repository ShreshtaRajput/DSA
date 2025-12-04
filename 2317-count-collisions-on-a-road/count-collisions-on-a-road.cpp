class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();
        int l = 0;
        int r = n - 1;

        // Eliminating all the leading Ls
        while(l < n && directions[l] == 'L') l++;
        // Eliminating all the trailing Rs
        while(r >= l && directions[r] == 'R') r--;

        int res = 0;
        // Just count the number of non-S characters for number of collisions in the remaining window
        for(int i = l; i <= r; i++){
            if(directions[i] != 'S'){
                res++;
            }
        }

        return res;
    }
};

// class Solution {
// public:
//     int countCollisions(string directions) {
//         int res = 0;
//         stack<char> st;

//         for(char ch: directions){
//             if(ch == 'R'){
//                 st.push('R');
//             }else if(ch == 'S'){
//                 if(st.empty() || st.top() == 'S' || st.top() == 'L'){
//                     st.push('S');
//                 }else{      //st.top() == 'R'
//                     while(!st.empty() && st.top() == 'R'){
//                         st.pop();
//                         res += 1;
//                     }
//                     st.push('S');
//                 }
//             }else{      //ch == 'L'
//                 if(st.empty()) continue;
//                 else if(st.top() == 'L'){
//                     st.push('L');
//                 }else if(st.top() == 'S'){
//                     res += 1;
//                 }else{
//                     int cntR = 0;
//                     while(!st.empty() && st.top() == 'R'){
//                         st.pop();
//                         cntR++;
//                     }

//                     res += cntR + 1;
//                     st.push('S');   //When R and L collide, they become S so we push S
//                 }
//             }
//         }

//         return res;
//     }
// };