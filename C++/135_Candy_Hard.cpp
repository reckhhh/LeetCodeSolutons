/*
 There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

    Each child must have at least one candy.
    Children with a higher rating get more candies than their neighbors.

What is the minimum candies you must give? 

Tags: Greedy
*/
class Solution {
public:
    int candy(vector<int> &ratings) {
        vector<int> A(ratings.size(), 1);
        for(int i = 1; i < ratings.size(); ++i) {
            A[i] = (ratings[i] > ratings[i-1]) ? A[i-1] + 1 : 1;
        }
        int sum = A[ratings.size() - 1];
        for(int i = ratings.size() - 2; i >= 0; --i) {
            A[i] = (ratings[i] > ratings[i+1] && A[i+1] + 1 > A[i]) ? A[i+1] + 1 : A[i];
            sum += A[i];
        }
        return sum;
    }
};
