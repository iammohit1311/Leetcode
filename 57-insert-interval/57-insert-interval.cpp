class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        if(intervals.size() == 1) return intervals;
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> merged;
        vector<int> temp = intervals[0];
        for(auto it : intervals)
        {
            if(it[0] <= temp[1])
            {
                temp[1] = max(temp[1], it[1]);
            }
            else
            {
                merged.push_back(temp);
                temp=it;
            }
        }
        merged.push_back(temp);
        return merged;
    }
};