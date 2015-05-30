/*
Given an array of strings, return all groups of strings that are anagrams.

Note: All inputs will be in lower-case.

Tags: Hash Table, String
*/
class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> result;
        map<string, vector<string> > hashmap;
        for(string s : strs) {
            string tmp = s;
            sort(tmp.begin(), tmp.end());
            hashmap[tmp].push_back(s);
        }
        for(auto mp : hashmap) {
            if(mp.second.size() > 1)
                result.insert(result.end(), mp.second.begin(), mp.second.end());
        }
        return result;
    }
};
