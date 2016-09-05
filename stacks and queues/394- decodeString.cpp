/*  394. Decode String

    The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

    You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

    Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].

    Examples:

    s = "3[a]2[bc]", return "aaabcbc".
    s = "3[a2[c]]", return "accaccacc".
    s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
*/

class Solution {
public:
    string decodeString(string s) {
        stack<char> sta;
        stack<int> number;
        string res;
        for(int i=0; i < s.length(); i++){
            
            if(isdigit(s[i])){
                int num=0;
                while(isdigit(s[i])){
                    num = num*10 + s[i]-'0';
                    ++i;
                }
                --i;
                number.push(num);
            }
            else if(s[i] != ']')
                sta.push(s[i]);
            else{
                string st;
                while(sta.top() != '['){
                    st = sta.top() + st;
                    sta.pop();
                }
                sta.pop();
                if(!number.empty()){
                    int k= number.top();
                    number.pop();
                    string str;
                    while( k > 0){
                        str += st;
                        --k;
                    }
                    if(sta.empty())
                        res += str;
                    else{
                        for (char c: str){
                            sta.push(c);
                        }
                    }
                }
            }
        }
        string str;
        while(!sta.empty()){
            str = sta.top() + str;
            sta.pop();
        }
        res+= str;
        return res;
    }
};