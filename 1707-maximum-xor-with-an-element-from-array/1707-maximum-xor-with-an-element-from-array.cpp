class Solution {
public:
    struct Trie {
        vector<Trie*> nodes;
        Trie(): nodes(2) {}
        static void insert(Trie* root, int num){
            for (int i = 31; i >= 0; i--){
                int ind = (num >> i)&1;
                if (! (root -> nodes[ind]) )
                    root -> nodes[ind] = new Trie();
                root = root -> nodes[ind];
            }
        }
        
        static int query(Trie* root, int num){
            if (!root -> nodes[0] && !root -> nodes[1])
                return -1; 
            int ans = 0;
            for (int i = 31; i >= 0; i--){
                int ind = (num >> i) & 1;
                
                if (root -> nodes[1 - ind]){
                    root = root -> nodes[1 - ind]; 
                    ans |= (1 << i); 
                }else{
                    root = root -> nodes[ind];
                }
            }
            return ans; 
        }
    };
    
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int q = queries.size(); 
        vector<int> ans(q);
        vector<array<int, 3>> qry;
        sort(nums.begin(), nums.end()); 
        
        for (int i = 0; i < q; i++){
            qry.push_back({queries[i][1], queries[i][0], i}); 
        }
        sort(qry.begin(), qry.end());
        
        Trie* trie = new Trie();
        
        int j = 0; 
        for (int i = 0; i < q; i++){
            while (j < nums.size() && nums[j] <= qry[i][0]){
                trie -> insert(trie, nums[j]); 
                j++;
            }
            ans[qry[i][2]] = trie -> query(trie, qry[i][1]); 
        }
        return ans; 
    }
};