/*Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int lo = 0;
        int hi = height.size()-1;
        int max = 0;
        while (lo < hi)
        {
            int dim = min(height[lo], height[hi]);
            int area = dim * (hi-lo);
            if (max < area) max = area;
            while (height[lo] <= dim && lo < hi) lo++;
            while (height[hi] <= dim && lo < hi) hi--;
        }
        return max;
    }
};
