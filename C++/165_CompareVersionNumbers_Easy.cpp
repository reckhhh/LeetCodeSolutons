/*
Compare two version numbers version1 and version2.
If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 13.37

Tags: String
*/
class Solution {
public:
    string nextSubstr(string s) {
        for(int i = 0; i < s.size(); ++i) {
            if(s.at(i) == '.')
                return s.substr(i+1);
        }
        return "0";
    }
    int compareVersion(string version1, string version2) {
        for(; version1 != version2; version1 = nextSubstr(version1), version2 = nextSubstr(version2)) {
            int gap = stoi(version1) - stoi(version2);
            if(gap != 0)
                return gap > 0 ? 1 : -1;
        }
        return 0;
    }
};
