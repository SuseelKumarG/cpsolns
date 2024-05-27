#include<bits/stdc++.h>
using namespace std;
const int N=10000007;
vector<bool>prime(N,1);
vector<int>hp(N),lp(N);
void prime_factorization(vector<int> &prime_factors,int num)
{
    while(num>1)
    {
        int highest_prime_factor=hp[num];
        while(!(num%highest_prime_factor))
        {
            num/=highest_prime_factor;
            prime_factors.push_back(highest_prime_factor);
        }
    }
}
int main()
{
    for(int i=2;i<N;i++)
    {
        if(prime[i])
        {
            lp[i]=hp[i]=i;
            for(int j=2*i;j<=N;j+=i)
            {
                prime[j]=0;
                hp[j]=i;
                if(!lp[j])
                lp[j]=i;
            }
        }
    }
    vector<int>prime_factors;
    prime_factorization(prime_factors,12);
    for(auto it:prime_factors)
    cout<<it<<' ';
}