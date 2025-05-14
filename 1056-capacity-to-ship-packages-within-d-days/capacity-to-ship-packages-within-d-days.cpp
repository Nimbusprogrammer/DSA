class Solution {
public:
    int daysreq ( int weightlimit , vector<int> weights , int days)
    {
        int n = weights.size();
        int weight = 0;
        int needdays = 1;
        for  ( int i = 0 ; i < n ; i++)
        {
            
            weight += weights[i];
            if ( weight > weightlimit)
            {
                weight = weights[i];
                needdays++;
            }
            
        }
        return needdays;
    }
    int shipWithinDays(vector<int>& weights, int days) {
         int totalweight = 0;
         int weightlimit;
         int n = weights.size();
         int left = *max_element ( weights.begin() , weights.end());
         int right = accumulate(weights.begin() , weights.end() , 0);
         while ( left <= right)
         {
            int mid = ( left + right)/2;
            int daysneed = daysreq ( mid , weights , days);
            if ( daysneed <= days)
            {
                weightlimit = mid;
                right = mid-1;
            }
            else 
            left = mid+1;
         }
         return weightlimit;
         
    }
};