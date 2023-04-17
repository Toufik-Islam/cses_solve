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

const int N = 10e5 + 3;
int n, m;
vector<int> Adj[N];
bool visited[N];
vector<int> roads;

void DFS(int node)
{
    visited[node] = true;

    for (auto child : Adj[node])
    {
        if (!visited[child])
        {
            DFS(child);
        }
    }
}

void solve()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        Adj[a].push_back(b);
        Adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            roads.push_back(i);
            DFS(i);
        }
    }

    cout << roads.size() - 1 << nl;
    for (int i = 1; i < roads.size(); i++)
        cout << roads[i - 1] << ' ' << roads[i] << nl;
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
