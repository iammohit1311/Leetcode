class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hashset;
        
        for(int num:nums) hashset.insert(num);
        
        int longestStreak=0;
        
        for(int num:nums)
        {
            if(!hashset.count(num-1))
            {
                int currNum=num;
                int currStreak=1;
                
                while(hashset.count(currNum+1))
                {
                    currNum += 1;
                    currStreak++;
                }
                
                longestStreak=max(longestStreak, currStreak);
            }
        }
        return longestStreak;
    }
};