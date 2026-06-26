class Solution {
public:
  int t[1001][1002];
  
    int kp(int W, vector<int> &val, vector<int> &wt, int n) {

        if (n == 0 || W == 0) {
            return 0;
        }
        if(t[n][W]!=-1){
            return t[n][W];
        }

        if (wt[n - 1] > W) {
            return t[n][W]=kp(W, val, wt, n - 1);
        }

        return  t[n][W]=max(
            val[n - 1] + kp(W - wt[n - 1], val, wt, n - 1),
            kp(W, val, wt, n - 1)
        );
    }

    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        memset(t, -1, sizeof(t));
        int n = wt.size();
 
 
 
 
        return kp(W, val, wt, n);
    }
};