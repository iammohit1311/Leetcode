class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int dp[n + 1][m + 1]; // DP - matrix

  // base condition 
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			if (i == 0 || j == 0)
				dp[i][j] = 0; //

  // choice diagram 
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (nums1[i - 1] == nums2[j - 1]) // when both string's last char is same
				dp[i][j] = 1 + dp[i - 1][j - 1]; // count the number and decrement the table 
			else
				dp[i][j] = 0; // variation from LCS(DP)

	int mx = INT_MIN;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			mx = max(mx, dp[i][j]);

	return mx;
    }
};