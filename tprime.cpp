#include<bits/stdc++.h>
using namespace std;
const unsigned long long N = 1e6;
bool prime[N]; 
void isprime()
{
    memset(prime, true, sizeof(prime));
    for (int p = 2; p * p <= N; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= N; i += p)
                prime[i] = false;
        }
    }
}
int main()
{
    isprime();
    int n;
    cin>>n;
    while(n--)
    {
        long long x,sq;
        cin>>x;
        sq=sqrt(x);
        if(sq==1)
        {
            cout<<"NO\n";
            continue;
        }
        if((sq*sq)==x && sq)
        {
            if(prime[sq])
            cout<<"YES\n";
            else
            cout<<"NO\n";
        }
        else
        cout<<"NO\n";
    }
}
