class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        stack<int> st;
        int n = asteroids.size();
        if ( n ==0) return ans;
       
        for ( int i = 0 ; i < n ; i++)
        {
            
            if ( asteroids[i] >=0)
            {
                st.push(asteroids[i]);
                ans.push_back(asteroids[i]);
            }
            else
            {
               
             while ( !st.empty() && st.top() >=0 && st.top() < abs(asteroids[i]))
             {
                   
                    st.pop();
                    ans.pop_back();

             }
              if ( !st.empty() && abs(asteroids[i]) == st.top())
                   {
                      st.pop();
                      ans.pop_back();
                      
                      
                   }
              else if ( st.empty() || st.top() <= 0 )
              {
                  
                  st.push(asteroids[i]);
                  ans.push_back(asteroids[i]);
              }
            }
        }
        return ans;
    }
};