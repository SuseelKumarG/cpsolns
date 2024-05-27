#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[3];
        // int max=-1;
        int fav=0,enm=0;
        while(n--)
        {
            for(int i=0;i<3;i++)
            cin>>arr[i];
            if(arr[0]==1 || arr[1]==arr[2])
            {
                cout<<"YES\n";
                fav=arr[1];
                enm=arr[2];
                // continue;
            }
            else if(fav==enm)
            {
                cout<<"NO\n";
            }
            else
            {
                if(fav>enm)
                {
                    int minm=min(arr[1],arr[2]);
                    if(fav>minm)
                    {
                        cout<<"YES\n";
                        fav=max(arr[1],arr[2]);
                        enm=minm;
                    }
                    else
                    cout<<"NO\n";
                }
                else
                {
                    int minm=min(arr[1],arr[2]);
                    if(enm>minm)
                    {
                        cout<<"YES\n";
                        enm=max(arr[1],arr[2]);
                        fav=minm;
                    }
                    else
                    cout<<"NO\n";
                }
            }
        }
    }
}
