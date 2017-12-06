#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define mpk make_pair
#define N 1001
#define PI acos(-1.0)
#define M (ll) 1000000007

using namespace std;

class block
{
public:
    ll x,y,z;

    bool operator < (block a) const
    {
        return (bool)((x<a.x&&y<a.y)||(x<a.y&&y<a.x));
    }
};

vector<block>v;
ll dp[91];
vector<ll>adj[91];


ll rec(ll n)
{
    if(dp[n]!=-1) return dp[n];

    ll temp=0;
    for(ll i=0;i<adj[n].size();i++)
    {
        temp=max(temp,rec(adj[n][i]));
    }
    dp[n]=temp+v[n].z;

    return dp[n];
}

int main()
{
    ll n,ks=0;
    while(cin>>n&&n!=0)
    {
        ks++;
        v.clear();
        for(ll i=0;i<91;i++) adj[i].clear();
        memset(dp,-1,sizeof dp);
        for(ll i=0;i<n;i++)
        {
            ll a,b,c;
            cin>>a>>b>>c;
            v.pb({a,b,c});
            v.pb({b,c,a});
            v.pb({c,a,b});
        }

        for(ll i=0;i<v.size();i++)
        {
            for(ll j=0;j<v.size();j++)
            {
                if(v[i]<v[j])
                {
                    adj[j].pb(i);
                }
            }
        }

        ll res=0;
        for(ll i=0;i<v.size();i++)
        {
            res=max(res,rec(i));
        }

        printf("Case %lld: maximum height = %lld\n",ks,res);
    }
    return 0;
}


