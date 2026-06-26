// User function template for C++

class Solution {
  public:
  int bs(vector<int>& res,int low,int high,int x){
      while(low<=high){
        int  mid=(low+high)/2;
          if(res[mid]==x) return mid;
         else if(res[mid]>x)high=mid-1;
          else low=mid+1;
      }
  }
    string isKSortedArray(int arr[], int n, int k) {
    vector<int> nums;
    for(int i=0;i<n;i++){
        nums.push_back(arr[i]);
    }
    sort(nums.begin(),nums.end());
    for(int i=0;i<n;i++){
       int j=bs(nums,0,n-1,arr[i]);
        
        if(k<abs(i-j)){
            return "No";
        }
        
        

    }
            return "Yes";
    
   
}
};