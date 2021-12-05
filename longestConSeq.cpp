class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        
        set<long long int> hashset;
        for(long long int num : nums) { hashset.insert(num); }
        
        long long int longestStreak = 0;
        
        for(long long int num : nums)
        {
            if(!hashset.count(num-1))
            {
                long long int currentNum = num;
                long long int currentStreak = 1;
                
                while(hashset.count(currentNum+1))
                {
                    currentNum += 1;
                    currentStreak +=1;
                }
                
                longestStreak = max(longestStreak, currentStreak);
            }
        }
        
        return longestStreak;
    }
};
