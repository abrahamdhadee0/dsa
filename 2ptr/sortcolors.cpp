void swap(int & a,int & b)
{
    int temp=a;
    a=b;
    b=temp;
}

void sort colors(vector<int> & ans){
    int low=0;
    int mid=0;
    int high=ans.size()-1;
    while(mid<=high){

        if(ans[mid]==0){
            swap(ans[low],ans[mid]);
            low++;
            mid++;
        }
        else if(ans[mid]==1){
            mid++;
        }
        else{
            swap(ans[mid],ans[high]);
            high--;
        }


    }
}
// dry run of this code is
// 0 1 2 0 1 2
/*
starting with low=0,mid=0,high=5
1. mid=0, ans[mid]=0, swap(ans[low],ans[mid])
2. mid=1, ans[mid]=1, mid++
3. mid=2, ans[mid]=2, swap(ans[mid],ans[high])
4. mid=2, ans[mid]=0, swap(ans[low],ans[mid])

*/