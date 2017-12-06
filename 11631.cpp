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

ll n,m;
ll pr[200005], rk[200005];
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

    return mcost;
}

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    while(cin>>m>>n&&!(n==0&&m==0))
    {
        vc.clear();
        ll total_dis=0;
        for(ll i=0;i<n;i++)
        {
            ll x,y,z;
            cin>>x>>y>>z;
            vc.pb(edge(x,y,z));
            total_dis+=z;
        }
        cout<<total_dis-MST()<<endl;
    }
    return 0;
}

/**
9 14
0 1 4
0 7 8
1 2 8
1 7 11
2 3 7
2 8 2
2 5 4
3 4 9
3 5 14
4 5 10
5 6 2
6 7 1
6 8 6
7 8 7
**/
