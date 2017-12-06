#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define N 1001
#define PI acos(-1.0)
#define M (ll)1e9+7
#define INF 1e18

ll pr[100005],rk[100005],res[100005],mx;

ll find_(ll r)
{
    if(pr[r]==r) return r;
    else return find_(pr[r]);
}

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ll t;
    cin>>t;
    while(t--)
    {
        memset(pr,0,sizeof pr);
        memset(rk,0,sizeof rk);
        memset(res,0,sizeof res);

        mx=0;
        for(ll i=0;i<=100005;i++)
        {
            pr[i]=i;
            rk[i]=0;
            res[i]=1;
        }

        map<string,ll>m;
        ll q;
        cin>>q;
        ll k=0;
        string a,b;
        while(q--)
        {
            cin>>a>>b;
            ll u,v;
            if(!m[a])
            {
                m[a]=++k;
            }
            if(!m[b])
            {
                m[b]=++k;
            }
            u=m[a];
            v=m[b];
            u=find_(u);
            v=find_(v);
            if(u!=v)
            {
                pr[v]=u;
                res[u]+=res[v];
            }
            cout<<res[u]<<endl;
        }

    }
    return 0;
}

