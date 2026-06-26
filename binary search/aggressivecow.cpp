class Solution {
  public:
  bool help(vector<int> v1,int n,int k,int mid){
      int cow=1;
     int pre=v1[0];
      bool flag=true;
      for(int i=0;i<n;i++){
        int  dist=v1[i]-pre;
          if(dist<mid){
              continue;
          }
          else{
              cow++;
              pre=v1[i];
          }
      }
      if(cow>=k) flag=true;
      else flag= false;
      
      return flag;
  }
    int aggressiveCows(vector<int> &stalls, int k) {
    int n=stalls.size();
    sort(stalls.begin(),stalls.end());
    int low=1;
    int high=stalls[n-1]-stalls[0];
    int res=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(help(stalls,n,k,mid)){
            res=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
        return res;
    }
};