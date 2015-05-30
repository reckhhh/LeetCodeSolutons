/*
Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.

Tags: Array, Math
*/
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        for(int i = digits.size() - 1; i >= 0; --i) {
            if (digits[i] == 9)
                digits[i] = 0;
            else {
                digits[i]++;
                return digits;
            }
        }
        digits[0] = 1;
        digits.push_back(0);
        
        return digits;
    }
};
