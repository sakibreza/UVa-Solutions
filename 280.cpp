#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define pb push_back

map<ll,vector<ll> >graph;
map<ll,bool>visited;
map<ll,ll>level;

void bfs(ll scr)
{
    visited.clear();
    level.clear();
    queue<ll>q;
    q.push(scr);
//    visited[scr]=true;
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
                level[temp]=1;
                q.push(temp);
            }
        }
    }
}

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    ll n;
    while(cin>>n&&n!=0)
    {
        graph.clear();
        ll u,v;
        while(cin>>u&&u!=0)
        {
            while(cin>>v&&v!=0)
            {
                graph[u].pb(v);
            }
        }

        ll k;
        cin>>k;
        while(k--)
        {
            ll a;
            cin>>a;
            bfs(a);
            vector<ll>v;
            for(ll i=1;i<=n;i++)
            {
                if(!level[i])v.pb(i);
            }

            cout<<v.size();
            if(v.size()!=0)cout<<" ";
            for(ll i=0;i<v.size();i++)
            {
                cout<<v[i];
                if(i!=v.size()-1) cout<<" ";
            }
            cout<<endl;
        }
    }

    return 0;
}
