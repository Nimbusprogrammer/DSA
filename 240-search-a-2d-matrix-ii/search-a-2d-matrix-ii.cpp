class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

     
        int n = matrix.size();
        int m = matrix[0].size();
        int rows = n - 1;
        int cols = 0;
        while ( rows>= 0 && cols <m)
        {
               if ( matrix[rows][cols] == target)
                return true;
                else if ( matrix[rows][cols] > target)
                rows--;
                else 
                cols++;
        }
        return false;
    }
};