/*
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.
*/

class Solution {
public:
    int getValue(string letter, string roman_numerals[], int roman_values[]) {
        int lo = 0;
        int hi = 6;
        int mid = (lo + hi) / 2;
        int value = 0;
        
        while (lo <= hi && value == 0)
        {

            if (strcmp(letter.c_str(),roman_numerals[mid].c_str()) < 0)
                hi = mid-1;
            else if (strcmp(letter.c_str(),roman_numerals[mid].c_str()) > 0)
                lo = mid + 1;
            else if (strcmp(letter.c_str(),roman_numerals[mid].c_str()) == 0)
                value = roman_values[mid];
            
            mid = (lo + hi) / 2;
        }
        
        return value;
    }
    
    string charToString(char c) {
        stringstream ss;
        string target;
        ss << c;
        ss >> target;
        
        return ss.str();
    }
    
    int romanToInt(string s) {
        string roman_numerals [] = {"C","D","I","L","M","V","X"};
        int roman_values [] = {100,500,1,50,1000,5,10};
        int sum = 0;
        int valOne = 0;
        int valTwo = 0;
       
        for (int a = 0; a < s.length(); a++)
        {
            valOne = getValue(charToString(s.at(a)),roman_numerals,roman_values);
            valTwo = 0;
            
            if (a < s.length()-1)
            valTwo = getValue(charToString(s.at(a+1)),roman_numerals,roman_values);
            
            if (valOne < valTwo)
                sum -= valOne;
            else
                sum += valOne;
        }//for

        return sum;
    }
};
