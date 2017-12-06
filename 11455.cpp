#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define N 1001
#define PI acos(-1.0)
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll a[4];
        for(ll i=0;i<4;i++)
        {
            cin>>a[i];
        }
        sort(a,a+4);

        if(a[0]+a[1]+a[2]>a[3])
        {
            if(a[0]==a[1]&&a[1]==a[2]&&a[2]==a[3]) cout<<"square"<<endl;
            else if(a[0]==a[1]&&a[2]==a[3]) cout<<"rectangle"<<endl;
            else cout<<"quadrangle"<<endl;
        }
        else cout<<"banana"<<endl;
    }
    return 0;
}



