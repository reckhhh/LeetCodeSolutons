/*
Given two numbers represented as strings, return multiplication of the numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative.

Tags: Math, String
*/
class Solution {
public:
    string multiply(string num1, string num2) {
        int l1 = num1.size(), l2 = num2.size();
        if(num1 == "0" || num2 == "0" || l1 == 0 || l2 == 0)  return "0";
        vector<int> v(l1 + l2, 0);

        for (int i = 0; i < l1; ++i) {
            int carry = 0;
            int n1 = (int)(num1[l1 - i - 1] - '0');    //Calculate from rightmost to left
            for(int j = 0; j < l2; ++j) {
                int n2   = num2[l2 - j - 1] - '0';      //Calculate from rightmost to left
                int sum  = n1 * n2 + v[i + j] + carry;
                carry  = sum / 10;
                v[i+j] = sum % 10;
            }
            if(carry > 0)   v[i + l2] += carry;
        }
        
        int start = l1 + l2 - 1;
        while(v[start] == 0)    --start;
        if(start == -1) return "0";

        // get results
        string s = "";
        for (int i = start; i >= 0; --i)
            s += (char)(v[i] + '0');
        return s;
    }
};
