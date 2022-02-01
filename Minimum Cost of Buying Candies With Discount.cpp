class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end(), greater<int>());
        int sum=0;
        
        for(int i=1; i<=cost.size(); i++)
        {
            if(i%3 == 0) continue;
            
            sum = sum + cost[i-1];
        }
        
        return sum;
    }
};
