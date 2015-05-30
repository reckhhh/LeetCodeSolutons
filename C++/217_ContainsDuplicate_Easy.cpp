/*
 Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.
 
 Tags: Array, Hash Table
 */

// Solution 1: O(nlog(n))

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1)  return false;
        
        sort(nums.begin(), nums.end());
        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i] == nums[i - 1])  return true;
        }
        return false;
    }
};

// Solution 2: O(n)

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size() == 1 || nums.size() == 0)  return false;
        
        set<int> hashTable;
        for(int i = 0; i < nums.size(); ++i) {
            if(hashTable.find(nums[i]) != hashTable.end()) {
                return true;
            }
            hashTable.insert(nums[i]);
        }
        return false;
    }
};
