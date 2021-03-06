/*Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example:

Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.
Example:

Input: "cbbd"

Output: "bb"
*/

class Solution {
public:
    string isPalindrome(string chop, string longest)
    {
        if (chop == string(chop.rbegin(),chop.rend()))
            longest = chop;
        return longest;
    }
    
    string longestPalindrome(string s) {
        string current = s;
        string longest = "";
        string chop = "";
        while (current.length() > longest.length()) //Keep low index move in from the right
        {
            chop = current;
            bool checked_all = false;
            int pos;
            while (!checked_all && chop.length() > longest.length() && chop.length() > 0)
            {
                pos = chop.find_last_of(chop.at(0));
                if (pos > 0)
                chop = chop.substr(0,pos+1);
                if (chop.length() > longest.length())
                longest = isPalindrome(chop, longest);
                if (pos == 0) checked_all = true;
                else chop = chop.substr(0,pos);
            }
            chop = current;
            checked_all = false;
            while (!checked_all && chop.length() > longest.length() && chop.length() > 0) //Keep high index move in from the left
            {
                pos = chop.find_first_of(chop.at(chop.size()-1));
                chop = chop.substr(pos,chop.size());
                if (chop.length() > longest.length())
                longest = isPalindrome(chop, longest);
                if (chop.size() == 1) checked_all = true;
                else chop = chop.substr(chop.find_first_of(chop.at(chop.size()-1)),chop.size()-1);
            }
            current = current.substr(1,current.size()-1);
        }
        return longest;
    }//longestPalindrome
};
