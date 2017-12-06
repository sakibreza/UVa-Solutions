#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define mpk make_pair
#define N 1001
#define PI acos(-1.0)
#define Mn 1000000007

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll res=0;
        while(n--)
        {
            ll a,b,c;
            cin>>a>>b>>c;
            res+=a*c;
        }
        cout<<res<<endl;
    }
    return 0;
}
