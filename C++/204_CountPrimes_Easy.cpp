/*
Description:
 
Count the number of prime numbers less than a non-negative number, n

Tags: Hash Table, Math
*/
class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2)  return 0;
        
        bool* hashTable = new bool[n];
        for (int i = 0; i < n; ++i)
            hashTable[i] = true;
        
        for (int i = 2; i < sqrt(n) ; ++i) {
            if (hashTable[i]) {
                for (int j = i * i; j < n; j += i)
                    hashTable[j] = false;
            }
        }
        
        int res = 0;
        for (int i = 2; i < n; ++i)
            res += (hashTable[i]) ? 1 : 0;
        
        delete[] hashTable;
        return res;
    }
};