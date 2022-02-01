class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        //Initialization
        int sz=nums.size();
        int count1=0, count2=0;
        int num1=-1, num2=-1;
        int i;
        
        //Extended Moore Voting Algorithm
        for(i=0; i<sz; i++)
        {
            if(nums[i]==num1) count1++;
            else if(nums[i]==num2) count2++;
            else if(count1==0)
            {
                num1=nums[i];
                count1=1;
            }
            else if(count2==0)
            {
                num2=nums[i];
                count2=1;
            }
            else
            {
                count1--;
                count2--;
            }
        }
        
        //Final check for num1 and num2
        vector<int> ans;
        count1=0, count2=0;
        for(i=0; i<sz; i++)
        {
            if(nums[i]==num1) count1++;
            if(nums[i]==num2) count2++;
        }
        
        if(count1>sz/3 && num1!=num2) ans.push_back(num1);
        if(count2>sz/3 && num1!=num2) ans.push_back(num2);
        if(count1>sz/3 && num1==num2) ans.push_back(num1);
            
        return ans;
    }
};
