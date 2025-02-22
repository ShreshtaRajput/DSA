class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // int row = matrix.size();
        // int col = matrix[0].size();

        // for(int index = col - 1; index >= 0; index--){
        //     if(matrix[0][index] < target){
        //         int start = 0;
        //         int end = row - 1;

        //         while(start <= end){
        //             int mid = start + (end - start)/2;
        //             int element = matrix[mid][index];

        //             if(element == target){
        //                 return 1;
        //             }else if(element > target){
        //                 end = mid - 1;
        //             }else{
        //                 start = mid + 1;
        //             }
        //         }
        //     }else if(matrix[0][index] == target){
        //         return 1;
        //     }
        // }
        // return 0;

        // Optimum approach
        int row = matrix.size();
        int col = matrix[0].size();

        int rowIndex = 0;
        int colIndex = col - 1;

        while(rowIndex < row && colIndex >= 0){
            int element = matrix[rowIndex][colIndex];

            if(element == target){
                return 1;
            }else if(element > target){
                colIndex--;
            }else{
                rowIndex++;
            }
        }
        return 0;
    }
};