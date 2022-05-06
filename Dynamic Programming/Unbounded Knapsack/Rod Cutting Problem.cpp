//Given a rod of length ‘N’ units. The rod can be cut into different sizes and each size has a cost associated with it. Determine the maximum cost obtained by cutting the rod and selling its pieces.
//Solution 1) Using Bottom Up DP
int cutRod(vector<int> &price, int n)
{
	// since length array is not given therefore let us make one
    int length_cap[n];
    for(int i=1;i<=n;i++)
       length_cap[i-1]=i;
    
    // Here W->n , val[]->price[] , wt[]=>length[]
	
	// Now unbounded Knapsack as usual no changes
    int dp[n+1][n+1];
      for(int i=0;i<=n;i++)
        dp[i][0] = 0;
    
      for(int j=0;j<=n;j++)
        dp[0][j] = 0;
    
       for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(length_cap[i-1] <= j){    
              dp[i][j] = max(price[i-1] + dp[i][j-length_cap[i-1]], 
                             dp[i-1][j]);
            }
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][n];
}
