//Determine whether an integer is a palindrome. Do this without extra space.
//I used one of the most innovative solutions for this problem as a guideline.

class Solution {
public:
    bool isPalindrome(int x) {
        
        if (x < 0 || x != 0 && x % 10 == 0) //Check for numbers less than zero, and any number with a zero at the end
        return false;
        
        int sum = 0;
        while (x > sum)
        {
            sum = sum*10+x%10;
            x = x/10;
        }
        return (x==sum) || (x==sum/10); //If they are equal, or they are equal besides the middle digit
    }
};
