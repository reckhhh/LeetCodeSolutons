/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R

And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);

convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

Tags: String
*/
class Solution {
public:
    string convert(string s, int nRows) {
    if (nRows <= 1)
       return s;
    
    string t = s;
    int len  = s.size();
    
    int dis  = (nRows - 1) * 2;     // 6
    int dis1 = dis;                 // 6
    int dis2 = 0;                   // 0
    
    int row = 0, pt = 0, ps = 0;
    while (pt < len)     // for each row
    {   
        if (ps > len - 1)   {  
            row += 1;
            ps = row;
            
            dis1 = dis - row * 2;
            dis2 = dis - dis1;
        }

        if (row == 0 || row == nRows - 1)
        {
           if (pt == 0) {
               t[pt++] = s[0];
               ps += dis;
           }
           else {
               t[pt++] = s[ps];
               ps += dis;
               
           }
        }
        else {
            t[pt++] = s[ps];
            ps += dis1;
            swap (dis1, dis2);
        } 
    }
    return t;
    }
};
