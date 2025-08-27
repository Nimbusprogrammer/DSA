#include <string>
#include <stack>
using namespace std;
class Solution {
  public:
    int precedence ( char k)
    {
        if ( k == '^')
        {
            return 3;
        }
        else if ( k == '*' || k == '/' )
        {
            return 2;
        }
        else if ( k == '+' || k == '-' )
        return 1;
        return 0;
    }
    string infixToPostfix(string& s) {
        // code here
        string output ;
        stack<char> st;
        int n = s.size();
        for ( int i = 0 ; i < n ;i++ )
        {
            //check if its an operand and put it in outpout string , if its an operator put in stack 
            if ( isalnum(s[i]))
            {
                output.push_back(s[i]);
                
            }
            else 
            {
                if ( st.empty())
                st.push(s[i]);
               else if ( s[i] == '(')
                {
                    st.push(s[i]);
                }
                else if ( s[i] == ')')
                {
                    while ( !st.empty() && st.top() != '(')
                    {
                        output.push_back(st.top());
                        st.pop();
                    }
                 
                 st.pop();
                }
                
                else 
                {
                   
                    while( !st.empty() && precedence(st.top()) >= precedence(s[i]))
                    {output.push_back(st.top());
                    st.pop();}
                    st.push(s[i]);
                }
               
            }
        }
        while( !st.empty())
        {
            output.push_back(st.top());
            st.pop();
        }
        return output;
    }
};
