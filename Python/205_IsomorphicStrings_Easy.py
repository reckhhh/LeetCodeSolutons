"""
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
"""
class Solution:
    # @param {string} s
    # @param {string} t
    # @return {boolean}
    def isIsomorphic(self, s, t):
        if len(s) != len(t):
            return False
        def helper(s, t):
            dic = {}
            for i in range(len(s)):
                if s[i] not in dic:
                    dic[s[i]] = t[i]
                elif dic[s[i]] != t[i]:
                    return False
            return True
        return helper(s, t) and helper(t, s)