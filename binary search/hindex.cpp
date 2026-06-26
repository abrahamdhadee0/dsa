class Solution {
public:
bool helper(vector<int> v1,int n,int mid){
    int count=0;
    bool flag=false;
    for(int i=0;i<v1.size();i++){
        if(v1[i]-mid>=0){
            count++;
        }
        else{
            continue;
        }
        
    }
    if(count>=mid) flag=true;
        else flag=false;

        return flag;

}
    int hIndex(vector<int>& cit) {

      //  sort(cit.begin(),cit.end());
        int n=cit.size();
        int low=0;
        int high=cit[n-1];
        int res=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(helper(cit,n,mid)){
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