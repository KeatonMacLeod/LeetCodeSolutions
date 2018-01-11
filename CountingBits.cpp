class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> vec;
        for (int a=0; a <= num; a++)
            vec.push_back(__builtin_popcount(a));
        return vec;
    }
};
