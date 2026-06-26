class Solution {
public:
bool help(vector<int> & v1,int n,long long mid,long long  k){
        long long piles=0;
    for(int i=0;i<n;i++){
        if(v1[i]>=mid){
            piles+=v1[i]/mid;
        }

    }
    return piles>=k;
}
    int maximumCandies(vector<int>& c, long long k) {
        int n=c.size();
        int sum=*max_element(c.begin(),c.end());
        long long sumu=accumulate(c.begin(),c.end(),0LL);
        long long low=1;
        long long high=sum;
        long long res=0;
        if(sumu<k) return 0;
        while(low<=high){
            long long mid=(low+high)/2;
            if(help(c,n,mid,k)){
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