class Solution {
  public:
     int precedence( char k)
     {
         int ans = 0;
         if ( k == '^')
         {
             ans = 3;
         }
         else if ( k == '*' || k == '/' || k == '%')
         {
             ans = 2;
         }
         else if ( k == '+' || k == '-')
         ans = 1;
        
         return ans ; // if its '(' then automatically its precedence is 0 as it must be considered 
     //mainly useful when we are like popping up stack until preced < precedence of that s[i] case if we encounter '('then we need to give it some precedence so that we will know it is of lower precedence or else error will come 
         
     }
    string infixToPrefix(string s) {
        // code here
        stack<char> st;
        reverse(s.begin() , s.end());
        // replace '(' with ')'
          for (char &c : s) {
            if (c == '(')
                c = ')';
            else if (c == ')')
                c = '(';
        }
        string output;
        int n = s.size();
        for ( int i = 0 ; i < n ; i++)
        {
            if ( isalnum(s[i]))
            {
                output.push_back(s[i]);
            }
            else 
            {
               
                if (s[i] == '(')
                {
                    st.push(s[i]);
                }
                else if ( s[i] ==  ')')
                {
                    while ( !st.empty() && st.top() != '(')
                    {
                          output.push_back(st.top());
                          st.pop();
                    }
                   if ( !st.empty()) 
                   st.pop();
                }
                //DONT consider right precedence of ^ ,  when we reverse the string then like if it was  3 ^ 2^4 it becomes 
                //4^2^3 like in before 3 power 2 power 4, there is right precedence like first we have to calculate 2 power 4 then only we do 3 power( 2 power 4) liek that
                // so here it has left precedence , means it is no more an exeption here .
            //   else if ( precedence(s[i] ) == 3)
            //     {
            //         st.push(s[i]);
            //     }
                else if ( !st.empty() && precedence(st.top()) >= precedence(s[i]))
                {
                    while ( !st.empty() && precedence(st.top()) >= precedence(s[i]) )
                    {
                        output.push_back(st.top());
                        st.pop();
                    }
                    st.push(s[i]);
                }
                else //this takes care of empty stack and precedence(st.top()) < precedence(s[i]) case 
                {
                    st.push(s[i]);
                }
                
            }
            
        }
        while( !st.empty())
        {
            output.push_back(st.top());
            st.pop();
        }
        reverse(output.begin() , output.end());
        return output;
    }
};
