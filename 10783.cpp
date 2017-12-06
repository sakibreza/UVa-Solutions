#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define N 1001
#define PI acos(-1.0)
#define M 1000000007

priority_queue<ll>q;
int main()
{
    ll n;
    cin>>n;
    for(ll k=1;k<=n;k++)
    {
        ll sum=0;
        ll l,r;
        cin>>l>>r;
        for(ll i=l;i<=r;i++)
        {
            if(i%2)sum+=i;
        }
        cout<<"Case "<<k<<": "<<sum<<endl;
    }
    return 0;
}


