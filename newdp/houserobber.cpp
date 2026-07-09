class Solution {
public:

    int find(vector<int>& nums,int n,int i,vector<int>&dp){
        if(i>=n) return 0;
        if(dp[i]!=-1)return dp[i];
        int c1= nums[i]+find(nums,n,i+2,dp);
        int c2=find(nums,n,i+1,dp);
        return dp[i]= max(c1,c2);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(100,-1);
      return  find(nums,n,0,dp);
    }
};