class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int len = nums.size();
        
        int ahead = 1, prev = 1;
        for(int i=1; i<len; i++)
        {
            if(nums[i] > nums[i-1]) ahead = prev+1;
            if(nums[i] < nums[i-1]) prev = ahead+1;
        }
        return max(prev, ahead);
    }
};