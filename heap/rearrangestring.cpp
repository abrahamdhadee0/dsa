class Solution {
public:

    struct cmp{
        bool operator()(pair<char,int>&a,pair<char,int>&b){
            return a.second < b.second;
        }
    };

    string reorganizeString(string s) {

        priority_queue<pair<char,int>, vector<pair<char,int>>, cmp> pq;

        unordered_map<char,int> freq;

        for(int i=0;i<s.size();i++){
            freq[s[i]]++;
        }

        for(auto &it:freq){
            pq.push({it.first,it.second});
        }

        string res="";

        while(!pq.empty()){

            pair<char,int> p=pq.top();
            pq.pop();

            int size=res.size();

            if(size==0 || res[size-1]!=p.first){

                res.push_back(p.first);
                p.second--;

                if(p.second>0){
                    pq.push(p);
                }
            }

            else{

                if(pq.empty()) return "";

                pair<char,int> p2=pq.top();
                pq.pop();

                res.push_back(p2.first);
                p2.second--;

                if(p2.second>0){
                    pq.push(p2);
                }

                pq.push(p);
            }
        }

        return res;
    }
};