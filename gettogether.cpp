#include<bits/stdc++.h>
#define eps 0.0000001
using namespace std;
int main()
{
    int n;
    cin>>n;
    pair<long long,long long>minm,maxm;
    minm.first=1;
    maxm.first=-1;
    while(n--){
        int pos,speed;
        cin>>pos>>speed;
        if(pos>(maxm.first))
        {
            maxm.first=pos;
            maxm.second=speed;
        }
        if(pos<(minm.first))
        {
            minm.first=pos;
            minm.second=speed;
        }
    }
    if(n==1)
    cout<<0;
    else
    {
        float totdist=maxm.first-minm.first;
        float totspeed=maxm.second+minm.second;
        float time = totdist/totspeed;
        cout<<setprecision(10)<<time;
    }
}
/*
all will get together when the people on the extreme ends come together so to find the exterme persons i took input and found the time took
FLAWS IN THE LOGIC :-
1)I assumed that the total distance travelled by the extreme end persons is the distance between them but it might not be the case
*/