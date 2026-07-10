class Solution {
public:
   int find(int m,int n,int i ,int j,vector<vector<int>>&dp){
    if(i==m-1&&j==n-1) return 1;
    if(i<0||i>=m ||j<0||j>=n){
        return 0;
    }
    if(dp[i][j]!=-1)
    return dp[i][j];

    return dp[i][j]=find(m,n,i+1,j,dp)+find(m,n,i,j+1,dp);
   }

    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        int i=0;
        int j=0;
        return find(m,n,i,j,dp);
        
    }
};