#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define mpk make_pair
#define N 1001
#define PI acos(-1.0)
#define M (ll)1e9+7

bool vis[101];
vector<ll>edge[101];
stack<ll>s;

void dfs(ll scr)
{
    vis[scr]=true;
    for(ll i=0;i<edge[scr].size();i++)
    {
        ll curr=edge[scr][i];
        if(!vis[curr])
            dfs(curr);
    }

    s.push(scr);
}

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ll n,m;
    while(cin>>n>>m&&n!=0&&m!=0)
    {
        for(ll i=0;i<101;i++)
        {
            edge[i].clear();
        }
        memset(vis,false,sizeof vis);

        while(!s.empty())
            s.pop();

        while(m--)
        {
            ll u,v;
            cin>>u>>v;
            edge[u].pb(v);
        }

        for(ll i=1;i<=n;i++)
        {
            if(!vis[i])
                dfs(i);
        }

        while(!s.empty())
        {
            cout<<s.top()<<" ";
            s.pop();
        }
        cout<<endl;
    }
    return 0;
}

