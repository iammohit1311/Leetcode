class Solution {
    bool solve(int i,vector<int> &sides,vector<int> &matchsticks)
    {
        if(i==matchsticks.size()) return (sides[0]==0 && sides[1]==0 && sides[2]==0 && sides[3]==0 );
        
        for(int j=0;j<4;j++)
        {
            if(matchsticks[i]>sides[j]) continue;
            sides[j]-=matchsticks[i];
            if( solve(i+1,sides,matchsticks)) return 1;
            sides[j] += matchsticks[i];
        }
        return false;
    }
public:
    bool makesquare(vector<int>& matchsticks) {
        int sum=0;
        sort(matchsticks.begin(),matchsticks.end(),greater<int>());
        for(auto i:matchsticks) sum+=i;
        int find=sum/4;
        if(sum%4!=0 || matchsticks.size()<4) return false;
        vector<int>sides(4,find);
        return solve(0,sides,matchsticks);
    }
};