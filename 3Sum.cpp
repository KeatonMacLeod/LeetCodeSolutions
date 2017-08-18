/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.

For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

#include <iostream>
#include <vector>
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> answer;
        
        if (nums.size() <= 2)
            return answer;
        
        std::sort(nums.begin(),nums.end());

        for (int a = 0; a <= nums.size()-3; a++) {
                           
            if (a == 0 || nums[a] > nums[a-1]) { //Avoid duplicates
                int start = a+1;
                int end = nums.size()-1;

                while (end > start) {
                    if (nums[a] + nums[start] + nums[end] == 0) {
                        vector<int> temp;
                        temp.push_back(nums[a]);
                        temp.push_back(nums[start]);
                        temp.push_back(nums[end]);
                        answer.push_back(temp);
                    }
                    
                    if (nums[a] + nums[start] + nums[end] < 0) {
                        int curr_start = start;
                        while (nums[curr_start] == nums[start] && end > start) start++;
                    }

                    else {
                        int curr_end = end;
                        while (nums[curr_end] == nums[end] && end > start) end--;
                    }
                    
                }//while
            }//if
        }//for
        
    return answer;
    }
};
