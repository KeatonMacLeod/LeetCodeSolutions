/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
*/

class Solution {
public:
    string convert(string s, int numRows) {
        
        if (numRows == 1)
            return s;
        
        std::vector < std::vector<int> > vector;
        for (int a = 0; a < numRows; a++)
        {
            std::vector<int> temp;
            vector.push_back(temp);
        }
        
        bool increment = true;
        int index = 0;
        
        for (int a = 0; a < s.length(); a++)
        {
            int letter = s[a];
            vector[index].push_back(s[a]);
            
            if (index == 0)
                increment = true;
            else if (index == numRows-1)
                increment = false;
            
            if (increment)
                index++;
            else
                index--;
        }
        
        string zig_zag = "";
        
        for (int b = 0; b < vector.size(); b++)
            for (int c = 0; c < vector[b].size(); c++)
                zig_zag += vector[b][c];

        return zig_zag;
    }
    
};
