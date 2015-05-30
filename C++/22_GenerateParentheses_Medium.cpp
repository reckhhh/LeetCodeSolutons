/*
 Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()" 

Tags: Backtracking, String
*/
class Solution {
public:
    void generate(vector<string> &result, string s, int l, int r, int n) {
        if(l == n) {
            result.push_back(s.append(n - r, ')'));
            return;
        }
        generate(result, s + "(", l + 1, r, n);
        if(l > r)
            generate(result, s + ")", l, r + 1, n);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generate(result, "", 0, 0, n);
        return result;
    }
};
