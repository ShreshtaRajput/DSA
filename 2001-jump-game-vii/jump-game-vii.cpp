class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();

        queue<int> q;
        q.push(0);  //Initialize with the first index

        int maxReached = 0;     //Track the farthest index to prevent recounting

        while(!q.empty()){
            int curr = q.front();
            q.pop();

            for(int i = max(curr + minJump, maxReached + 1); i <= min(curr + maxJump, n-1); i++){
                if(s[i] == '0'){
                    q.push(i);
                    if(i == n-1) return true;
                }
            }

            maxReached = max(maxReached, curr + maxJump);
        }

        return false;
    }
};

// class Solution {
// private:
//     bool solve(string s, int minJump, int maxJump, int idx){
//         int n = s.size();

//         if(idx == n - 1){
//             return true;
//         }

//         if(idx >= n) return false;

//         for(int i = idx + minJump; i <= min(idx + maxJump, n - 1); i++){
//             if(s[i] == '0'){
//                 if(solve(s, minJump, maxJump, i)){
//                     return true;
//                 }
//             }
//         }

//         return false;
//     }

// public:
//     bool canReach(string s, int minJump, int maxJump) {
//         return solve(s, minJump, maxJump, 0);
//     }
// };