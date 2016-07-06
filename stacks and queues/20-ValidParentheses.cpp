/*  Valid Parantheses
    Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
    The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int i=0;
        while(i < s.length()){
            if(s[i]=='(' ||s[i]=='{'||s[i]=='[')
                st.push(s[i]);
            else if(s[i]== ')' || s[i]=='}' || s[i]== ']'){
                if(st.empty() || !isMatching(st.top(),s[i]))
                    return false;
                else 
                    st.pop();
            }
            ++i;
        }
        return st.empty() ? true : false;
    }
    bool isMatching(char begin, char close_seen){
        char close;
        if(begin== '(')
            close= ')';
        else if(begin== '{')
            close= '}';
        else if(begin== '[')
            close= ']';
        if(close == close_seen)
            return true;
        return false;
    }
};