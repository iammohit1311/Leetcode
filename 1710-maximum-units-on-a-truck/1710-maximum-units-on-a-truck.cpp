class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), 
             [](auto &a, auto &b) { return a[1]>b[1]; });
        
        int sum = 0;
        for(auto box : boxTypes)
        {
            
            if(truckSize == 0) break;
            int mini = min(truckSize, box[0]);
            sum += mini*box[1];
            truckSize = truckSize - mini;
    
        }
        return sum;
    }
};