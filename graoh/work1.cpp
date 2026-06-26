class Solution {
public:
    
    bool dfs(vector<vector<int>>& adj, int node,
             vector<bool>& vis, vector<int>& path) {
        
        vis[node] = 1;
        path[node] = 1;

        for (int i = 0; i < adj[node].size(); i++) {
            int neigh = adj[node][i];

            // cycle found
            if (vis[neigh] && path[neigh]) {
                return false;
            }

            // visit unvisited node
            if (!vis[neigh]) {
                if (!dfs(adj, neigh, vis, path)) {
                    return false;
                }
            }
        }

        // remove from current dfs path
        path[node] = 0;

        return true;
    }

    bool canFinish(int n, vector<vector<int>>& p) {

        vector<vector<int>> adj(n);

        // build adjacency list
        for (int i = 0; i < p.size(); i++) {
            int src = p[i][0];
            int des = p[i][1];

            adj[src].push_back(des);
        }

        vector<bool> vis(n, 0);
        vector<int> path(n, 0);

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                if (!dfs(adj, i, vis, path)) {
                    return false;
                }
            }
        }

        return true;
    }
};