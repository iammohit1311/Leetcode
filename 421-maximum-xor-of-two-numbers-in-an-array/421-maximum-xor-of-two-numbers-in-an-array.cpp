class Trie{
    Trie *child[2];
    int val;
public:
    Trie(){
        child[0] = NULL;
        child[1] = NULL;
        val = 0;
    }
    
    void insert(int num) {
        auto curr = this;
        for(int i = 30; i >= 0; i--) {
            bool bit = (num >> i) & 1;
            if(curr->child[bit]){
                curr = curr->child[bit];
            } else {
                curr->child[bit] = new Trie();
                curr = curr->child[bit];
            }
        }
        curr->val = num;
    }
    
    int findbestmismatch(int num) {
        auto curr = this;
        for(int i = 30; i >= 0; i--) {
            bool bit = (num >> i) & 1;
            if(curr->child[!bit]){
                curr = curr->child[!bit];
            } else {
                curr = curr->child[bit];
            }
        }
        return curr->val;
    }
};


class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie t;
        for(auto &i : nums) {
            t.insert(i);
        }
        
        int ret = INT_MIN;
        for(auto &i : nums) {
            ret = max(ret, i ^ t.findbestmismatch(i));
        }
        return ret;
    }
};