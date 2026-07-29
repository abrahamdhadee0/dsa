class Solution {
public:
int fun(unordered_map<char,int>&t,unordered_map<char,int>&st){
    int res=INT_MAX;
            for(auto it:st){
                char c=it.first;
                int need=it.second;
                int have=t[c];
                int times=have/need;
                res=min(res,times);
            }
return res;
}
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> t;
        for(int i=0;i<text.size();i++){
            t[text[i]]++;
        }
        string s="balloon";
        unordered_map<char,int> st;
        for(int i=0;i<7;i++){
            st[s[i]]++;
        }
        int n=fun(t,st);
        return n;
    }
};