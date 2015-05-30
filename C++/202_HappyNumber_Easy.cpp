/*
Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Example: 19 is a happy number

    12 + 92 = 82
    82 + 22 = 68
    62 + 82 = 100
    12 + 02 + 02 = 1

Tags: Hash Table, Math
*/
class Solution {
public:
    int hashTable[1024] = {0};
    int cmpSquareSum(int n) {
        int res = 0;
        while(n != 0) {
            res += pow(n % 10, 2);
            n /= 10;
        }
        return res;
    }
    bool isHappy(int n) {
        int res = cmpSquareSum(n);
        if(res == 1) {
            return true;
        } else {
            if(hashTable[res] == 1) {
                return false;
            } else {
                hashTable[res] = 1;
                return isHappy(res);
            }
        }
    }
};
