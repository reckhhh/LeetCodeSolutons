/*
 All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

For example,

Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",

Return:
["AAAAACCCCC", "CCCCCAAAAA"].

Tags: Hash Table, Bit Manipulation
*/
class Solution {
public:
    int str2int(string s) {
        int num = 0;
        for (int i = 0; i < s.size(); ++i)
            num = num << 3 | s[i] & 7;
        return num;
    }
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        unordered_map<int, int> m;
        for(int i = 0; i + 10 <= s.size(); ++i) {
            string t = s.substr(i, 10);
            if(m[str2int(t)]++ == 1)    ans.push_back(t);
        }
        return ans;
    }
};

