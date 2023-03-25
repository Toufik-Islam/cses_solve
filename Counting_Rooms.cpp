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

const int Max = 1005;

int move_x[] = {0, 0, 1, -1};
int move_y[] = {1, -1, 0, 0};

int Adj[Max][Max];
bool visited[Max][Max];
int n, m;
int room = 0;

bool is_safe_unexplored(pair<int, int> x)
{
    if (x.first > 0 && x.second > 0 && x.first <= n && x.second <= m && !visited[x.first][x.second] && Adj[x.first][x.second] != -1)
        return true;
    return false;
}

void BFS(pair<int, int> src)
{
    queue<pair<int, int>> q;
    q.push(src);
    visited[src.first][src.second] = true;

    while (q.size())
    {
        pair<int, int> head = q.front();
        q.pop();
        int x = head.first;
        int y = head.second;

        for (int i = 0; i < 4; i++)
        {
            if (is_safe_unexplored({x + move_x[i], y + move_y[i]}))
            {
                visited[x + move_x[i]][y + move_y[i]] = true;
                q.push({x + move_x[i], y + move_y[i]});
            }
        }
    }
}

void count_room()
{

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            if (s[j] == '#')
                Adj[i][j + 1] = -1;
        }
    }
    /*
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
                cout << Adj[i][j];
            cout << nl;
        }
    */
    pair<int, int> chk = {1, 1};

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (is_safe_unexplored({i, j}))
            {
                room++;
                BFS({i, j});
            }
        }
    }
}

int main()
{
    Faster;

    int t = 1;
    // cin >> t;
    while (t--)
        count_room();

    cout << room;
    return 0;
}