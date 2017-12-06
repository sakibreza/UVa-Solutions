#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define N 1001
#define PI acos(-1.0)
#define M (ll)1e9+7
#define INF 1e18

class edge
{
public:
    ll u,v,w;
    edge(ll x,ll y,ll z)
    {
        u=x,v=y,w=z;
    }
    bool operator<(const edge& e) const
    {
        return w<e.w;
    }
};

ll n,m,ac;
ll pr[10005], rk[10005];
vector<edge>vc;

ll find_(ll r)
{
    if(pr[r]==r) return r;
    else return find_(pr[r]);
}

void Union(ll a,ll b)
{
    if(rk[a]<rk[b])
        pr[a]=find_(b);
    else
    {
        pr[b]=find_(a);
        if(rk[a]==rk[b])
        rk[a]++;
    }
}

ll MST()
{
    memset(pr,0,sizeof pr);
    sort(vc.begin(),vc.end());
    for(ll i=1;i<=n;i++)
        pr[i]=i,rk[i]=0;
    ll cnt=0,mcost=0;
    for(ll i=0;i<vc.size();i++)
    {
        if(vc[i].w>=ac) continue;

        ll u=find_(vc[i].u);
        ll v=find_(vc[i].v);

        if(u!=v)
        {
            Union(u,v);
            cnt++;
            mcost+=vc[i].w;
            if(cnt==n-1)
                break;
        }
    }

    ll no_of_air=0;

    for(ll i=1;i<=n;i++)
    {
        if(pr[i]==i)
        {
            mcost+=ac;
            no_of_air++;
        }
    }

    cout<<mcost<<" "<<no_of_air<<endl;
}

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ll t;
    cin>>t;
    for(ll ks=1;ks<=t;ks++)
    {
        vc.clear();
        cin>>n>>m>>ac;
        for(ll i=0;i<m;i++)
        {
            ll u,v,w;
            cin>>u>>v>>w;
            vc.pb(edge(u,v,w));
        }

        cout<<"Case #"<<ks<<": ";
        MST();
    }
    return 0;
}


