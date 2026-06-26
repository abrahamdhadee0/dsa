class Solution {
  public:
  bool help(vector<int>& v1,int n,int mid,int k){
      int pagesstudent=0;
     int  student=1;
      for(int i=0;i<n;i++){
          if(v1[i]>mid) return false;
          if(pagesstudent+v1[i]<=mid){
              pagesstudent+=v1[i];
          }
          else{
              student++;
              pagesstudent=v1[i];
          }
          
      }
      return  student<=k; //why is this is less and equal
      }
    int findPages(vector<int> &arr, int k) {
        int n=arr.size();
        if(k>arr.size()) return -1;
        int low=*max_element(arr.begin(),arr.end());
        int high=accumulate(arr.begin(),arr.end(),0);
        while(low<=high){
           int mid = low + (high - low) / 2;
            
            if(help(arr,n,mid,k)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};