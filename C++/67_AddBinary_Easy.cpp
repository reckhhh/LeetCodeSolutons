/*
 Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100". 

Tags: Math, String
*/
class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int lenA = a.size() - 1;
        int lenB = b.size() - 1;
        int byteA, byteB, carry = 0;
        
        while(lenA >= 0 || lenB >= 0 || carry == 1) {
            byteA  = (lenA >= 0) ? (a[lenA--] - '0') : 0;
            byteB  = (lenB >= 0) ? (b[lenB--] - '0') : 0;
            result = static_cast<char>(byteA ^ byteB ^ carry + '0') + result;
            carry  = ((byteA + byteB + carry) > 1) ? 1 : 0; 
        }
        return result;
    }
};
