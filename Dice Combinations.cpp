#include<bits/stdc++.h>
using namespace std;

vector<long long> way;

#define mod 1000000007

long long dp(long long n)
{
    if(n==0)
        return 1;
    if(n<=way.size())
        return way[n-1];

    long long x = 0;
    for(int i=1;i<=6;i++)
    {
        if(n-i>=0)
            x += (dp(n-i));
    }

    way.push_back(x%mod);
    return x;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for(int i=0;i<6;i++)
    {
        way.push_back(pow(2,i));
    }

    long long ans = dp(n);

    cout << way[n-1];
    return 0;
}
