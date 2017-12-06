#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define mpk make_pair
#define N 1001
#define PI acos(-1.0)
#define M (ll) 1000000007

using namespace std;


ll edge[50004],len[50004];
bool vis[50004];

ll dfs(ll n)
{
    vis[n]=true;
    ll res=0;
//    cout<<n<<" "<<edge[n]<<" "<<(!vis[edge[n]])<<endl;
    if(edge[n]&&!vis[edge[n]])
    {
        res+=dfs(edge[n])+1;
//        cout<<res<<"<<"<<endl;
    }
    vis[n]=false;
    len[n]=res;
//    cout<<">> "<<res<<endl;
    return res;
}

int main()
{
    ll t;
    cin>>t;
    for(ll ks=1;ks<=t;ks++)
    {
        memset(edge,0,sizeof edge);
        memset(len,0,sizeof len);
        memset(vis,false,sizeof vis);
        ll n,res,lon_len=0;
        cin>>n;
        for(ll i=0;i<n;i++)
        {
            ll u,v;
            cin>>u>>v;
            edge[u]=v;
        }

        for(ll i=1;i<=n;i++)
        {
            if(!len[i]) dfs(i);
//            cout<<len[i]<<" ---<<"<<lon_len<<endl;

            if(len[i]>lon_len)
            {
                res=i;
                lon_len=len[i];
            }
        }
        cout<<"Case "<<ks<<": "<<res<<endl;
    }
}
