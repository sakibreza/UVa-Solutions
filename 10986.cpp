#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define N 1001
#define PI acos(-1.0)
#define Mn 1000000007

ll level[20004];
vector<pair<ll,ll> >graph[20004];

void dijkstra(ll source)
{
    level[source]=0;
    priority_queue<pair<ll,ll> >q;
    q.push(mp(source,0));
    while(!q.empty())
    {
        pair<ll,ll> temp=q.top();
        q.pop();
        ll u,uc,v,vc;

        u=temp.first;
        uc=-temp.second;

        if(uc>level[u]) continue;

        for(ll i=0;i<graph[u].size();i++)
        {
            v=graph[u][i].first;
            vc=graph[u][i].second;
//            cout<<v<<" "<<vc<<endl;

//            cout<<level[v]<<" "<<level[u]+vc<<endl;

            if(level[v]>level[u]+vc)
            {
                level[v]=level[u]+vc;
                q.push(mp(v,-level[v]));
            }
        }
    }
}

int main()
{
    ll T,n,m,s,t;
    cin>>T;
    for(ll ks=1;ks<=T;ks++)
    {
        for(ll i=0;i<20004;i++) level[i]=1000000000;
        for(ll i=0;i<20004;i++) graph[i].clear();

        cin>>n>>m>>s>>t;

        while(m--)
        {
            ll a,b,c;
            cin>>a>>b>>c;
            graph[a].pb(mp(b,c));
            graph[b].pb(mp(a,c));
        }

        dijkstra(s);

//        cout<<level[t]<<endl;

        if(level[t]!=1000000000)
            printf("Case #%lld: %d\n",ks,level[t]);
        else
            printf("Case #%d: unreachable\n",ks);

    }

    return 0;

}
