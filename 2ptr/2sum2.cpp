class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v1(2);
     int n=nums.size();
     int i=0;
     int j=n-1;
     sort(nums.begin(),nums.end());
        while(i<j){
            int sum=nums[i]+nums[j];
            if(sum==target){
            return {i+1,j+1};//one indexed array
            }
            else if(sum>target){
j--;
            }
            else{
                i++;
            }
        }
return v1;
    }
};