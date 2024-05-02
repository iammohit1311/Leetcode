class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        for(int i=size-1; i>0; i--)
        {
            if(nums[i] > 0 && binary_search(nums.begin(), nums.end(), -nums[i]))
            return nums[i];
        }
        return -1;
    }
};
