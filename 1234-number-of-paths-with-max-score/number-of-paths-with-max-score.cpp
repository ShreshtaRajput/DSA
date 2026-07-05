#define MOD 1000000007

class Solution {
private:
    int findSum(vector<string> &board, int i, int j, vector<vector<int>> &dp){
        if(i == 0 && j == 0){
            return 0;
        }

        if (i < 0 || j < 0 || board[i][j] == 'X'){
            return -1e9;
        }

        if(dp[i][j] != -1) return dp[i][j];

        int curr = 0;
        if(board[i][j] != 'S'){
            curr = board[i][j] - '0';
        }

        int up = findSum(board, i-1, j, dp);
        int left = findSum(board, i, j-1, dp);
        int ul = findSum(board, i-1, j-1, dp);

        return dp[i][j] = curr + max(up, max(left, ul));
    }

    int findPath(vector<string> &board, int i, int j, vector<vector<int>> &dp, vector<vector<int>> &dpSum){
        if(i == 0 && j == 0){
            return 1;
        }

        if (i < 0 || j < 0 || board[i][j] == 'X'){
            return 0;
        }

        if(dp[i][j] != -1) return dp[i][j];

        // Get the scores for each path
        int upScore = findSum(board, i-1, j, dpSum);
        int leftScore = findSum(board, i, j-1, dpSum);
        int ulScore = findSum(board, i-1, j-1, dpSum);

        int maxScore = max(upScore, max(leftScore, ulScore));

        // Calculate the paths that give the maxScore
        int paths = 0;
        if(upScore == maxScore) paths += findPath(board, i-1, j, dp, dpSum);
        if(leftScore == maxScore) paths += findPath(board, i, j-1, dp, dpSum);
        if(ulScore == maxScore) paths += findPath(board, i-1, j-1, dp, dpSum);

        return dp[i][j] = paths % MOD;
    }

public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int m = board.size();
        int n = board[0].size();

        vector<int> res(2);
        vector<vector<int>> dpSum(m, vector<int>(n, -1));
        vector<vector<int>> dpPath(m, vector<int>(n, -1));

        int maxSum = findSum(board, m-1, n-1, dpSum);
        res[0] = maxSum;
        int totalPaths = findPath(board, m-1, n-1, dpPath, dpSum);
        res[1] = totalPaths;

        if(totalPaths == 0) return {0,0};

        return res;
    }
};