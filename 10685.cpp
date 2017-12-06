#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define N 1001
#define PI acos(-1.0)
#define M (ll)1e9+7
#define INF 1e18

ll pr[5003],rk[5003],res[5003],mx;

ll find_(ll r)
{
    if(pr[r]==r) return r;
    else return find_(pr[r]);
}

int main()
{
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ll n,q;
    while(cin>>n>>q&&!(n==0&&q==0))
    {
        memset(pr,0,sizeof pr);
        memset(rk,0,sizeof rk);
        memset(res,0,sizeof res);

        mx=0;
        for(ll i=0;i<=n;i++)
        {
            pr[i]=i;
            rk[i]=0;
            res[i]=1;
        }

        map<string,ll>m;
        ll cnt=0;
        for(ll i=0;i<n;i++)
        {
            string s;
            cin>>s;
            m[s]=++cnt;
        }

        while(q--)
        {
            string a,b;
            cin>>a>>b;
            ll u,v;
            u=m[a];
            v=m[b];
            u=find_(u);
            v=find_(v);
            if(u!=v)
            {
                pr[v]=u;
                res[u]+=res[v];
            }
        }

        for(ll i=1;i<=n;i++)
        {
//            cout<<pr[i]<<endl;
            mx=max(mx,res[i]);
        }

        cout<<mx<<endl;

    }
    return 0;
}

