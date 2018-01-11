class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        if (nums.size() < 3)
            return 0;
        
        std::sort(nums.begin(), nums.end());
        
        int closest_sum = INT_MIN;
        
        for (int a = 0; a <= nums.size()-3; a++) {
        
            int start = a+1;
            int end = nums.size()-1;
            int sum = 0;
            
            if (a == 0 || nums[a] > nums[a-1]) //Avoid duplicates
            {
                while (end > start) {
                    sum = nums[a] + nums[start] + nums[end];
                    
                    if (sum == target)
                        return sum;
                    
                    else if (abs(target - sum) < abs(target - closest_sum) || closest_sum == INT_MIN) {
                        closest_sum = sum;
                    }

                    else if (sum < target) {
                        int curr_start = start;
                        while (nums[curr_start] == nums[start] && end > start) start++;
                    }

                    else if (sum > target) {
                        int curr_end = end;
                        while (nums[curr_end] == nums[end] && end > start) end--;
                    }
                    
                }//while

            }//if
            
        }//for
        
        return closest_sum;
    }
};
