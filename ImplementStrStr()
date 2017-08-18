/*
Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        
        if (haystack == "" && needle == "")
            return 0;
        
        int index = -1;
    
        for (int a = 0; a < haystack.length() && index == -1; a++)
            if (haystack.substr(a,needle.length()).compare(needle) == 0)
                index = a;  

        return index;
    }
};
