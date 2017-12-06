#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define pb push_back

map<ll,vector<ll> >graph;
bool visited[50];
ll level[50];

void bfs(ll scr,ll des)
{
    memset(visited,false,sizeof visited);
    memset(level,0,sizeof level);
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
//    cout<<scr<<" "<<des<<" "<<level[des]<<endl;
    printf("%2lld to %2lld: %lld\n",scr,des,level[des]);
}

int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ll x,y,k=1;
    while(cin>>x)
    {
        for(ll i=1;i<=19;i++)
        {
            if(i!=1) cin>>x;
            for(ll j=0;j<x;j++)
            {
                cin>>y;
                graph[i].pb(y);
                graph[y].pb(i);
            }
        }

        ll scr,des,n;
        cin>>n;
        cout<<"Test Set #"<<k++<<endl;
        for(ll i=0;i<n;i++)
        {
            cin>>scr>>des;
            bfs(scr,des);
        }
        cout<<endl;
        graph.clear();
    }

    return 0;
}
