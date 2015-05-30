/*
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4. 

Tags: Dynamic Programming, String
*/
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        int ans = 0, sz  = s.size();
        for(int i = 0; i < sz; ++i) {
            if(s[i] == '(')
                stk.push(i);
            else {
                if(!stk.empty() && s[stk.top()] == '(')
                    stk.pop();
                else
                    stk.push(i);
            }
        }
        
        if(stk.empty())
            return sz;
        else {
            int a = sz, b = 0;
            while(!stk.empty()) {
                b = stk.top();  stk.pop();
                ans = max(ans, a - b - 1);
                a = b;
            }
            ans = max(ans, a);
        }
        return ans;
    }
};
