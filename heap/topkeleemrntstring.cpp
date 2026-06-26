class Solution {
public:
struct cmp{
    bool operator()(pair<string,int>&a,pair<string,int>&b){
        if(a.second!=b.second){
            return a.second>b.second;
        }
        return a.first<b.first;
    }
};
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();
        unordered_map<string,int> freq;

        for(int i = 0; i < n; i++){
            freq[words[i]]++;
        }
priority_queue<pair<string,int>,
               vector<pair<string,int>>,
               cmp> pq;

        for(auto it : freq){
      pq.push({it.first,it.second});
      if(pq.size()>k){
        pq.pop();
      }

}
vector<string> ans;
while(!pq.empty()){
        ans.push_back(pq.top().first);
        pq.pop();

}
reverse(ans.begin(), ans.end());
        return ans;
    }
};