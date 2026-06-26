class Solution {
public:
long long helper(vector<int> v1,int n,int speed){
long long h=0;
for(int i=0;i<v1.size();i++){
    h+=(v1[i]/speed);
    if(v1[i]%speed!=0){
        h++;
    }
    
}
return h;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int n=piles.size();
        int high=*max_element(piles.begin(),piles.end());
        int res=high;
        while(low<=high){
             int mid = low + (high - low) / 2;
             long long hour=helper(piles,n,mid);
             if(hour>h){
                        low=mid+1;
             }
             else{
                res=mid;
                high=mid-1;

             }

        }
        return res;
    }
};