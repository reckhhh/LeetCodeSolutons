/*
Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"]. 

Tags: Dynamic Programming Backtracking
*/
class Solution {
public:
    void collect(vector<list<int> > mark, int i, string s, string path, vector<string>& result){
        for(auto& stop : mark[i]) {
            string sub = s.substr(i, stop - i);
            string newpath = path + ((i == 0) ? sub : " " + sub);
            if(stop == s.size())
                result.push_back(newpath);
            else 
                collect(mark, stop, s, newpath, result);
        }
    }
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        int N = s.size();
        vector<list<int> > mark(N, list<int>());
        for(int stop = N; stop >= 0; --stop) {
            if(stop < N && mark[stop].empty())
                continue;
            for(int start = stop - 1; start >= 0; --start) {
                if(dict.count(s.substr(start, stop - start)) > 0)
                    mark[start].push_back(stop);
            }
        }
        vector<string> result;
        collect(mark, 0, s, "", result);
        return result;
    }
};
