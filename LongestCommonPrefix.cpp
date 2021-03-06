/*Write a function to find the longest common prefix string amongst an array of strings.*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0)
            return "";
        string build = strs[0];
        string curr = "";
        
        for (int i = 1; i < strs.size(); i++)
        {
            curr = strs[i];
            bool modified = false;
            for (int j = 0; j < strs[i].length() && j < build.length() && !modified; j++)
            {       
                if (strs[i].at(j) != build.at(j))
                    modified = true;
                if (modified)
                    build = build.substr(0,j);  
            }//for
    
            if (strs[i].length() < build.length())
                build = build.substr(0,strs[i].length());
        }//for
        
        return build;
    }//longestCommonPrefix
};
