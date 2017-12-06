#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int x=1;x<=t;x++)
    {
        int a[3];

        for(int y=0;y<3;y++) cin>>a[y];

        sort(a,a+3);

        cout<<"Case "<<x<<": "<<a[1]<<endl;
    }

    return 0;
}
