#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // दिशा (4-direction movement: up, down, right, left)
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    // check if (i, j) is inside grid
    bool valid(int n, int m, int i, int j) {
        return (i >= 0 && i < n && j >= 0 && j < m);
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;   // stores rotten oranges positions
        int fresh = 0;            // count of fresh oranges
        int time = 0;             // minutes passed

        // 🔹 Step 1: Put all rotten oranges in queue and count fresh ones
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});   // already rotten
                }
                else if(grid[i][j] == 1){
                    fresh++;          // count fresh
                }
            }
        }

        // 🔹 Step 2: BFS (multi-source)
        // each level = 1 minute
        while(!q.empty() && fresh > 0){
            int size = q.size(); // number of rotten oranges at current minute
            time++;              // increase time for this level

            while(size--){
                auto p = q.front();
                q.pop();

                int r = p.first;
                int c = p.second;

                // check 4 directions
                for(int k = 0; k < 4; k++){
                    int row = r + dx[k];
                    int col = c + dy[k];

                    // if valid cell and fresh orange found
                    if(valid(n, m, row, col) && grid[row][col] == 1){
                        grid[row][col] = 2;     // make it rotten
                        q.push({row, col});     // add to queue for next minute
                        fresh--;                // decrease fresh count
                    }
                }
            }
        }

        // 🔹 Step 3: if still fresh oranges remain → impossible
        return (fresh > 0) ? -1 : time;
    }
};