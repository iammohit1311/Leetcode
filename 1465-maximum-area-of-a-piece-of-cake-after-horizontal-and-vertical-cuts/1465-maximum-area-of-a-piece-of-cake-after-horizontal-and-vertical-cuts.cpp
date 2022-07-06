class Solution {
public:
    const long long int mod = 1000000007;
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        // Sort
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        
        // Horizontal
        vector<int> heights = {horizontalCuts[0]};
        int nh = horizontalCuts.size();
        for (int i=1; i<nh; i++) {
            heights.push_back(horizontalCuts[i]-horizontalCuts[i-1]);
        }
        heights.push_back(h-horizontalCuts[nh-1]);
        
        // Vertical
        vector<int> lengths = {verticalCuts[0]};
        int nv = verticalCuts.size();
        for (int i=1; i<nv; i++) {
            lengths.push_back(verticalCuts[i]-verticalCuts[i-1]);
        }
        lengths.push_back(w-verticalCuts[nv-1]);
        
        // Take max
        long long int a = *max_element(heights.begin(), heights.end());
        long long int b = *max_element(lengths.begin(), lengths.end());
        
        // Multiply and return
        return (int)(a%mod*b%mod);
    }
};