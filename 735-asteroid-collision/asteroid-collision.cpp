class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        
        int n = asteroids.size();
        if ( n ==0) return ans;
       
        for ( int i = 0 ; i < n ; i++)
        {
            
            if ( asteroids[i] >=0)
            {
                
                ans.push_back(asteroids[i]);
            }
            else
            {
               
             while ( !ans.empty() && ans.back() >=0 && ans.back() < abs(asteroids[i]))
             {
                   
                   
                    ans.pop_back();

             }
              if ( !ans.empty() && abs(asteroids[i]) == ans.back())
                   {
                      
                      ans.pop_back();
                      
                      
                   }
              else if ( ans.empty() || ans.back() <= 0 )
              {
                  
                 
                  ans.push_back(asteroids[i]);
              }
            }
        }
        return ans;
    }
};