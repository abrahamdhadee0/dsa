int find(nums,int a ,int i,int dp){
    if(i>=a) return 0;
    if(dp[i][free]!=-1) return dp[i][free];
    if(free==0){
        return dp[i][free]=find(nums,a,i+1,0,dp);
    }
    int c1= nums[i]+find(nums,a,i+2,0,dp);
    int c2=find(nums,a,i+1,1,dp);
    return dp[i][free]= max(c1,c2);
}
