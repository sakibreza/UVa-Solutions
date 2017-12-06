#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define mpk make_pair
#define N 1001
#define PI acos(-1.0)
#define M (ll)1e9+7

using namespace std;

ll der(ll n)
{
    if(n==0) return 1;
    if(n==1) return 0;
    else if(n==2) return 1;
    else return (n-1)*(der(n-1)+der(n-2));
}

ll fact(ll n)
{
    ll sum=1;
    for(ll i=1;i<=n;i++)
        sum*=i;

    return sum;
}

ll ncr(ll n,ll r)
{
    return fact(n)/(fact(r)*fact(n-r));
}

int main()
{
    ll n,m;
    while(cin>>n>>m)
    {
        ll sum=0;
        sum+=der(n);
        for(ll i=1;i<=m;i++)
        {
            sum+=ncr(n,i)*der(n-i);
        }
        cout<<sum<<endl;
    }
}

