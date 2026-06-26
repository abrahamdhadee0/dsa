#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    bool validate(int m, int n, int i, int j) {
        return (i >= 0 && i < m && j >= 0 && j < n);
    }

    void dfs(vector<vector<char>>& grid, int i, int j, vector<vector<bool>>& visited) {
        visited[i][j] = true;

        for (int k = 0; k < 4; k++) {
            int newRow = i + dx[k];
            int newCol = j + dy[k];

            if (validate(grid.size(), grid[0].size(), newRow, newCol) &&
                !visited[newRow][newCol] &&
                grid[newRow][newCol] == '1') {

                dfs(grid, newRow, newCol, visited);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int res = 0;
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    dfs(grid, i, j, visited);
                    res++;
                }
            }
        }
        return res;
    }
};