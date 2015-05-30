/*
    Follow up for "Find Minimum in Rotated Sorted Array":
    What if duplicates are allowed?

    Would this affect the run-time complexity? How and why?

Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

The array may contain duplicates.

Tags: Array, Binary Search
*/
class Solution {
public:
    int findMin(vector<int> &num) {
        int l = 0;
        int r = num.size() - 1;
        
        while(l < r) {
            if(num[l] < num[r]) return num[l];
            
            int m = (l + r) / 2;
            if(num[m] > num[r]) l = m + 1;
            else if (num[m] < num[r]) r = m;
            else {
                ++l;
                --r;
            }
        }
        return num[l];
    }
};
