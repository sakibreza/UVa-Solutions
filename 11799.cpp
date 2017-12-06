#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int x=1;x<=t;x++)
    {
        int n;
        cin>>n;
        int a[n];
        for(int y=0;y<n;y++) cin>>a[y];

        sort(a,a+n);
        cout<<"Case "<<x<<": "<<a[n-1]<<endl;
    }

    return 0;
}
