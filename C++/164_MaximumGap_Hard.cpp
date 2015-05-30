/*
Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Try to solve it in linear time/space.

Return 0 if the array contains less than 2 elements.

You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.

Tags: Sort
*/
class Solution {
public:
    int maximumGap(vector<int> &num) {
        int n = num.size();
        if(n < 2)
            return 0;
            
        vector<int> minBucket(n, INT_MAX);
        vector<int> maxBucket(n, INT_MIN);
        
        int minNum = *min_element(num.begin(), num.end());
        int maxNum = *max_element(num.begin(), num.end());
    
        int gap = (maxNum - minNum - 1) / (n - 1) + 1;
        for(int i = 0; i < n; ++i) {
            if (num[i] != minNum && num[i] != maxNum) {
                int index = (num[i] - minNum) / gap;
                minBucket[index] = min(num[i], minBucket[index]);
                maxBucket[index] = max(num[i], maxBucket[index]);
            }
        }
        
        int maxGap = INT_MIN;
        int prev   = minNum;
        for(int i = 0; i < n; ++i) {
            if(minBucket[i] != INT_MAX || maxBucket[i] != INT_MIN) {
                maxGap = max(minBucket[i] - prev, maxGap);
                prev   = maxBucket[i];
            }
        }
        maxGap = max(maxNum - prev, maxGap);
        
        return maxGap;
    }
};
