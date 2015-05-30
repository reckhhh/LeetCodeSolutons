/*
 Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"

Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the emtpy string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S. 

Tags: Hash Table, Two Pointers, String
*/
class Solution {
public:
    string minWindow(string S, string T) {
        int len = S.size(), count = T.size();
        if(len == 0 || count == 0)
            return "";
            
        int  require[128] = {0};
        bool charSet[128] = {false};
        for(int i = 0 ; i < count; ++i) {
            ++require[T[i]];
            charSet[T[i]] = true;
        }
        
        int i = -1, j = 0;
        int minLen = INT_MAX, minId = 0;
        while(i < len && j < len) {
            if(count > 0) {
                ++i;
                --require[S[i]];
                if(require[S[i]] >= 0 && charSet[S[i]] == true)
                    --count;
            }
            else {
                if(minLen > i - j + 1) {
                    minLen = i - j + 1;
                    minId  = j;
                }
                ++require[S[j]];
                if(require[S[j]] > 0 && charSet[S[j]] == true) {
                    ++count;
                }
                ++j;
            }
        }
        return (minLen == INT_MAX) ? "" : S.substr(minId, minLen);
    }
};
