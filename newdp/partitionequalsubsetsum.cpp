class Solution {
public:
   int perfectSum(vector<int>& arr, int target) {
                
                int n=arr.size();
                
                vector<vector<int>>dp(n+1,vector<int>(target+1,0));
                
                
                for(int i=0;i<target;i++){
                    dp[n][i]=0;
                }
                
                dp[n][0]=1;
                
                for(int i=n-1;i>=0;i--){
                    for(int j=0;j<=target;j++){
                        if(arr[i]>j){
                            dp[i][j]=dp[i+1][j];
                        }
                        else{
                        dp[i][j]=dp[i+1][j-arr[i]]|dp[i+1][j];
                        }
                    }
                    
                }
        
        return dp[0][target];
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
         if(sum%2==1) return false;

       return   perfectSum(nums,sum/2);



    }
};