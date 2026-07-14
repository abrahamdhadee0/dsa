class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int res=1;
        int cm=1;
        int officer=1;   // showuldstart from bcz 1st element always uniqye
        while(cm<=nums.size()-1){
                if(nums[cm]==nums[cm-1]){
                        cm++;
                        continue;
                }
                else{
                nums[officer]=nums[cm];
                res++;
                cm++;
                officer++;
                }

        }
        return res;
    }
};