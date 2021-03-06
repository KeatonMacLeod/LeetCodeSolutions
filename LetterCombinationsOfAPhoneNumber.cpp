/*Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.



Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
*/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        
        string letters [10] = {"", "", "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> result;
        
        for (int a = 0; a < digits.length(); a++) {
            if (digits.at(a) == '0' || digits.at(a) == '1') {
                result.clear();
                return result;
            }
            
            string curr = letters[digits[a]-'0'];
            
            if (result.size() == 0) {
                for (int b = 0; b < curr.length(); b++)
                    result.push_back(string(1,curr.at(b)));
            }//if
            
            else {
                vector<string> vec;
                for (int c = 0; c < result.size(); c++)
                    for (int d = 0; d < curr.length(); d++)
                        vec.push_back(result[c] + curr.at(d));
                result = vec;
            }//else
            
        }//for
        return result;
    }
};
