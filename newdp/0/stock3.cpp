class Solution {
public:
                int find(vector<int>&prices,int n,int k,int i,vector<vector<int>>&dp){
                    if(i==n||k==0) return 0;

                        if(dp[i][k]!=-1) return dp[i][k];
            int c1,c2;
                        if(k%2==0){
                        c1=find(prices,n,k-1,i+1,dp)-prices[i];
                         c2=find(prices,n,k,i+1,dp);
                         return dp[i][k]=max(c1,c2);
                        }
                        else{
                                 c1=find(prices,n,k-1,i+1,dp)+prices[i];
                                c2=find(prices,n,k,i+1,dp);
                         return dp[i][k]=max(c1,c2);
                                                }
return 1;
                }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int k=4;
        vector<vector<int>>dp(n,vector<int>(2*k+1,-1));
        return find(prices,n,k,0,dp);
    }
};