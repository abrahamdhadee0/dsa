class Solution {
public:
int minimum(int a ,int b){
    if(a<b) return a;
    return b;
}
    int minSubArrayLen(int target, vector<int>& nums) {
      //  int min=INT_MAX;
        int low=0;
        int high=0;
        int sum=0;
        int res=INT_MAX;
        while(high<nums.size()){
                sum+=nums[high];
                while(sum>=target){
                    int len=high-low+1;
                    res=minimum(res,len);
                    sum-=nums[low];
                    low++;
                }
                high++;
        }
        if(res==INT_MAX) return 0;
        return res;
    }
};