class Solution {
public:
 vector<int> t = vector<int>(100, -1);
int climb(int n){
    if(t[n]!=-1)return t[n];
    if(n<=3){
     t[n]= n;
    }
    else {
        t[n]= climb(n-1)+climb(n-2);
    }
    return t[n];
    }
    int climbStairs(int n) {
        int h=climb(n);
        return h;
    }
};


int main(){
    vector<int> dp(n,-1);
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}