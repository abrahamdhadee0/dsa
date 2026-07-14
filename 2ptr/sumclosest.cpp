class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());

        int n = nums.size();
        int ans = 0;
        int diff =INT_MAX;

        for(int i = 0; i < n - 2; i++) {

            int left = i + 1;
            int right = n - 1;

            while(left < right) {

                int s = nums[i] + nums[left] + nums[right];

                if(abs(s - target) < diff) {
                    diff = abs(s - target);
                    ans = s;
                }

                if(s == target)
                    return s;
                else if(s > target)
                    right--;
                else
                    left++;
            }
        }

        return ans;
    }
};