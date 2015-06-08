/*
 Given an array of integers and an integer k, find out whether there there are two distinct indices i and j in the array such that nums[i] = nums[j] and the difference between i and j is at most k.
 
 Tags: Array, Hash Table
*/
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        set<int> hash;
        //if(k <= 0)  return false;
        //if(k > nums.size())  k = nums.size();
        
        for(int i = 0; i < nums.size(); ++i) {
            if(i > k)  hash.erase(nums[i - k - 1]);
            if(hash.find(nums[i]) != hash.end())  return true;
            hash.insert(nums[i]);
        }
        return false;
    }
};