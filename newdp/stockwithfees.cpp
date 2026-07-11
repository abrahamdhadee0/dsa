class Solution {
public:

    int find(vector<int>& prices,int n,int i,int k,vector<vector<int>>&dp,int fee){
            if(i==n||k==0) return 0;
            if(dp[i][k]!=-1) return dp[i][k];
            int c1,c2;
            if(k==2){
                c1=find(prices,n,i+1,k-1,dp,fee)-prices[i];
                c2=find(prices,n,i+1,k,dp,fee);
                return dp[i][k]=max(c1,c2);
            }
            else{
                c1=find(prices,n,i+1,2,dp,fee)+prices[i]-fee;
                c2=find(prices,n,i+1,k,dp,fee);
                return dp[i][k]=max(c1,c2);

            }
return 1;
    }
    int maxProfit(vector<int>& prices,int fee) {
        int n=prices.size();
        int k=2;
        vector<vector<int>>dp(n,vector<int>(k+1,-1));
        return find(prices,n,0,k,dp,fee);
    }
};