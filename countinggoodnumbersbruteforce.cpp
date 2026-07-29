class Solution {
public:
int rev(int n){
    int r=0;
    while(n>0){
        r*=10;
        r+=(n%10);
        n/=10;
    }  
    return r;
}
    int countNicePairs(vector<int>& nums) {
        int count=0;
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
              if(nums[i]+rev(nums[j])==nums[j]+rev(nums[i])){
              count++;  
            }
        }
     
    }
       return count;
    }
};
// This is a brute force solution that checks all pairs of numbers in the input vector `nums` to see if they form a "nice pair". A "nice pair" is defined as two numbers `nums[i]` and `nums[j]` such that `nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])`, where `rev(n)` is a function that returns the reverse of the integer `n`. The function iterates through all pairs of indices `(i, j)` where `i < j`, and increments the count of nice pairs whenever the condition is satisfied. Finally, it returns the total count of nice pairs found.
// Note: This brute force approach has a time complexity of O(n^2) due to the nested loops, which may not be efficient for large input sizes.
// The `rev` function computes the reverse of an integer by repeatedly extracting the last digit and building the reversed number. The main function `countNicePairs` uses this helper function to check each pair of numbers in the input vector.
// The code is straightforward and easy to understand, but it may not be the most efficient solution for large datasets.
// The code uses the C++17 language standard, as specified in the project settings.
