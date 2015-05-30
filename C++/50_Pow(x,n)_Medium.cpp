/*
Implement pow(x, n).

Tags: Math, Binary Search
*/
class Solution {
public:
    double pow(double x, int n) {
        if (n == 0)
            return 1;
            
        double tmp = pow(x, n / 2);
        if (n % 2 == 0)
            return tmp * tmp;
        else {
            if (n > 0)
                return tmp * tmp * x;
            else
                return tmp * tmp / x;
        }
    }
};
