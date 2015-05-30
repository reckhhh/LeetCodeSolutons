/*
 Given two words (beginWord and endWord), and a dictionary, find the length of shortest transformation sequence from beginWord to endWord, such that:

    Only one letter can be changed at a time
    Each intermediate word must exist in the dictionary

For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]

As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:

    Return 0 if there is no such transformation sequence.
    All words have the same length.
    All words contain only lowercase alphabetic characters.

Tags: Breadth-first Search
*/
class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        unordered_map<string, int> length;
        length[start] = 1;
        
        queue<string> q;
        q.push(start);
        
        while(!q.empty()) {
            string curWord = q.front();
            q.pop();
            
            if(curWord == end)  break;
            
            for(int i = 0; i < curWord.size(); ++i) {
                string temp = curWord;
                for(char ch = 'a'; ch <= 'z'; ++ch) {
                    temp[i] = ch;
                    
                    if(dict.count(temp) > 0 && length.count(temp) == 0) {
                        length[temp] = length[curWord] + 1;
                        q.push(temp);
                    }
                }
            }
        }
        return (length.count(end) == 0) ? 0 : length[end];
    }
};
