class Solution {
public:
 vector<int> dp = vector<int>(1000, -1);
int find(int i,int n){
    if( i==n) return 1;
    if(i>n) return 0;
    if(dp[i]!=-1) return dp[i];
    int a1=find(i+1,n);
    int a2=find(i+2,n);
    int ans=a1+a2;
    dp[i]=ans;
    return ans;
}
    int climbStairs(int n) {
        return find(0,n);
    }
};