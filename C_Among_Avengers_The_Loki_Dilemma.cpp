#include <bits/stdc++.h>
using namespace std;
// #define loop for (int i = 0; i <n; i++)
// #define rloop for (int i = n-1; i >= 0; i--)
// #define printspace cout<<  <<" ";
// #define printentre cout<<  <<endl;
//  floor(log10(n) + 1);           // length of any integer
#define debug(x) cerr << #x << " = " << x << endl
#define debug2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl
#define endl ("\n")
#define pi (3.141592653589)
#define ll long long
#define rrep(i, s, e) for (int i = s; i >= e; i--)
#define rep(i, s, e) for (int i = s; i <= e; i++)
#define loop(i, s, e, inc) for (int i = s; i <= e; i = i + inc)
#define rloop(i, s, e, dec) for (int i = s; i >= e; i = i - dec)
#define str(x) \
    string x;  \
    cin >> x;
#define fin(x) \
    double x;  \
    cin >> x;
#define in(x)        \
    long long int x; \
    cin >> x;
#define in2(x, y)       \
    long long int x, y; \
    cin >> x >> y;
#define in3(x, y, z)       \
    long long int x, y, z; \
    cin >> x >> y >> z;
#define out(x) cout << x;
#define out2(x, y) cout << x << " " << y;
#define out3(x, y, z) cout << x << " " << y << " " << z;
#define float double
#define yes cout << "YES";
#define no cout << "NO";
// decimal to binary.
string dectobin(long long num);
// binary to decimal.
long long bintodec(string n);
// gives a power b.
long long binpow(long long a, long long b);
// which number is prime between 1 to n.
vector<bool> sieve(long long int n);
// check whether the no. is prime or not.
bool is_prime(long long int n);
// gives lowest prime factor of numbers between 1 to n.
vector<long long int> lowest_prime(long long int n);
// gives highest prime factor of numbers between 1 to n.
vector<long long int> highest_prime(long long int n);
// gives divisors of a particular number.
vector<long long int> divisors(long long int n);
// gives the prime factors of a particular number.
vector<long long int> primefactor(long long int n);
void fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
//-------------------------------------------------------------------------
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> pos, neg;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        a[i] = num;
        if (num > 0)
        {
            pos.push_back(num);
        }
        else
            neg.push_back(-num);
    }
    if (m == 0)
    {
        for (int i = 0; i < n; i++)
        {
            cout << "Enchanted\n";
        }
        return;
    }
    if (m == n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << "Truthful\n";
        }
        return;
    }
    if (pos.size() == 0)
    {
        if (n == 1)
        {
            cout << "Enchanted";
            return;
        }
        for (int i = 0; i < n; i++)
        {
            cout << "Agamotto failed\n";
        }
        return;
    }
    if (neg.size() == 0)
    {
        if (n == 1)
        {
            cout << "Truthful";
            return;
        }
        for (int i = 0; i < n; i++)
        {
            cout << "Agamotto failed\n";
        }
        return;
    }

    int pPeople = pos.size();
    int nPeople = neg.size();
    // if (pPeople == 1)
    // {
    //     if (m == nPeople + 1)
    //     {
    //         for (int i = 0; i < n; i++)
    //         {
    //             cout << "Truthful\n";
    //         }
    //         return;
    //     }
    // }
    // if (nPeople == 1)
    // {
    //     if (m == 0)
    //     {
    //         for (int i = 0; i < n; i++)
    //         {
    //             cout << "Enchanted\n";
    //         }
    //         return;
    //     }
    // }
    if (m == nPeople + 1)
    {
        for (int i = 0; i < n; i++)
        {
            if (a[i] > 0)
            {
                cout << "Agamotto failed\n";
            }
            else
                cout << "Truthful\n";
        }
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (a[i] < 0)
        {
            cout << "Agamotto failed\n";
        }
        else
            cout << "Enchanted\n";
    }
}
int main()
{
    fast();
    // int t;
    // cin >> t;
    // while (t--)
    //{
    //    solve();
    //}
    solve();
    return 0;
}
//-------------------------------------------------------------------------
vector<bool> sieve(long long int n)
{
    vector<bool> is_prime(n, 1);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i < n; i++)
    {
        if (is_prime[i] == true)
        {
            for (int j = 2 * i; j < n; j = j + i)
            {
                is_prime[j] = false;
            }
        }
    }
    return is_prime;
}

long long binpow(long long a, long long b)
{
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
long long bintodec(string n)
{
    string num = n;
    ll dec_value = 0, base = 1, len = num.length();
    for (ll i = len - 1; i >= 0; i--)
    {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    }
    return dec_value;
}
string dectobin(long long num)
{
    string str1;
    while (num)
    {
        if (num & 1) // 1
            str1 += '1';
        else // 0
            str1 += '0';
        num >>= 1; // Right Shift by 1
    }
    reverse(str1.begin(), str1.end());
    return str1;
}   