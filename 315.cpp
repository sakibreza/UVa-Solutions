#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair

vector<ll>edge[110];
bool visited[110];
ll n;

void dfs(ll a)
{
    visited[a]=true;
    for(ll i=0;i<edge[a].size();i++)
    {
        if(!visited[edge[a][i]])
            dfs(edge[a][i]);
    }
}

bool articulation_point()
{
    for(ll i=1;i<=n;i++)
    {
        if(!visited[i]) return true;
    }

    return false;
}

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    string s;
    ll b,d;
    while(cin>>n && n!=0)
    {
        if(n==1)
        {
            cin>>b;
            cout<<0<<endl;
            continue;
        }
        getchar();

        while(getline(cin,s))
        {
            istringstream ss(s);
            ss>>b;
            if(b==0) break;

            while(ss>>d)
            {
                edge[b].pb(d);
                edge[d].pb(b);
            }
        }

        ll ans=0;

        for(ll i=1;i<=n;i++)
        {
            memset(visited,0,sizeof visited);
            visited[i]=true;
            if(i!=1)dfs(1);
            else dfs(2);
            ans+=articulation_point();
        }

        cout<<ans<<endl;

        for(ll i=1;i<=n;i++)
        {
            edge[i].clear();
        }
    }
    return 0;
}
