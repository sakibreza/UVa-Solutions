#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define N 10005

ll t,num[N],low[N],parent[N];

pair<ll,ll> p;
bool visited[N];
vector<ll>edge[N];
vector<pair<ll,ll> >bridge;

void bridgefind(ll u)
{
    low[u]=num[u]=++t;
    visited[u]=true;
    for(ll i=0;i<edge[u].size();i++)
    {
        ll v=edge[u][i];
        if(!visited[v])
        {
            parent[v]=u;
            bridgefind(v);
            low[u]=min(low[u],low[v]);
            if(low[v]>num[u])
            {
                p.first=u,p.second=v;
                if(u>v) swap(p.first,p.second);
//                cout<<p.first<<" "<<p.second<<endl;
                bridge.pb(mp(p.first,p.second));
                ll temp=p.second;
            }
        }

        else if(parent[u]!=v)
            low[u]=min(low[u],num[v]);
    }
}

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ll n,u,v,num;
    while(cin>>n)
    {
        for(ll i=0;i<n;i++)
        {
            cin>>u;
            scanf(" (%lld)",&num);
            while(num--)
            {
                cin>>v;
                edge[u].pb(v);
            }
        }

        for(ll i=0;i<n;i++)
        {
            if(!visited[i])
            {
                bridgefind(i);
            }
        }


        sort(bridge.begin(),bridge.end());

        printf("%d critical links\n",bridge.size());
        for(ll i=0;i<bridge.size();i++)
        {
            printf("%lld - %lld\n",bridge[i].first,bridge[i].second);
        }

        cout<<endl;
        bridge.clear();
        memset(visited,0,sizeof visited);
        for(ll i=0;i<N;i++)
        {
            edge[i].clear();
        }
    }
    return 0;
}

