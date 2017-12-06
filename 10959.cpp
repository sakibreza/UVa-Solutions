#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define pb push_back

map<ll,vector<ll> >graph;
map<ll,bool>visited;
map<ll,ll>level;

void bfs(ll scr,ll des)
{
    visited.clear();
    level.clear();
    queue<ll>q;
    q.push(scr);
    visited[scr]=true;
    while(!q.empty())
    {
        ll top=q.front();
        q.pop();
        for(ll i=0;i<graph[top].size();i++)
        {
            ll temp=graph[top][i];
            if(!visited[temp])
            {
                visited[temp]=1;
                level[temp]=level[top]+1;
                q.push(temp);
            }
        }
    }
    cout<<level[des]<<endl;
}

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    ll n,m,t;
    cin>>t;
    while(t--)
    {
        graph.clear();
        cin>>n>>m;
        while(m--)
        {
            ll a,b;
            cin>>a>>b;
            graph[a].pb(b);
            graph[b].pb(a);
        }

        for(ll i=1;i<n;i++)
        {
            bfs(0,i);
        }
        if(t) cout<<endl;
    }

    return 0;
}
