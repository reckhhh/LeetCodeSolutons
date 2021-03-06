/*
Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no extra space is inserted between words.

For example,
words: ["This", "is", "an", "example", "of", "text", "justification."]
L: 16.

Return the formatted lines as:

[
   "This    is    an",
   "example  of text",
   "justification.  "
]

Note: Each word is guaranteed not to exceed L in length.

click to show corner cases.
Corner Cases:

    A line other than the last line might contain only one word. What should you do in this case?
    In this case, that line should be left-justified.

Tags: String
*/
class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> ans, vs;
        string str;
        int len = 0;
        for(int i = 0; i < words.size(); ++i) {
            if(len + words[i].size() + vs.size() <= L) {    // when lengh is shorter than or equal to L
                vs.push_back(words[i]);
                len += words[i].size();
            }
            else {
                if(vs.size() == 1) {                        // only one word
                    str = vs[0];
                    str.append(L - str.size(), ' ');
                }
                else if(vs.size() > 1) {                    // more than one word
                    int quo = (L - len) / (vs.size() - 1);
                    int mod = (L - len) % (vs.size() - 1);
                    str = vs[0];
                    for(int j = 1; j < vs.size(); ++j) {
                        if(j <= mod)    str.append(quo + 1, ' ');   // odd  blanks
                        else            str.append(quo,     ' ');   // even blanks
                        str += vs[j];
                    }
                }
                ans.push_back(str);         // push current string to answer
                
                vs.clear();
                vs.push_back(words[i]);     // push next string to vector<stirng> vs;
                len = words[i].size();
            }
        }
        // the last line
        str = vs[0];
        for(int j = 1; j < vs.size(); ++j) {
            str += ' ' + vs[j];
        }
        str.append(L - str.size(), ' ');
        ans.push_back(str);
        
        return ans;
    }
};
