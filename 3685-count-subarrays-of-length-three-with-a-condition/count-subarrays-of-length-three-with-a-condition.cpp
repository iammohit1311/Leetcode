class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size();
        if(n<3) return 0;
        int count;

        for(int i=0; (i+2) < n; i++)
            if(nums[i+1] == 2*(nums[i] + nums[i+2])) 
                count++;

        return count;
    }
};