class Solution {
  public:
    vector<int> mergeArrays(vector<vector<int>> &mat) {
        int n=mat.size();
        int m=mat[0].size();
         priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                pq.push(mat[i][j]);
            }
        }
         vector<int> res;
         while(!pq.empty()){
             res.push_back(pq.top());
             pq.pop();
             
         }
         return res;
        
    }
};