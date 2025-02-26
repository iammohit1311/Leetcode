class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int sum = 0, minSum = 0, maxSum = 0;
        for(int i=0; i<nums.size(); i++)
        {
            sum += nums[i];
            if(sum > maxSum) maxSum = sum;
            if(sum < minSum) minSum = sum;
        }

        return abs(maxSum - minSum);
    }
};