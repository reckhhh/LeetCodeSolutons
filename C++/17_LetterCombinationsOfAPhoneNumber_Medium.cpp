/*
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.

Tags: Backtracking, String
*/
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        map<char, string> phone;
        phone['2'] = "abc";
        phone['3'] = "def";
        phone['4'] = "ghi";
        phone['5'] = "jkl";
        phone['6'] = "mno";
        phone['7'] = "pqrs";
        phone['8'] = "tuv";
        phone['9'] = "wxyz";
        
        if(digits.size() == 0) {
            result.push_back("");
            return result;
        }
        
        string current = phone[digits[0]];
        if(digits.size() == 1) {
            for(int i = 0; i < current.size(); ++i) {
                string temp = "";
                temp.push_back(current[i]);
                result.push_back(temp);
            }
            return result;
        }
        
        string next = digits.substr(1, digits.size() - 1);
        vector<string> iter = letterCombinations(next);
        for(int i = 0; i < current.size(); ++i) {
            for(int j = 0; j < iter.size(); ++j) {
                string temp = "";
                temp.push_back(current[i]);
                result.push_back(temp + iter[j]);
            }
        }
        return result;
    }
};
