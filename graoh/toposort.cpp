class Solution {
  public:
    vector<int> topoSort(int n, vector<vector<int>>& edges) {
        vector<vector<int>> a(n);
        vector<int> indeg(n,0);
        for(int i=0;i<edges.size();i++){
            int src=edges[i][0];
            int des=edges[i][1];
            a[src].push_back(des);
            indeg[des]++;
        }
        queue<int> q;
                    vector<int> res;

        for(int i=0;i<n;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }
            while(!q.empty()){
                int node=q.front();
                q.pop();
                res.push_back(node);
                for(int i=0;i<a[node].size();i++){
                    int neigh=a[node][i];
                    indeg[neigh]--;
                    if(indeg[neigh]==0){
                        q.push(neigh);
                    }
                }
            }
        
        return res;
}
};