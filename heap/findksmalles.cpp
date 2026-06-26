class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        int n=arr.size();
        priority_queue<int> pq;
        for(int i=0;i<k;i++){
            pq.push(arr[i]);
        }
            for(int j=k;j<n;j++){
                if(pq.top()<=arr[j]) continue;
                
                pq.pop();
                pq.push(arr[j]);
            
            }
        return pq.top();
    }
    };