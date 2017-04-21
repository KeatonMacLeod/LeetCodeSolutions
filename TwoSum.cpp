/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int> &numbers, int target)
	{
		//Key is the number and value is its index in the vector.
		unordered_map<int, int> hash;
		vector<int> result;

		for (int i = 0; i < numbers.size(); i++) {
			int difference = target - numbers[i];

			//if difference is found in map, return them
			if (hash.find(difference) != hash.end()) {
				result.push_back(hash[difference]); //Get the first occurance of that number in the hash map.
				result.push_back(i); //Get the index that numbers[i] would be at.
				return result;
			}

			//The difference between target and numbers[i] is not in the map, put numbers[i] in the hash.
			hash[numbers[i]] = i;
		}
		return result;
	}
};