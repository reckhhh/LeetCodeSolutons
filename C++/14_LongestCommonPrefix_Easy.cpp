/*
Write a function to find the longest common prefix string amongst an array of strings. 

Tags: String
*/
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if(strs.size() == 0)
            return "";
            
        int pos = -1;
        bool done = false;
        
        while(!done) {
            if(++pos == strs[0].size())
                break;
                
            char c = strs[0][pos];
            for(int i = 0; i < strs.size(); ++ i) {
                if(pos > strs[i].size() - 1 || c != strs[i][pos]) {
                    done = true;
                    break;
                }
            }
        }
        return (pos == 0) ? "" : strs[0].substr(0, pos);
    }
};
