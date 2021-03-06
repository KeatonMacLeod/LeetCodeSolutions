/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

class Solution {
public:
    bool isValid(string s) {
        std::stack<char> stack;
        
        for (int a = 0; a < s.length(); a++)
        {
            char curr = s.at(a);
            
            if (curr == '{' || curr == '[' || curr == '(')
                stack.push(curr);
            
            else
            {
                if (stack.empty()) return false;
                char top = stack.top();
                stack.pop();
                if (top == '{' && curr != '}') return false;
                else if (top == '[' && curr != ']') return false;
                else if (top == '(' && curr != ')') return false; 
            }//else
            
        }//for
        
        if (stack.empty())
            return true;
        else 
            return false;
    }
};
