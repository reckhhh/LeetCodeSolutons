/*
 Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.


Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].


The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given height = [2,1,5,6,2,3],
return 10. 

Tags: Array, Stack
*/
class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        stack<int> s;
        int tp;         // value of "stack top"
        int i = 0, tempArea = 0, maxArea = 0;
        while(i < height.size()) {
            if(s.empty() || height[s.top()] < height[i]) {
                s.push(i++);
            }
            else {
                tp = s.top();
                s.pop();
                tempArea = height[tp] * (s.empty() ? i : i - s.top() - 1);
                maxArea  = max(maxArea, tempArea);
            }
        }
        while(!s.empty()) {
            tp = s.top();
            s.pop();
            tempArea = height[tp] * (s.empty() ? i : i - s.top() - 1);
            maxArea  = max(maxArea, tempArea);
        }
        return maxArea;
    }
};
