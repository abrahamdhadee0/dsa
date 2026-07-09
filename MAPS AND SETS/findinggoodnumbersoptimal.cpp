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

    int  countNicePairs(vector<int>& nums) {
        int count=0;
        int n=nums.size();
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            nums[i]-=rev(nums[i]);
        }
            for(int i=0;i<n;i++){
                if(m.find(nums[i])!=m.end()){
                    count=count%1000000007;
                    count+=m[nums[i]];
                    m[nums[i]]++;
                }
                else m[nums[i]]++;
            }
        return count%1000000007;
    }
};
// This is an optimized solution that uses a hash map (unordered_map)
// to count the occurrences of the values obtained by 
//subtracting the reverse of each number from itself. The key idea is that if two numbers `
//nums[i]` and `nums[j]` satisfy the condition `nums[i] +
// rev(nums[j]) == nums[j] + rev(nums[i])`, it can be rearranged to
// `nums[i] - rev(nums[i]) == nums[j] - rev(nums[j])`. Therefore, we can compute//
 //this value for each number and count how many times each value occurs using a hash map. //
 //Whenever we encounter a value that has already been seen, we can add the count of//
//  that value to our total count of nice pairs. Finally, //
  //we return the count modulo 10^9 + 7 to handle large numbers.
//