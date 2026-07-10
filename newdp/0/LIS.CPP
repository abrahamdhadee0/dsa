class Solution {
public:
int find(vector<int>& v1,int n,int i ,int prev,vector<vector<int>>&dp){
        if(i==n) return 0;
        if(dp[i][prev+1]!=-1) return dp[i][prev+1];
    
    if(prev==-1||v1[i]>v1[prev]){
            int c1=1+find(v1,n,i+1,i,dp);
            int c2=find(v1,n,i+1,prev,dp);

            return dp[i][prev+1]=max(c1,c2);
    }
    return dp[i][prev+1]=find(v1,n,i+1,prev,dp);
}
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
int i=0;
int prev=-1;
       return find(nums,n,i,prev,dp);
    }
};