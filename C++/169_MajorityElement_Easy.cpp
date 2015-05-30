/*
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Tags: Divide and Conquer, Array, Bit Manipulation
*/
class Solution {
public:
    int majorityElement(vector<int> &num) {
        int count = 0;
        int candidate;
        
        for(int i = 0; i < num.size(); ++i) {
            if(count == 0) {
                candidate = num[i];
                count = 1;
            }
            else
                count = (candidate == num[i]) ? ++count : --count;
        }
        return candidate;
    }
};
