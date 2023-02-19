#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,mid;
    cin>>n;

    int A[n];
    long long ans=0;
    for(int i=0; i<n; i++)
        cin>> A[i];

    sort(A,A+n);

    mid = A[n/2];

    for(int i=0; i<n; i++)
        ans+=abs(mid-A[i]);

    cout << ans;
    return 0;
}
