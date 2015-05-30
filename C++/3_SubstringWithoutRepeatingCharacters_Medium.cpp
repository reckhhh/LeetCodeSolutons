/*
Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.

Tags: Hash Table, Two Pointers, String
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0, startIndex = 0;
        vector<int> hashMap(256, -1);
        
        for(int i = 0; i < s.size(); ++i) {
            startIndex = max(startIndex, hashMap[s[i]] + 1);
            hashMap[s[i]] = i;
            maxLen = max(maxLen, i - startIndex + 1);
        }
        return maxLen;
    }
};
