class Solution {
public:
int find(vector<int>& nums,int sum){
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(sum+1,0));

        dp[n][0]=1;
for(int i=n-1;i>=0;i--){
    for(int j=0;j<=sum;j++){
        if(nums[i]>j){
            dp[i][j]=dp[i+1][j];
        }else{
         dp[i][j]=dp[i+1][j]+dp[i+1][j-nums[i]];
        }
    }


}
return dp[0][sum];
}

    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
          sum+=nums[i];
        }
        if(sum<abs(target)) return 0;
        int final=(target+sum)/2;
        if(final%2!=1) return 0;

            return find(nums,final);

    }
};
// The fix
// Check divisibility before you divide, on the sum itself:
// cppif ((sum + target) % 2 != 0) return 0;   // check first
// int final = (sum + target) / 2;          // then safely divide
// This checks the thing that actually determines validity (is sum+target even?) before the truncating division destroys that information — rather than checking an unrelated property (is the truncated result odd?) afterward.