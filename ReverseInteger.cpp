#include <iostream>
#include <string>

class Solution {
public:
	int reverse(int x);
};

int reverse(int x)
{
	//If the initial number cannot be flipped, return 0.
	if (x > INT_MAX || x < INT_MIN)
		return 0;

	std::string s = std::to_string(x);
	std::string newString = "";
	
	//If it's negative, append a minus sign.
	if (x < 0)
		newString += "-";

	for (int a = s.length() - 1; a >= 0; a--)
		newString += s.at(a);

	//Convert to 'long' in case the flipped number > INT_MAX
	long newNumber = stol(newString);

	//If the flipped number is too big / too small, return 0.
	if (newNumber > INT_MAX || newNumber < INT_MIN)
		return 0;

	return (int)newNumber;

}//reverse