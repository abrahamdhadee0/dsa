class Solution {
public:
    bool cycle = false;

    void dfs(vector<vector<int>>& adj, int node, int parent, vector<bool>& vis) {
        vis[node] = true;

        for (int neigh : adj[node]) {

            // if already visited and not parent => cycle
            if (vis[neigh] && neigh != parent) {
                cycle = true;
                return;
            }

            // if not visited
            if (!vis[neigh]) {
                dfs(adj, neigh, node, vis);
            }
        }
    }

    bool isCycle(int V, vector<vector<int>>& edges) {

        vector<vector<int>> adj(V);

        // create adjacency list
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> vis(V, false);

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(adj, i, -1, vis);
            }
        }

        return cycle;
    }
};