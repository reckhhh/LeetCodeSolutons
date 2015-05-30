/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.

Tags: Array, Binary Search
*/
int findMin(int num[], int n) {
    int l = 0;
    int r = n - 1;
        
    while(l < r) {
        int m = (l + r) / 2;
        if(num[m] < num[r]) r = m;
        else l = m + 1;
    }
    return num[l];
}
