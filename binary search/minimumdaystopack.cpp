class Solution {
public:
bool helper(vector<int> v1,int days,int n,int mid){
    int sum=0;
    int used=1;
    for(int i=0;i<n;i++){
        if(v1[i]>mid) return false;
        
        if(v1[i]+sum<=mid){
            sum+=v1[i];
        }
        else {
            used++;
            sum=v1[i];
        }
    }
    return used<=days;
}
    int shipWithinDays(vector<int>& w, int days) {
        int n = w.size();
        int low = 1;
        int high = accumulate(w.begin(), w.end(), 0);
        int res = -1;
        while(low<=high){
            int mid=(low+high)/2;

            if(helper(w,days,n,mid)){
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