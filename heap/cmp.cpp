struct cmp{
    bool operator()(pair<int,string>&a,pair<int,string>&b){
        if(a.first!=b.first) return a.first>b.first;
        return a.second<b.second;
        // if(a.first!=b.first) return a.first<b.first;
        // return a.second>b.second;
    }
}
//first is frequency and second is word
// for top k frequent words
// for top k least frequent words
// for top k longest words
// for top k shortest words
// for top k largest numbers
// for top k smallest numbers
// for top k highest salary
//first is min heap and second is max heap
//