#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    auto low=arr.begin();
    auto curr=arr.begin();
    auto high=--(arr.end());
    while(high>=curr)
    {
        if(*curr==0)
        {
            swap(*curr,*low);
            curr++;
            low++;
        }
        else if(*curr==2)
        {
            swap(*curr,*high);
            high--;
        }
        else
        curr++;
    }
    for(auto it:arr)
    cout<<it<<' ';
    cout<<'\n';
}