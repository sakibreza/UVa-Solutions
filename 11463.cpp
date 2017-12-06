#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define mpk make_pair
#define N 1001
#define PI acos(-1.0)
#define Mn 1000000007
#define INF 10000000000000

ll dis[102][102];
ll n,m;

void floydwarshall()
{
    for(ll k=0;k<n;k++)
        for(ll i=0;i<n;i++)
            for(ll j=0;j<n;j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
}

int main()
{

    ll t;
    cin>>t;
    for(ll ks=1;ks<=t;ks++)
    {
        cin>>n>>m;

        for(ll i=0;i<n;i++)
            for(ll j=0;j<n;j++)
            {
                if(i==j) dis[i][j]=0;
                else dis[i][j]=INF;
            }

        for(ll i=0;i<m;i++)
        {
            ll u,v;
            cin>>u>>v;
            dis[u][v]=dis[v][u]=1;
        }

        floydwarshall();

        ll s,d;
        cin>>s>>d;

        ll res=0;
        for(ll i=0;i<n;i++)
        {
            if(dis[s][i]!=INF&&dis[i][d]!=INF)
                res=max(res,dis[s][i]+dis[i][d]);
        }

        cout<<"Case "<<ks<<": "<<res<<endl;
    }
    return 0;
}

