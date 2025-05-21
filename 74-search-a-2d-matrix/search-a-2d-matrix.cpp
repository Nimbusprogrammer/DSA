class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
     {
        int n = matrix.size();
        bool answer = false;
        int m = matrix[0].size();
        //lets think of it as a 1d array and do it.
        int low = 0;
        int high = m*n-1;
        while ( low <= high)
        {
            int mid =(low+high)/2;
            int row = mid/m;
            int coloumn = mid%m;
            if ( matrix[row][coloumn] == target)
            {
                answer = true;
                return answer;
            }
            else if ( matrix[row][coloumn] > target)
            high = mid-1;
            else 
            low = mid+1;
        }
        return answer;
    }
};