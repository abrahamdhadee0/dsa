//same as book allocation problem
class Solution {
public:
bool helper(vector<int>& v1,int k,int mid){
int sum=0;
 int kx=1;
for(int i=0;i<v1.size();i++){
  if(sum+v1[i]<=mid){
   sum+=v1[i];
  }
  else{
    sum=v1[i];
    kx++;
  }
    
}
return kx<=k;
}

    int splitArray(vector<int>& v, int k) {
        int n=v.size();
        int low=*max_element(v.begin(),v.end());
        int high=accumulate(v.begin(),v.end(),0);
        int res=high;
        while(low<=high){
            int mid= low + (high - low) / 2;

            
            if(helper(v,k,mid)){
               res=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return res;
    }
};