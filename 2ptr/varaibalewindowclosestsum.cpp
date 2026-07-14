class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        int high=0;
        int low=0;
        int res=INT_MIN;
        unordered_map<char, int> mp;


for(int i=high;i<s.size();i++){
     mp[s[high]]++;
            
        while(mp.size()>k){
            mp[s[low]]--;
            if(mp[s[low]]==0) mp.erase(s[low]);
            low++;
        }
        if(mp.size()==k)
        {
            
            
            int len=high-low+1;
            res=max(len,res);
    
    }
    high++;
}
    if(res==INT_MIN) return -1;
    
    return res;
    }
};