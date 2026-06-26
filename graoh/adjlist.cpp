#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,e;
    cin>>n>>e;
    vector<vector<int>> adj(n);
    vector<vector<int>> edges;
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        edges.push_back({u,v});
}
for(int i=0;i<edges.size();i++){
    int src =edges[i][0];
    int dest =edges[i][1];
    adj[src].push_back(dest);
    adj[dest].push_back(src); // undirected graph
}
}