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

const int N = 1005;
int move_x[] = {0, 0, 1, -1};
int move_y[] = {1, -1, 0, 0};
string direction = "RLDU";

int n, m;
int Adj[N][N];
pair<int, int> src;
pair<int, int> des;
bool visited[N][N];
pair<int, int> parent[N][N];
int distnce;

bool is_safe(pair<int, int> A)
{
    if (A.first > 0 && A.second > 0 && A.first <= n && A.second <= m && Adj[A.first][A.second] == 0)
        return true;
    return false;
}

void BFS(pair<int, int> source)
{
    queue<pair<int, int>> qq;
    qq.push(source);
    visited[source.first][source.second] = true;
    parent[source.first][source.second] = {-1, -1};
    while (qq.size())
    {
        pair<int, int> head = qq.front();
        qq.pop();
        int x = head.first;
        int y = head.second;

        for (int i = 0; i < 4; i++)
        {
            int p = x + move_x[i];
            int q = y + move_y[i];
            if (is_safe({p, q}) && !(visited[p][q]))
            {
                pair<int, int> push = {p, q};
                qq.push(push);
                visited[p][q] = true;
                parent[p][q] = {x, y};
            }
        }
    }
}

void path(pair<int, int> x)
{
    if (x == pair<int, int>(-1, -1))
    {
        cout << distnce - 1 << nl;
        return;
    }
    distnce++;
    int par_x = parent[x.first][x.second].first;
    int par_y = parent[x.first][x.second].second;
    path(parent[x.first][x.second]);
    for (int i = 0; i < 4; i++)
    {
        if (par_x + move_x[i] == x.first && par_y + move_y[i] == x.second)
        {
            cout << direction[i];
            return;
        }
    }
}

void maze()
{

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            if (s[j] == '#')
            {
                Adj[i][j + 1] = -1;
            }
            else if (s[j] == 'A')
                src = {i, j + 1};
            else if (s[j] == 'B')
                des = {i, j + 1};
        }
    }
    BFS(src);

    if (!visited[des.first][des.second])
    {
        no;
        return;
    }

    yes;
    path(des);
}

int main()
{
    Faster;

    int t = 1;
    // cin >> t;
    while (t--)
        maze();

    return 0;
}
