#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define mpk make_pair
#define N 1001
#define PI acos(-1.0)
#define Mx 1000000000

vector<ll>edge[302];
ll color[302];

int main()
{
//        freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ll V;
    while(cin>>V&&V!=0)
    {
    for(ll i=0;i<=V;i++)edge[i].clear();

    ll u,v;
    while(cin>>u>>v && u!=0&&v!=0)
    {
        edge[u-1].pb(v-1);
        edge[v-1].pb(u-1);
    }

    queue<ll>q;
    q.push(0);
    for(ll i=0;i<=V;i++) color[i]=Mx;
    color[0]=0;
    bool flag=1;
    while(!q.empty()&&flag)
    {
        ll u=q.front();
        q.pop();
        for(ll i=0;i<edge[u].size();i++)
        {
            ll v=edge[u][i];
            if(color[v]==Mx)
            {
                color[v]=1-color[u];
                q.push(v);
            }
            else if(color[v]==color[u])
            {
                flag=0;
                break;
            }
        }
    }

    if(flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    }
    return 0;
}
