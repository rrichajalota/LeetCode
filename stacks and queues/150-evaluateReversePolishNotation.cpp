/*  Evaluate Reverse Polish Notation
    Evaluate the value of an arithmetic expression in Reverse Polish Notation.

    Valid operators are +, -, *, /. Each operand may be an integer or another expression.

    Some examples:
      ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
      ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
*/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int res=0;
        for(int i =0; i < tokens.size(); ++i){
            if(tokens[i]=="+" || tokens[i]== "-"|| tokens[i]== "*"|| tokens[i]=="/"){
                int op2= s.top();
                s.pop();
                int op1= s.top();
                s.pop();
                if(tokens[i]=="+")
                    res = op1 + op2;
                else if(tokens[i]== "-")
                    res= op1 - op2;
                else if(tokens[i]== "*")
                    res= op1 * op2;
                else 
                    res= op1/ op2;
                s.push(res);
            }
            else {
                int operand = stoi(tokens[i]); // stoi converts string to integer
                s.push(operand);
            }
        }
        if(!s.empty())
            res= s.top();
        return res;
    }
};