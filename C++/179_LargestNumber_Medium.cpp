/*
Given a list of non negative integers, arrange them such that they form the largest number.

For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.

Tags: Sort
*/
class Solution {
public:
    static bool compare(int a, int b) {
        string s1 = to_string(a), s2 = to_string(b);
        int m = s1.size(), n = s2.size();
        
        for(int i = 0, j = 0; i < m, j < n; ) {
            if(s1[i] != s2[j])   return s1[i] < s2[j];
            
            if(i == m-1 && j == n-1)    return false;   // not need to swap
            else if(i == m-1)   {  i = 0; ++j;  }
            else if(j == n-1)   {  j = 0; ++i;  }
            else                {    ++i; ++j;  }
        }
    }
    string largestNumber(vector<int> &num) {
        string res;
        sort(num.begin(), num.end(), compare);
        
        for(auto i : num) {
            res = to_string(i) + res;
        }
        return res[0] == '0' ? "0" : res;
    }
};
