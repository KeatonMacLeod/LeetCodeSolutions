class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        set<vector<int> > answer;
        
        if (nums.size() < 4)
            return{};
        
        std::sort(nums.begin(),nums.end());

        for (int a = 0; a < nums.size()-3; a++) {
            for (int b = a+1; b < nums.size()-2; b++) {
                    int start = b+1;
                    int end = nums.size()-1;

                    while (start < end) {
                        if (nums[a] + nums[b] + nums[start] + nums[end] == target) {
                            vector<int> tmp(4);
                            tmp[0] = nums[a];
                            tmp[1] = nums[b];
                            tmp[2] = nums[start];
                            tmp[3] = nums[end];
                            answer.insert(tmp);

                            start++;
                            end--;
                        }
                        else if (nums[a] + nums[b] + nums[start] + nums[end] < target) {start++;}
                        else {end--;}
                    }
                }
            }
            
        vector<vector<int>>result(answer.begin(),answer.end());
        return result;
    }
};
