class Solution {
  public:
    int countTriplets(int sum, vector<int>& arr) {
     int ans=0;
     int n=arr.size();
     sort(arr.begin(),arr.end());
     for(int i=0;i<n-2;i++){
         int left=i+1;
         int right=arr.size()-1;
         
         while(left<right){
             
             int sumu=arr[left]+arr[right]+arr[i];
             
             if(sumu>=sum){
                 right--;
                 
             }
             else{
                ans=ans+(right-left);
                 left++;
             }
             
             
             
             
         }
         
        
         
         
         
         
         
     }
     return ans;
        
    }
};