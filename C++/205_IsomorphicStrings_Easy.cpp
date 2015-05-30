/*
 Given two strings s and t, determine if they are isomorphic.
 
 Two strings are isomorphic if the characters in s can be replaced to get t.
 
 All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.
 
 For example,
 Given "egg", "add", return true.
 
 Given "foo", "bar", return false.
 
 Given "paper", "title", return true.
 
 Note:
 You may assume both s and t have the same length.

Tags: Hash Table
*/
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> hash_s(128, 0);
        vector<int> hash_t(128, 0);
        
        for(int i = 0; i < s.size(); ++i) {
            if (hash_s[s[i]] != hash_t[t[i]]) {
                return false;
            }
            hash_s[s[i]] = i+1;
            hash_t[t[i]] = i+1;
        }
        return true;
    }
};