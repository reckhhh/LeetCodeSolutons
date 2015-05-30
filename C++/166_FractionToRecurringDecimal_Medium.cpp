/*
Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

For example,

    Given numerator = 1, denominator = 2, return "0.5".
    Given numerator = 2, denominator = 1, return "2".
    Given numerator = 2, denominator = 3, return "0.(6)".

Tags: Hash Table, Math
*/
class Solution {
public:
    string fractionToDecimal(int64_t numerator, int64_t denominator) {
        if(numerator == 0)  return "0";
        string res;
        if(numerator < 0 ^ denominator < 0)  res += '-';
        
        int64_t n = abs(numerator), d = abs(denominator);
        res += to_string(n / d);
        if(n % d == 0)  return res;
            
        res += '.';
        unordered_map<int, int> map;
        for(int64_t r = n % d; r != 0; r = r % d) {
            if(map.count(r) > 0) {
                res.insert(map[r], 1, '(');
                res += ')';
                break;
            }
            map[r] = res.size();
            r *= 10;
            res += to_string(r / d);
        }
        return res;
    }
};
