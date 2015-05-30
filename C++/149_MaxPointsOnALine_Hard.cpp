/*
Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.

Tags: Hash Table, Math
*/
/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int gcd(int a, int b) {
        if(a == 0)  return b;
        if(b == 0)  return a;
        return gcd(b, a % b);
    }
    int maxPoints(vector<Point> &points) {
        int ans = 0;
        for(int i = 0; i < points.size(); ++i) {
            int slope = 0, same = 1;
            unordered_map<string, int> count;
            for(int j = i + 1; j < points.size(); ++j) {
                int x = points[i].x - points[j].x;
                int y = points[i].y - points[j].y;
                int g = gcd(x, y);  // when x == 0 && y == 0, gcd(x, y) == 0
                
                if(g == 0)  same += 1;      // when g == 0, two points at the same location
                else        slope = max(slope, ++count[to_string(x/g) + ", " + to_string(y/g)]);
            }
            ans = max(ans, slope + same);
        }
        return ans;
    }
};
