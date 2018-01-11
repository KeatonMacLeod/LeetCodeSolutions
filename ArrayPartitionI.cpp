class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        assert(nums.size()%2 == 0);
        std::sort(nums.begin(),nums.end());
        int sum = 0;
        for (int a = 0; a < nums.size(); a+=2) {
            sum += std::min(nums[a], nums[a+1]);
        }
        
        return sum;
    }
};
