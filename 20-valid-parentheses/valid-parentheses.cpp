class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<char> st;
        
        for (int i = 0; i < n; i++) {
            if (s[i] == '{' || s[i] == '(' || s[i] == '[')
                st.push(s[i]);
            // like in this if we see a closed bracket we need to check it with
            // the last open bracket
            else {
                if (st.empty())
                    return false;

                else if (s[i] == ')' && st.top() == '(') {
                    st.pop();

                } else if (s[i] == ']' && st.top() == '[') {
                    st.pop();

                } else if (s[i] == '}' && st.top() == '{') {
                    st.pop();

                } else
                    return false;
            }

        }
        if ( st.empty())
        return true;
        else 
        return false;
    }
};