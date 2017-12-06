#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define pb push_back

map<ll,ll>visited;

void bfs(ll start,map<ll,vector<ll> > graph)
{
    queue<ll>q;
    q.push(start);
//    if(visited[start]!=0) cout<<start<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl<<endl<<endl<<endl;
    visited[start]=0;
    while(!q.empty())
    {
        ll top=q.front();
        q.pop();
        for(ll i=0;i<graph[top].size();i++)
        {
            ll temp=graph[top][i];
            if(!visited.count(temp))
            {
                visited[temp]=visited[top]+1;
                q.push(temp);
            }
        }
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ll nods,k=1;

    map<ll,vector<ll> >graph;
    while(cin>>nods && nods!=0)
    {
        for(ll i=0;i<nods;i++)
        {
            ll a,b;
            scanf(" %lld %lld",&a,&b);
            graph[a].pb(b);
            graph[b].pb(a);
        }

        ll ttl,start,cnt=0;
        while((cin>>start>>ttl) && (ttl!=0 || start!=0))
        {
            map<ll,ll>::iterator it;
            visited.clear();
            bfs(start,graph);
            cnt=0;
            for(it=visited.begin();it!=visited.end();it++)
            {
                if(it->second > ttl) cnt++;
            }

            cnt+=graph.size()-visited.size();

            printf("Case %lld: %lld nodes not reachable from node %lld with TTL = %lld.\n",k,cnt,start,ttl);
            k++;
        }

        graph.clear();
    }

    return 0;
}
