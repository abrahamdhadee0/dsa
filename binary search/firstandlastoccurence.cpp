class Solution {
  public:
    int countFreq(vector<int>& arr, int target) {
        // code here
        
      int low =0;
      int high=arr.size()-1;
      int last=-1;
      int first=-1;
      while(low<=high){
          int mid=(low+high)/2;
          
          if(arr[mid]>target)high=mid-1;
          else if(arr[mid]<target)low=mid+1;
          else{
              first=mid;
              high=mid-1;
          }
      }
      if (first == -1) return 0;
            low =0;
       high=arr.size()-1;
      int count2=0;
      while(low<=high){
          int mid=(low+high)/2;
          
          if(arr[mid]>target)high=mid-1;
          else if(arr[mid]<target)low=mid+1;
          else{
              last=mid;
              low=mid+1;
          }
          
         
          
      }
       return  last - first + 1;
    }
};
