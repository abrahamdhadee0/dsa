class Solution {
public:
vector<int> squared(vector<int>&v1){
    for(int i=0;i<v1.size();i++){
        v1[i]=v1[i]*v1[i];
    }
    
return v1;
}
vector<int> merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0;
        int j=0;
        int id=0;
        vector<int> res(m+n);
        while(i<m&&j<n){
            if(nums1[i]<nums2[j]){
                res[id]=nums1[i];
                i++;
                id++;
            }
            else{
            res[id]=nums2[j];
            j++;
            id++;
            }
        }

        while(i<m){
           res[id] = nums1[i];
id++;
i++;
        }
     while(j<n){
            res[id] = nums2[j];
id++;
j++;
        }
      return res;
}
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> pos;
        vector<int> neg;

        for(int i=0;i<nums.size();i++){
                if(nums[i]<0){
                    neg.push_back(nums[i]);
                }
                else{
                    pos.push_back(nums[i]);
                }
        }
            if(neg.size()==0){
                return squared(pos);
            }
            if(pos.size()==0){
                reverse(neg.begin(),neg.end());
                return squared(neg);
            }
            
             squared(pos);
             squared(neg);
             reverse(neg.begin(),neg.end());
    int n=neg.size();
    int m=pos.size();
            return merge(neg,n,pos,m);
        }
};