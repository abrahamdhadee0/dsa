class Solution {
public:
int dist(vector<int> points){
    return (points[0]*points[0])+(points[1]*points[1]);
}
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
       //  int n=points.size();
           priority_queue<pair<int, vector<int>>> pq;
           for(auto &it:points){
            int d=dist(it);
            pq.push({d,it});
            if(pq.size()>k){
                pq.pop();
            }
           }
            vector<vector<int>> ans;
           while(!pq.empty()){
ans.push_back(pq.top().second);
pq.pop();
           }
     return ans;
    }
};