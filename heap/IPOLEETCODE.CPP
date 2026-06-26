class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n=profits.size();
      vector<pair<int,int>> p1;
       for(int i=0;i<n;i++){
        p1.push_back({capital[i],profits[i]});
       }
        sort(p1.begin(),p1.end());
        priority_queue<int> pq;
        int idx=0;
        while(k--){
        
        while(idx<n){
            if(p1[idx].first>w){
                break;
            }
            else{
               pq.push(p1[idx].second);
               idx++;
            }
        }
        if(pq.empty())
            return w;
            w=w+pq.top();
            pq.pop();
        }
return w;
    }
};