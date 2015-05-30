/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

Tags: Stack, String
*/
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        stk.push('#');
        
        for(int i = 0; i < s.length(); ++i) {
                 if(stk.top() == '(' && s[i] == ')')   stk.pop();
            else if(stk.top() == '[' && s[i] == ']')   stk.pop();
            else if(stk.top() == '{' && s[i] == '}')   stk.pop();
            else stk.push(s[i]);
        }
        
        return (stk.top() == '#') ? true : false;
    }
};
