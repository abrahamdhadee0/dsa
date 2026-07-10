class Solution {
public:

    int find(int w, vector<int> &val, vector<int> &wt, int i, vector<vector<int>> &dp) {
        if (i >= val.size()) return 0;

        if (dp[i][w] != -1) return dp[i][w];

        if (wt[i] > w) {
            return dp[i][w] = find(w, val, wt, i + 1, dp);
        }

        int a = val[i] + find(w - wt[i], val, wt, i + 1, dp);
        int b = find(w, val, wt, i + 1, dp);

        return dp[i][w] = max(a, b);
    }

    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(W + 1, -1));

        return find(W, val, wt, 0, dp);
    }
};