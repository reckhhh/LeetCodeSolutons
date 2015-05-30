/*
 You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.

For example, given:
s: "barfoothefoobarman"
words: ["foo", "bar"]

You should return the indices: [0,9].

Tags: Hash Table, Two Pointers, String
*/
class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> ans;
        int n = S.size(), cnt = L.size();
        if(n == 0 || cnt == 0)  return ans;
        
        unordered_map<string, int> dict;
        for(int i = 0; i < cnt; ++i)   dict[L[i]]++;    // save the number of occurrences
            
        int wl = L[0].size();
        for(int i = 0; i < wl; ++i) {
            int left  = i, count = 0;   // left for the location of beginning, count for the size of words in L
            unordered_map<string, int> tmp;
            
            for(int j = i; j <= n - wl; j += wl) {
                string str = S.substr(j, wl);
                if(dict.count(str) > 0) {
                    ++tmp[str];
                    if(tmp[str] <= dict[str])
                        ++count;
                    else {
                        while(tmp[str] > dict[str]) {
                            string str1 = S.substr(left, wl);
                            --tmp[str1];
                            if(tmp[str1] < dict[str1])    --count;
                            left += wl;
                        }
                    }
                    if(count == cnt) {
                        ans.push_back(left);
                        --tmp[S.substr(left, wl)];
                        --count;
                        left += wl;
                    }
                }
                else {
                    tmp.clear();
                    count = 0;
                    left  = j + wl;
                }
            }
        }
        return ans;
    }
};
