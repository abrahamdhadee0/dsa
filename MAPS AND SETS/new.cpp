#include<bits/stdc++.h>
using namespace std;
int main(){
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    for(auto x:s){
        cout<<x<<" ";
    }
    map<int,int> m;
    m[1]=10;
    m[2]=20;
    m[3]=30;
    for(auto x:m){
        cout<<x.first<<" "<<x.second<<endl;
    }
    
}