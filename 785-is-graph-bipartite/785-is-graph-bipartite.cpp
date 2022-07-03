class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> color(n);     
    queue<int> q;    
	
    for (int i = 0; i < n; i++) {
      if (color[i]) continue; // skip already colored nodes
      
      color[i] = 1;  
      for (q.push(i); !q.empty(); q.pop()) {
        int cur = q.front();
        for (auto neighbor : graph[cur]) 
		{
          if (!color[neighbor]) // if uncolored, color with opposite color
          { color[neighbor] = -color[cur]; q.push(neighbor); } 
		  
          else if (color[neighbor] == color[cur]) 
            return false; // if already colored with same color, can't be bipartite!
        }        
      }
    }
    
    return true;
    }
};