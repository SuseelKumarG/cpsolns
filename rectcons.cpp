#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        vector<int>arr(3);
        for(int i=0;i<3;i++)
        cin>>arr[i];
        sort(arr.begin(),arr.end());
        int sum=arr[0]+arr[1];
        if(sum == arr[2] || ((arr[0]==arr[1] && !(arr[2] & 1)) || (arr[1]==arr[2] && !(arr[0] & 1)) ))
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
}