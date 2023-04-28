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

const int N = 10e5 + 2;
int n, m;
vector<int> Adj[N];
int visited[N];
stack<int> serial;
bool DFS(int node)
{
    visited[node] = 1;

    for (auto child : Adj[node])
    {
        if (visited[child] == 0)
        {
            bool cycle = DFS(child);
            if (cycle)
                return true;
        }
        else if (visited[child] == 1)
            return true;
    }
    visited[node] = 2;
    serial.push(node);
    return false;
}

void solve()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        Adj[a].push_back(b);
    }
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0)
        {
            bool cycle = DFS(i);
            if (cycle)
            {
                cout << "IMPOSSIBLE\n";
                return;
            }
        }
    }

    while (serial.size())
    {
        cout << serial.top() << ' ';
        serial.pop();
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
