#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    map<int,int> A;
    while(n--)
    {
        int a,b;
        cin >> a >> b;
        A[a]++;
        A[b];
        A[b+1]--;
    }
    int maxx=0,tmp=0;
    for(auto it: A)
    {
        it.second+=tmp;
        tmp = it.second;
        if(it.second>maxx)
            maxx = it.second;
    }
    cout << maxx;
    return 0;
}
