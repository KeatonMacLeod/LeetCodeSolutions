/*
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

#include <iostream>
#include <string.h>

#include <iostream>
#include <string.h>

class Solution {
public:
	int lengthOfLongestSubstring(std::string s);
};

int lengthOfLongestSubstring(std::string s)
{
	std::string lettersSeen = "";
	int startOfString = 0;
	int endOfString = 0;
	int firstSeen = 0; //Used to track the first index we saw our duplicate character at.
	int overallSubstringLength = 0; //The largest substring length without duplicates we've seen.
	int currentSubstringLength = 0; //The current substring length without duplicates we've seen.

	for (int a = 0; a < s.length(); a++)
	{

		//If we've already seen that letter in our greatest substring:
		if (lettersSeen.find(s.at(a)) != std::string::npos)
		{
			firstSeen = lettersSeen.find(s.at(a));
			//Start one position after the duplicate letter and continue searching for the longest substring.
			lettersSeen = lettersSeen.substr(firstSeen + 1, lettersSeen.length());
			currentSubstringLength = lettersSeen.length();
		}

		//Add the next letter to the letters we've already seen.
		lettersSeen += s.at(a);
		currentSubstringLength++;

		//If we ever see a greater substring lenghth, make it the overall best.
		if (currentSubstringLength > overallSubstringLength)
			overallSubstringLength = currentSubstringLength;

	}

	return overallSubstringLength;

}
