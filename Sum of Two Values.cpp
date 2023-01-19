#include<bits/stdc++.h>
using namespace std;

int LinSearch(int A[],int n,int k)
{
    for(int i=0;i<n;i++)
    {
        if(A[i]==k)
            return i+1;
    }
    return 0;
}
int LinSearch2(int A[],int n,int k)
{
    for(int i=n-1;i>=0;i--)
    {
        if(A[i]==k)
            return i+1;
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long n, s;
    cin >> n >> s;

    list<int> A;
    int B[n];
    for(int i=0;i<n;i++)
    {
        cin >> B[i];
        A.push_front(B[i]);
    }
    A.sort();

    while(A.size()>1)
    {
        if(A.front()+A.back()==s)
        {
            cout << LinSearch(B,n,A.front()) << ' ' << LinSearch2(B,n,A.back()) << '\n';
            return 0;
        }
        if(A.front()+A.back()<s)
        {
            A.pop_front();
        }
        else
        {
            A.pop_back();
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}
