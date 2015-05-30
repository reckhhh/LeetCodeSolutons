/*
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"

click to show corner cases.
Corner Cases:

    Did you consider the case where path = "/../"?
    In this case, you should return "/".
    Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
    In this case, you should ignore redundant slashes and return "/home/foo".

Tags: Stack, String
*/
class Solution {
public:
    vector<string> getPath(vector<string> vect, string path) {
        string name;
        for(int i = 0; i < path.size(); ++i) {
            if(path[i] == '/') {
                if(name.size() == 0)
                    continue;
                if(name == "..") {
                    if(vect.size() > 0)
                        vect.pop_back();
                }
                else if(name != ".") {
                    vect.push_back(name);
                }
                name.clear();
            }
            else
                name.push_back(path[i]);
        }
        return vect;
    }
    string getAnswer(vector<string> vect) {
        string ans;
        if(vect.empty())    
            return "/";
        for(int i = 0; i < vect.size(); ++i)
            ans.append("/" + vect[i]);
            
        return ans;
    }
    string simplifyPath(string path) {
        vector<string> vect;
        path.push_back('/');
        vect = getPath(vect, path);
        return getAnswer(vect);
    }
};
