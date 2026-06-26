class Solution {
public:
    bool cycle = false;

    void dfs(vector<vector<int>>& adj, int node,
             vector<bool>& vis, vector<int>& path) {

        vis[node] = true;
        path[node] = 1;

        for (int neigh : adj[node]) {

            if (vis[neigh] && path[neigh]) {
                cycle = true;
                return;
            }

            if (!vis[neigh]) {
                dfs(adj, neigh, vis, path);
            }
        }

        path[node] = 0;
    }

    bool isCyclic(int V, vector<vector<int>> &edges) {

        vector<vector<int>> adj(V);

        for (int i = 0; i < edges.size(); i++) {

            int src = edges[i][0];
            int des = edges[i][1];

            adj[src].push_back(des);
        }

        vector<bool> vis(V, false);
        vector<int> path(V, 0);

        for (int i = 0; i < V; i++) {

            if (!vis[i]) {
                dfs(adj, i, vis, path);
            }
        }

        return cycle;
    }
};