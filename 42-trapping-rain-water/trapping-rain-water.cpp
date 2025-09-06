class Solution {
public:
    int trap(vector<int>& height) {
         int leftmax = height[0];
         int n = height.size();
         if ( n == 0)
         return 0;//handling null inputs
         int rightmax = height[n-1];
         int left = 0 ; 
         int water =0;//use long long to avoid overflow in some cases
         int right = n-1;
         while( left <= right)
         {
               if ( leftmax < rightmax)
               {
                   if ( height[left] < leftmax)
                   {
                       water+= leftmax- height[left];
                   }
                   else 
                   leftmax = height[left] ;
                   left++;
               }
               else 
               {
                  if ( height[right] < rightmax)
                  {
                     water+= rightmax- height[right];
                  }
                  else 
                  rightmax = height[right];
                  right--;
               }
         }
         return water;
    }
};