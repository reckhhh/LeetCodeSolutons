/*
Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true

Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.

Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button to reset your code definition. 

Tags: Math, String
*/
class Solution {
public:
    bool isNumber(const char *s) {
        int i = 0, num = 0, point = 0;
        for(; isspace(s[i]); ++i)
            ;
        if(s[i] == '+' || s[i] == '-')
            ++i;
        for(num = 0, point = 0; isdigit(s[i]) || s[i] == '.'; ++i)
            s[i] == '.' ? ++point : ++num;
        if(point > 1 || num < 1)
            return false;
            
        if(s[i] == 'e') {
            ++i;
            for(; isspace(s[i]); ++i)
                ;
            if(s[i] == '+' || s[i] == '-')
                ++i;
            for(num = 0; isdigit(s[i]); ++i, ++num)
                ;
            if(num < 1)
                return false;
        }
        
        for(; isspace(s[i]); ++i)
            ;
        return s[i] == '\0';
    }
};
