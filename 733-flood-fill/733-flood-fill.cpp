class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color) return image;
        dfsFill(image, sr, sc, image[sr][sc], color);
        return image;
    }
    
    void dfsFill(vector<vector<int>>& image, int sr, int sc, int oldColor, int color){
        if(sr < 0 || sr >= image.size() 
           || sc < 0 || sc >= image[0].size() 
           || image[sr][sc] != oldColor) return;
        
        image[sr][sc] = color;
        dfsFill(image, sr+1, sc, oldColor, color);
        dfsFill(image, sr-1, sc, oldColor, color);
        dfsFill(image, sr, sc+1, oldColor, color);
        dfsFill(image, sr, sc-1, oldColor, color);
    }
};