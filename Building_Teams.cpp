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

const int Maxx = 10e5 + 5;
vector<int> Adj[Maxx];
int n, m;
int color[Maxx];

bool DFS(int src)
{

    int col;
    if (color[src] == 1)
        col = 2;
    else
        col = 1;

    for (auto node : Adj[src])
    {
        if (color[node] == 0)
        {
            color[node] = col;
            bool ok = DFS(node);
            if (!ok)
                return false;
        }
        else
        {
            if (color[src] == color[node])
                return false;
        }
    }

    return true;
}

void build_team()
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
        if (color[i] == 0)
        {
            color[i] = 1;

            bool ok = DFS(i);
            if (!ok)
            {
                cout << "IMPOSSIBLE";
                return;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << color[i] << ' ';
    }
}

int main()
{
    Faster;

    int t = 1;
    // cin >> t;
    while (t--)
        build_team();

        return 0;
}
