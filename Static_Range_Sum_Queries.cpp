/*
\~~~~~~~~~~~~~~~~~\
 \    TOUFIK       \
  \        ISLAM    \
   \~~~~~~~~~~~~~~~~~\
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define nl '\n'
#define md 1000000007
#define Faster                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);

void solve()
{
    ll n, q;
    cin >> n >> q;
    vector<ll> A(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> A[i];

    for (int i = 1; i <= n; i++)
        A[i] += A[i - 1];

    while (q--)
    {
        ll l, r;
        cin >> l >> r;
        cout << A[r] - A[l - 1] << nl;
    }
}

int main()
{
    Faster;

    int t = 1;
    // cin >> t;
    while (t--)
        solve();

    return 0;
}
