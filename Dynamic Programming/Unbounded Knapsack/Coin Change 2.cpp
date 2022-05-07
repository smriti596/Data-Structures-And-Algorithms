//You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

//Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

//You may assume that you have an infinite number of each kind of coin.

class Solution {
public:
    int coinChange(vector<int>& coins, int m) {
       int n=coins.size();
       int dp[n+1][m+1];
        
       for(int i=0;i<n+1;i++)
       {
           for(int j=0;j<m+1;j++)
           {
               if(j==0)
                   dp[i][j]=0;
               if(i==0)
                   dp[i][j]=INT_MAX-1;
           }
       }
       for(int i=1;i<m+1;i++)
       {
            if(i%coins[0]==0)
                dp[1][i] = i/coins[0];
            else
                dp[1][i]=INT_MAX-1;
       }
        for(int i=2;i<n+1;i++)
        {
            for(int j=0;j<m+1;j++)
            {
                if(coins[i-1]<=j)
                    dp[i][j]=min(dp[i-1][j],dp[i][j-coins[i-1]]+1);
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        if (dp[n][m]==INT_MAX-1)
            return -1;
        else
            return dp[n][m];
    }
};
