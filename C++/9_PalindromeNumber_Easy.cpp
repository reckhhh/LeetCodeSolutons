/*
Determine whether an integer is a palindrome. Do this without extra space.

click to show spoilers.
Some hints:

Could negative integers be palindromes? (ie, -1)

If you are thinking of converting the integer to string, note the restriction of using extra space.

You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?

There is a more generic way of solving this problem.

Tags: Math
*/
class Solution {
public:
    bool isPalindrome(int x) {
        int digit = 1000000000;	// the capacity of x
	    int head;		        // first num at head
	    int tail;		        // last  num at tail

	    if (x < 0)
		    return false;
		if (x / 10 == 0)
		    return true;

	    while (x / digit == 0)
		    digit /= 10;

	    while (x > 0)
	    {
		    head = x / digit;
		    tail = x % 10;

		    if (head != tail)
			    return false;

		    x -= head * digit;
		    x /= 10;
		    digit /= 100;
	    }
    	return true;
    }
};

