#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define mpk make_pair
#define N 1001
#define PI acos(-1.0)
#define M (ll) 1000000007
#define INF 1e12

using namespace std;

class edge
{
public:
    ll u,v,w;
    edge(ll a,ll b,ll c)
    {
        u=a;
        v=b;
        w=c;
    }
};

ll dis[N],n,m;
ll vis[N],con[N][N],ww[N];
vector<ll>adj[N];
vector<edge>edge_list;

void bellmanford(ll scr)
{
    for(ll i=0;i<=n;i++)
        dis[i]=INF;

    dis[1]=ww[0];

    ll mm=edge_list.size();
    for(ll i=0;i<n-1;i++)
    {
        for(ll j=0;j<mm;j++)
        {
            ll u=edge_list[j].u;
            ll v=edge_list[j].v;
            ll w=edge_list[j].w;

            if(dis[u]!=INF && dis[v]>dis[u]+w)
            {
                if(dis[u]+w<100)
                    dis[v]=dis[u]+w;
            }
        }
    }

    for(ll i=0;i<mm;i++)
    {
        ll u=edge_list[i].u;
        ll v=edge_list[i].v;
        ll w=edge_list[i].w;
        if(dis[u]!=INF && dis[v]>dis[u]+w)
        {
            if(con[v][n] && dis[u]+w<100)
            {
                cout<<"winnable"<<endl;
                return;
            }
        }
    }

    if(dis[n]<100)
        cout<<"winnable"<<endl;
    else
        cout<<"hopeless"<<endl;

    return;

}

void dfs(int u)
{
    vis[u]=1;
    for(ll i=0;i<adj[u].size();i++)
    {
        ll v=adj[u][i];
        if(!vis[v]) dfs(v);
    }

}


void connect()
{
    for(ll i=1;i<=n;i++)
    {
        memset(vis,0,sizeof vis);
        dfs(i);

        for(ll j=1;j<=n;j++)
        {
            if(vis[j]==1)
            {
                con[i][j]=1;
            }
        }
    }
}


int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    while(cin>>n && n!=-1)
    {
        memset(con,0,sizeof con);

        edge_list.clear();
        for(ll i=0;i<=n;i++)
            adj[i].clear();

        for(ll i=1;i<=n;i++)
        {
            ll w;
            cin>>w>>m;
            for(ll j=0;j<m;j++)
            {
                ll t;
                cin>>t;
                adj[i].pb(t);
                edge_list.pb(edge(i,t,-w));
            }
        }

        connect();
        bellmanford(1);
    }

}
