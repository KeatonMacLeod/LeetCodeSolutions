/*Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> vec;
        solve(vec,"",n,0);
        return vec;
    }
    
    void solve(vector<string> &vec, string s, int n, int m) {
        if (n==0 && m==0) {
            vec.push_back(s);
            return;
        }
        if (n>0) solve(vec,s+"(",n-1,m+1);
        if (m>0) solve(vec,s+")",n,m-1);
    }
};
