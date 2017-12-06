#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define inf 1000000000000000000
#define mp make_pair
#define mx 1003


ll ax[4]={-1,0,1,0};
ll ay[4]={0,-1,0,1};
ll n,m;
ll dis[mx][mx];
ll w[mx][mx];

void dijkstra(ll x,ll y)
{
    dis[x][y]=w[x][y];
    priority_queue<pair<ll,pair<ll,ll>> >q;
    q.push(mp(-w[x][y],mp(x,y)));
    while(!q.empty())
    {
        pair<ll,pair<ll,ll>> temp=q.top();
        q.pop();

        ll ux=temp.second.first;
        ll uy=temp.second.second;
        ll uc=-temp.first;


        for(ll i=0;i<4;i++)
        {
            ll vx=ux+ax[i];
            ll vy=uy+ay[i];
            if(vx>=0&&vx<n&&vy>=0&&vy<m)
            {
                if(uc+w[vx][vy]<dis[vx][vy])
                {
                    dis[vx][vy]=uc+w[vx][vy];
                    q.push(mp(-dis[vx][vy],mp(vx,vy)));
                }
            }
        }
    }
}

int main()
{
    ll t;
    cin>>t;
    for(ll ks=1;ks<=t;ks++)
    {
//        memset(dis,32,sizeof dis);
//        memset(w,0,sizeof w);
        for(ll i=0;i<mx;i++)
        {
            for(ll j=0;j<mx;j++)
            {
                dis[i][j]=inf;
                w[i][j]=0;
            }
        }

        cin>>n>>m;
        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<m;j++)
            {
                scanf(" %lld",&w[i][j]);
            }
        }

        dijkstra(0,0);
        cout<<dis[n-1][m-1]<<endl;
    }
}
