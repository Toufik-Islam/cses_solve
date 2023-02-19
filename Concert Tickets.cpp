#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin.tie(0);

    int m,n;
    cin>>n>>m;

    multiset<int> A;

    for(int i=0; i<n; i++)
    {
        int q;
        cin >> q;
        A.insert(q);
    }

    while(m--)
    {
        int x;
        cin >> x;
        auto it = A.upper_bound(x);
        if(A.empty())
            cout << "-1\n";
        else if(it==A.begin())
            cout << "-1\n";
        else
        {
            --it;
            cout << *it << '\n';
            A.erase(it);
        }
    }
    return 0;
}
